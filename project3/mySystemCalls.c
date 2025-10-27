#include "proj3KernelTemplate.h"

/**
 *  Globally available mutexes (or binary semaphores) for your application to use.
 *  if you're reading this ... what is the best energy drink/type of coffee/drink of choice? -AJ
 *  Respectively, the each lock serves the following purpose.
 *
 *  application_init_lock:  locks concurrent attempts to initialize (or re-initialize) the application context.
 *                          it is important to note that this mutex may be used for more than the init system call!
 *                          think about what critical data this lock can access ...
 *
 *  application_free_lock:  locks concurrent attempts to free the application context. 
 *                          similar to the init lock, this mutex should be used for more than the free system call.
 *
 *  hopefully that gives some insight into what you should be checking.
 *  happy coding!
 *  -AJ
 *   */
static DEFINE_MUTEX(application_init_lock);
static DEFINE_MUTEX(application_free_lock);

const long ERR_NULL_NODE = 99;

void freeQueue(priority_queue_421_t* queue);
long enqueueNode(priority_queue_421_t* queue, queue_node_421_t* node);
long dequeueNode(priority_queue_421_t* queue, queue_node_421_t* result);
priority_queue_421_t* createQueue(char* priorityName);

proj_app_ctx_t* application = NULL;

SYSCALL_DEFINE0(init_kern_application) {
  // Return error if application context already created
  if (application != NULL){
    // Print error message and return error
    printk("init_kern_application: ERROR: application context already created");
    return EPERM;
  }

  // Lock application context (from initing and freeing)
  mutex_lock(&application_init_lock);
  mutex_lock(&application_free_lock);

  // Allocate application context
  if ((application = kmalloc(sizeof(proj_app_ctx_t), GFP_KERNEL)) == NULL){
    // Print error message and return error
    printk("init_kern_application: ERROR: failed to allocate kernel memory for application context");
    return ENOMEM;
  }

  // Create queues
  if ((application->highQueue = createQueue("high")) == NULL){
    return EIO;
  }
  if ((application->mediumQueue = createQueue("medium")) == NULL){
    return EIO;
  }
  if ((application->lowQueue = createQueue("low")) == NULL){
    return EIO;
  }

  // Unlock application context (from initing and freeing)
  mutex_unlock(&application_init_lock);
  mutex_unlock(&application_free_lock);

  // Return success
  return 0;
}

SYSCALL_DEFINE0(free_kern_application) {
printk("free_kern_application: HERE0");
printk("free_kern_application: application_init_lock=%d, application_free_lock=%d", mutex_is_locked(&application_init_lock), mutex_is_locked(&application_free_lock));
  // If application context is NULL
  if (application == NULL){
    // Print error message and return error
    printk("free_kern_application: ERROR: application context already freed");
    return EPERM;
  }
printk("free_kern_application: HERE1");

  // Lock application context (from initing and freeing)
  mutex_lock(&application_init_lock);
printk("free_kern_application: HERE2");
  mutex_lock(&application_free_lock);
printk("free_kern_application: HERE3");

  // Deallocate queues
  freeQueue(application->highQueue);
printk("free_kern_application: HERE4");
  freeQueue(application->mediumQueue);
printk("free_kern_application: HERE5");
  freeQueue(application->lowQueue);
printk("free_kern_application: HERE6");

  // Deallocate application context
  application->highQueue = NULL;
  application->mediumQueue = NULL;
  application->lowQueue = NULL;
  kfree(application);
printk("free_kern_application: HERE7");

  application = NULL;

  // Unlock application context (from initing and freeing)
  mutex_unlock(&application_init_lock);
printk("free_kern_application: HERE8");
  mutex_unlock(&application_free_lock);
printk("free_kern_application: HERE9");

  // Return success
  return 0;
}

SYSCALL_DEFINE1(kern_add_priority, void __user*, node) {
  // If application context NULL
  if (application == NULL){
    // Print error message and return error
    printk("kern_add_priority: ERROR: application context null");
    return EPERM;
  }

  // Add node to priority queue if necessary
  if (node != NULL){
    long result;
    switch (((queue_node_421_t*)node)->priority){
      case HIGH:
        result = enqueueNode(application->highQueue, node);
        break;
      case MEDIUM:
        result = enqueueNode(application->mediumQueue, node);
        break;
      case LOW:
        result = enqueueNode(application->lowQueue, node);
        break;
    }
    // Return error if necessary
    if (result != 0){
      return result;
    }
  }
  else {
    // Print error message and return error
    printk("kern_add_priority: ERROR: node given for add is null");
    return ERR_NULL_NODE;
  }

  // Return success
  return 0;
}

SYSCALL_DEFINE1(kern_get_priority, void __user*, dest) {
  long result = ENOENT;

  // If application context NULL
  if (application == NULL){
    // Print error message and return error
    printk("kern_get_priority: ERROR: application context null");
    return EPERM;
  }

  // If nodes exist in high priority queue
  if (application->highQueue != NULL){
    // Retrieve first enqueued node from high priority queue
    result = dequeueNode(application->highQueue, dest);
  }
  // If nodes exist in medium priority queue
  if (result == ENOENT && application->mediumQueue != NULL){
    // Retrieve first enqueued node from medium priority queue
    result = dequeueNode(application->mediumQueue, dest);
  }
  // If nodes exist in low priority queue
  if (result == ENOENT && application->lowQueue != NULL){
    // Retrieve first enqueued node from low priority queue
    result = dequeueNode(application->lowQueue, dest);
  }
  if (result == ENOENT) {
    // Print error message and return error
    printk("kern_get_priority: ERROR: no nodes available");
  }

  // Return success or error
  return result;
}

/**
 * Creates and initializes a priority queue.
 * @returns priority queue or NULL if allocation fails.
 */
priority_queue_421_t* createQueue(char* priorityName){
  priority_queue_421_t* result = NULL;

  // Allocate queue
  if ((result = kmalloc(sizeof(priority_queue_421_t), GFP_KERNEL)) == NULL){
    // Print error message and return error
    printk("createQueue: ERROR: failed to allocate kernel memory for %s priority queue", priorityName);
    return NULL;
  }

  // Initialize queue properties
  result->head = NULL;
  result->tail = NULL;
  result->num_nodes = 0;

  // Allocate and initialize queue mutex
  result->lock = kmalloc(sizeof(struct mutex), GFP_KERNEL);
  mutex_init(result->lock);

  // Return result;
  return result;
}

/**
 * Removes and returns first available node from priority queue.
 * @param queue     priority queue.
 * @param result    return location for node in user space.
 * @returns 0 if successful, error code otherwise.
 */
long dequeueNode(priority_queue_421_t* queue, queue_node_421_t* result){
  queue_node_421_t* knode;

  // Lock queue
  mutex_lock(queue->lock);

  // Retrieve first available node
  knode = queue->head;

  // If node unavailable
  if (knode == NULL){
    // Unlock queue
    mutex_unlock(queue->lock);
    // Print error message and return error
    printk("dequeueNode: ERROR: queue is empty");
    return ENOENT;
  }

  // Copy to user space
  if (copy_to_user(result, knode, sizeof(queue_node_421_t)) != 0){
    // Unlock queue
    mutex_unlock(queue->lock);
    // Print error message and return error
    printk("dequeueNode: ERROR: failed to copy node to user space");
    return EIO;
  }

  // If head is also tail (only 1 node)
  if (queue->head == queue->tail){
    // Remove queue head and tail
    queue->head = queue->tail = NULL;
  }
  else {
    // Assign next node as queue head
    queue->head = queue->head->next;
  }

  // Decrement queue node count
  queue->num_nodes--;

  // Deallocate kernel space for result
  kfree(knode);
printk("INFO: node[%d](%d) retrieved", result->id, result->priority);
printk("INFO: num_nodes=%d", queue->num_nodes);

  // Unlock queue
  mutex_unlock(queue->lock);

  // Return success
  return 0;
}

/**
 * Adds node in user space to priority queue.
 * @param queue     target priority queue.
 * @param node	    node in user space.
 * @returns 0 if successful, error code otherwise.
 */
long enqueueNode(priority_queue_421_t* queue, queue_node_421_t* node){
  queue_node_421_t* knode;

  // If target queue is NULL
  if (queue == NULL){
    // Print error message and return error
    printk("enqueueNode: ERROR: target queue is not initialized");
    return ENOENT;
  }

  // Lock queue
  mutex_lock(queue->lock);

  // Allocate kernel space for node
  if ((knode = kmalloc(sizeof(queue_node_421_t), GFP_KERNEL)) == NULL){
    // Unlock queue
    mutex_unlock(queue->lock);
    // Print error message and return error
    printk("enqueueNode: ERROR: failed to allocate kernel memory for node");
    return ENOMEM;
  }

  // Copy node to kernel space
  if (copy_from_user(knode, node, sizeof(queue_node_421_t)) != 0){
    // Unlock queue
    mutex_unlock(queue->lock);
    // Print error message and return error
    printk("enqueueNode: ERROR: failed to copy node to kernel space");
    return EIO;
  }

  // If no nodes in queue
  if (queue->head == NULL){
    // Assign node as queue head and tail
    queue->tail = queue->head = knode;
  }
  else{
    // Point previous queue tail to new node
    queue->tail->next = knode;
    // Assign node as queue tail
    queue->tail = knode;
  }

  // Increment queue node count
  queue->num_nodes++;
printk("INFO: node[%d](%d) added", knode->id, knode->priority);
printk("INFO: num_nodes=%d", queue->num_nodes);

  // Unlock queue
  mutex_unlock(queue->lock);

  // Return success
  return 0;
}

/**
 * Deallocates priority queue.
 * @param queue     priority queue.
 */
void freeQueue(priority_queue_421_t* queue){
printk("freeQueue: HERE0");
  if (queue != NULL){
    queue_node_421_t* node;
printk("freeQueue: HERE1");

    // Lock queue
    mutex_lock(queue->lock);
printk("freeQueue: HERE2");

    // Deallocate queue nodes
    while ((node = queue->head) != NULL){
      // Assign next node as head
      queue->head = queue->head->next;
      // Deallocate node
      kfree(node);
    }
printk("freeQueue: HERE3");

    // Unlock queue
    mutex_unlock(queue->lock);
printk("freeQueue: HERE4");

    // Destroy and deallocate queue mutex
    mutex_destroy(queue->lock);
printk("freeQueue: HERE5");
    kfree(queue->lock);
printk("freeQueue: HERE6");

    // Deallocate queue
    queue->tail = NULL;
    queue->lock = NULL;
    queue->num_nodes = 0;
    kfree(queue);
printk("freeQueue: HERE7");
  }
}

