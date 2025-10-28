#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <sys/syscall.h>
#include "421proj3structs.h"

#define INIT_APP_SYSCALL 600
#define FREE_APP_SYSCALL 601
#define ADD_PRIORITY_SYSCALL 602
#define GET_PRIORITY_SYSCALL 603

#define MUTEX_FAILURE -998;
#define TEST_FAILED -999;

#define NUM_NODES 10

#define NUM_THREADS_1 100
#define NUM_THREADS_2 30
#define NUM_THREADS_3 20


// Test data
const char* DATA = "Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal. "
""
"Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and so dedicated, can long endure. We are met on a great battle-field of that war. We have come to dedicate a portion of that field, as a final resting place for those who here gave their lives that that nation might live. It is altogether fitting and proper that we should do this. "
""
"But, in a larger sense, we can not dedicate—we can not consecrate—we can not hallow—this ground. The brave men, living and dead, who struggled here, have consecrated it, far above our poor power to add or detract. The world will little note, nor long remember what we say here, but it can never forget what they did here. It is for us the living, rather, to be dedicated here to the unfinished work which they who fought here have thus far so nobly advanced. It is rather for us to be here dedicated to the great task remaining before us—that from these honored dead we take increased devotion to that cause for which they gave the last full measure of devotion—that we here highly resolve that these dead shall not have died in vain—that this nation, under God, shall have a new birth of freedom—and that government of the people, by the people, for the people, shall not perish from the earth.";

const size_t NODE_SIZE = sizeof(queue_node_421_t);

// Mutex lock
pthread_mutex_t lock;

// Argument to thread task
typedef struct{
	int tid;
	queue_node_421_t* node;
	int add;
	int rc;
} thread_arg_t;

// Function declarations
void cleanupNodeArray(queue_node_421_t** array, int numElements);
queue_node_421_t** cloneNodes(queue_node_421_t** nodes, int numNodes);
int compareIntegers(const void *a, const void *b);
char* concatElements(char** string, int numElements, int start, int count, char* delim);
queue_node_421_t** createPriorityNodes(int numNodes, char** data, int numData);
int getArrayLength(char** array);
priority_421_t getPriority(int priorityNum);
int getRandomInt(int max);
int getRemainingNodes();
char** getTokens(const char* string);
long add_priority_threaded(queue_node_421_t** nodes, int numNodes);
long get_priority_threaded(queue_node_421_t** nodes, int numNodes);
void printFail(char* message);
void printPass(char* message);
long random_add_get_priority_threaded(char** data, int numData, int numThreads);
long random_init_free_application_threaded(int numthreads);
void test_add_priority(queue_node_421_t** nodes);
void test_free_app(queue_node_421_t** nodes);
void test_get_priority(queue_node_421_t** nodes);
void test_init_app();
void test_nonthreaded(char** data, int numData);
void test_threaded(char** data, int numData);

// System function calls
long init_kern_application() {
        return syscall(INIT_APP_SYSCALL);
}
long free_kern_application() {
        return syscall(FREE_APP_SYSCALL);
}
long kern_add_priority(queue_node_421_t* node) {
        return syscall(ADD_PRIORITY_SYSCALL, node);
}
long kern_get_priority(queue_node_421_t* dest) {
        return syscall(GET_PRIORITY_SYSCALL, dest);
}

// Execute init application in thread
void* init_kern_application_task(void *arg) {
	// Extract arguments
	thread_arg_t *targ = (thread_arg_t*)arg;
	int tid = targ->tid;

	// Obtain lock
	int err = pthread_mutex_lock(&lock);
	if (err != 0){
		// Print error message and return error
		fprintf(stderr, "[Thread %d] ERROR: Failed to acquire lock. Error Code: %d\n", tid, err);
		targ->rc = MUTEX_FAILURE;
		return NULL;
	}

        targ->rc = syscall(INIT_APP_SYSCALL);

	// Release lock
	err = pthread_mutex_unlock(&lock);
	if (err != 0){
		// Print error message and abort thread
		fprintf(stderr, "[Thread %d] FATAL: Failed to release lock. Error Code: %d\n", tid, err);
		targ->rc = MUTEX_FAILURE;
		abort();
	}

	// Return
	return NULL;
}
// Execute free application in thread
void* free_kern_application_task(void *arg) {
	// Extract arguments
	thread_arg_t *targ = (thread_arg_t*)arg;
	int tid = targ->tid;

	// Obtain lock
	int err = pthread_mutex_lock(&lock);
	if (err != 0){
		// Print error message and return error
		fprintf(stderr, "[Thread %d] ERROR: Failed to acquire lock. Error Code: %d\n", tid, err);
		targ->rc = MUTEX_FAILURE;
		return NULL;
	}

        targ->rc = syscall(FREE_APP_SYSCALL);

	// Release lock
	err = pthread_mutex_unlock(&lock);
	if (err != 0){
		// Print error message and abort thread
		fprintf(stderr, "[Thread %d] FATAL: Failed to release lock. Error Code: %d\n", tid, err);
		targ->rc = MUTEX_FAILURE;
		abort();
	}

	// Return
	return NULL;
}
// Execute add priority in thread
void* kern_add_priority_task(void *arg) {
	// Extract arguments
	thread_arg_t *targ = (thread_arg_t*)arg;
	int tid = targ->tid;
	queue_node_421_t* node = targ->node;

	// Obtain lock
	int err = pthread_mutex_lock(&lock);
	if (err != 0){
		// Print error message and return error
		fprintf(stderr, "[Thread %d] ERROR: Failed to acquire lock. Error Code: %d\n", tid, err);
		targ->rc = MUTEX_FAILURE;
		return NULL;
	}

        targ->rc = syscall(ADD_PRIORITY_SYSCALL, node);

	// Release lock
	err = pthread_mutex_unlock(&lock);
	if (err != 0){
		// Print error message and abort thread
		fprintf(stderr, "[Thread %d] FATAL: Failed to release lock. Error Code: %d\n", tid, err);
		targ->rc = MUTEX_FAILURE;
		abort();
	}

	// Return
	return NULL;
}
// Execute get priority in thread
void* kern_get_priority_task(void *arg) {
	// Extract arguments
	thread_arg_t *targ = (thread_arg_t*)arg;
	int tid = targ->tid;
	queue_node_421_t* dest = targ->node;

	// Obtain lock
	int err = pthread_mutex_lock(&lock);
	if (err != 0){
		// Print error message and return error
		fprintf(stderr, "[Thread %d] ERROR: Failed to acquire lock. Error Code: %d\n", tid, err);
		targ->rc = MUTEX_FAILURE;
		return NULL;
	}

        targ->rc = syscall(GET_PRIORITY_SYSCALL, dest);

	// Release lock
	err = pthread_mutex_unlock(&lock);
	if (err != 0){
		// Print error message and abort thread
		fprintf(stderr, "[Thread %d] FATAL: Failed to release lock. Error Code: %d\n", tid, err);
		targ->rc = MUTEX_FAILURE;
		abort();
	}

	// Return
	return NULL;
}

void main(int argc, char** argv){
	// Initialize data
	char** data = getTokens(DATA);
	int numData = getArrayLength(data);
	srand(time(NULL));	

	// Run non-threaded tests
	test_nonthreaded(data, numData);

	// Run threaded tests
	test_threaded(data, numData);

	// Cleanup
	free(data[0]);
	free(data);
	printf("Done\n");

	// Exit with success
	exit(0);
}

/**
 * Runs non-threaded tests.
 * @param data		array of test data.
 * @param numData	number of array elements.
 */
void test_nonthreaded(char** data, int numData){
	printf("\nPerforming non-threaded tests...\n");

	// Create test nodes
	queue_node_421_t** nodes = createPriorityNodes(NUM_NODES, data, numData);

	// Run init application tests
	test_init_app();

	// Run free application tests
	test_free_app(nodes);

	// Run add priority tests
	test_add_priority(nodes);

	// Run get priority tests
	test_get_priority(nodes);
	
	// Cleanup
	cleanupNodeArray(nodes, NUM_NODES);
}

/**
 * Runs threaded tests.
 * @param data		array of test data.
 * @param numData	number of array elements.
 */
void test_threaded(char** data, int numData){
	printf("\nPerforming threaded tests...\n");

	int numNodes = NUM_THREADS_1;
	char testName[100];

	// Initialize application
	long rc = init_kern_application();

	// Create test nodes
	queue_node_421_t** nodes = createPriorityNodes(numNodes, data, numData);

	// Add priority nodes using threads
	sprintf(testName, "test_add_priority_%d_threads", numNodes);
	rc = add_priority_threaded(nodes, numNodes);
	if (rc == 0){
		printPass(testName);
	}
	else {
		printFail(testName);
	}

	// Get priority nodes using threads
	sprintf(testName, "test_get_priority_%d_threads", numNodes);
	rc = get_priority_threaded(nodes, numNodes);
	if (rc == 0){
		printPass(testName);
	}
	else {
		printFail(testName);
	}

	// Cleanup nodes
	cleanupNodeArray(nodes, numNodes);

	// Free application
	rc = free_kern_application();	

	// Initialize application
	rc = init_kern_application();

	// Add/get priority nodes randomly using threads
	sprintf(testName, "test_random_add_get_priority_%d_threads", NUM_THREADS_2);
	rc = random_add_get_priority_threaded(data, numData, NUM_THREADS_2);
	if (rc == 0){
		printPass(testName);
	}
	else {
		printFail(testName);
	}

	// Free application
	rc = free_kern_application();	

	// Init/free application randomly using threads
	sprintf(testName, "test_random_init_free_application_%d_threads", NUM_THREADS_3);
	rc = random_init_free_application_threaded(NUM_THREADS_3);
	if (rc == 0){
		printPass(testName);
	}
	else {
		printFail(testName);
	}

	// Free application
	rc = free_kern_application();	
}

/**
 * Adds priority nodes using threads.
 * @param nodes		array of priority nodes.
 * @param numNodes	number of priority nodes.
 */
long add_priority_threaded(queue_node_421_t** nodes, int numNodes){
	// Initialize threads and mutex lock
	int numThreads = numNodes;
	pthread_t threads[numThreads];
	thread_arg_t args[numThreads];
	int err = pthread_mutex_init(&lock, NULL);
	if (err != 0){
		// Print error message and return error
		fprintf(stderr, "ERROR: Failed to initialize mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}

	// Add priority nodes
	for (int i = 0; i < numNodes; i++){
		// Execute add priority in thread
		args[i].tid = i + 1;
		args[i].node = nodes[i];
		err = pthread_create(&threads[i], NULL, kern_add_priority_task, &args[i]);
		if (err != 0){
			// Print error message
			fprintf(stderr, "ERROR: Failed to create thread %d. Error Code: %d\n", i + 1, err);
			// Join threads that did start
			for (int j = 0; j < i; j++){
				pthread_join(threads[j], NULL);
			}
			// Destroy mutex lock
			pthread_mutex_destroy(&lock);
			// Return error
			return MUTEX_FAILURE;
		}
	}

	// Wait for all threads to finish
	for (int i = 0; i < numNodes; i++){
		err = pthread_join(threads[i], NULL);
		if (err != 0){
			// Print error message
			fprintf(stderr, "ERROR: Failed to join thread %d. Error Code: %d\n", i + 1, err);
		}
	}

	// Destroy mutex lock
	if ((err = pthread_mutex_destroy(&lock)) != 0){
		// Print error message and return error
		fprintf(stderr, "ERROR: Failed to destroy mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}	

	// Return success
	return 0;
}

/**
 * Gets priority nodes using threads.
 * @param nodes		array of original priority nodes to verify against.
 * @param numNodes	number of priority nodes.
 */
long get_priority_threaded(queue_node_421_t** nodes, int numNodes){
	// Initialize threads and mutex lock
	int numThreads = numNodes;
	pthread_t threads[numThreads];
	thread_arg_t args[numThreads];
	int err = pthread_mutex_init(&lock, NULL);
	if (err != 0){
		// Print error message and return error
		fprintf(stderr, "ERROR: Failed to initialize mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}

	// Get all priority nodes
	for (int i = 0; i < numNodes; i++){
		queue_node_421_t* node = malloc(NODE_SIZE);
		memset(node, 0, NODE_SIZE);

		// Execute get priority in thread
		args[i].tid = i + 1;
		args[i].node = node;
		err = pthread_create(&threads[i], NULL, kern_get_priority_task, &args[i]);
		if (err != 0){
			// Print error message
			fprintf(stderr, "ERROR: Failed to create thread %d. Error Code: %d\n", i + 1, err);
			// Join threads that did start
			for (int j = 0; j < i; j++){
				pthread_join(threads[j], NULL);
				// Cleanup node
				free(args[j].node);
			}
			free(node);
			// Destroy mutex lock
			pthread_mutex_destroy(&lock);
			// Return error
			return MUTEX_FAILURE;
		}
	}

	int retrievedIds[numNodes];

	// Wait for all threads to finish
	for (int i = 0; i < numNodes; i++){
		err = pthread_join(threads[i], NULL);
		if (err != 0){
			// Print error message
			fprintf(stderr, "ERROR: Failed to join thread %d. Error Code: %d\n", i + 1, err);
		}

		// Report and deallocate node
		queue_node_421_t* node = args[i].node;
		if (args[i].rc == 0){
			// Collect retrieved node id
			retrievedIds[i] = node->id;
		}
		free(node);
	}

	// Sort retrieved node ids
	qsort(retrievedIds, numNodes, sizeof(int), compareIntegers);

	// Tally results
	int successCount = 0;
	for (int i = 0; i < numNodes; i++){
		if (retrievedIds[i] == nodes[i]->id){
			successCount++;
		}
	}

	// Destroy mutex lock
	if ((err = pthread_mutex_destroy(&lock)) != 0){
		// Print error message and return error
		fprintf(stderr, "ERROR: Failed to destroy mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}	

	// Return success or failure
	return successCount == numNodes ? 0 : TEST_FAILED;
}

/**
 * Add and gets priority nodes randomly using threads.
 * @param data		array of test data.
 * @param numData	number of array elements.
 * @param numThreads	number of threads to run.
 * @returns 0 if successful, non-zero otherwise.
 */
long random_add_get_priority_threaded(char** data, int numData, int numThreads){
	// Initialize threads and mutex lock
	pthread_t threads[numThreads];
	thread_arg_t args[numThreads];
	int err = pthread_mutex_init(&lock, NULL);
	if (err != 0){
		// Print error message and return error
		fprintf(stderr, "ERROR: Failed to initialize mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}

	int maxNodes = (int)floor(numThreads / 2);
	queue_node_421_t** nodes = (void *)malloc(sizeof(queue_node_421_t*) * maxNodes);
	int nodeCount = 0;
	int nodesRetrieved = 0;

	// Add/get priority nodes
	int numGets = 0;
	int numOutofOrderGets = 0;
	int dataOffset = 0;
	for (int i = 0; i < numThreads; i++){
		// Determine whether to add or get priority nodes
		int add = getRandomInt(2) == 1;

		// Create node
		queue_node_421_t* node = malloc(sizeof(queue_node_421_t));

		// If under retrieval threshold and should add node
		if (nodeCount + numOutofOrderGets < maxNodes && add){
			node->id = nodeCount + 1;
			node->priority = getPriority(getRandomInt(3));
			int numValues = getRandomInt(10);
			char* dataString = concatElements(data, numData, dataOffset, numValues, " ");
			strncpy(node->data, dataString, sizeof(node->data) - 1);
			free(dataString);
			nodes[nodeCount] = node;

			// Execute add priority in thread
			args[i].tid = i + 1;
			args[i].node = node;
			args[i].add = 1;
			err = pthread_create(&threads[i], NULL, kern_add_priority_task, &args[i]);
			if (err != 0){
				// Print error message
				fprintf(stderr, "ERROR: Failed to create thread %d. Error Code: %d\n", i + 1, err);
				// Join threads that did start
				for (int j = 0; j < i; j++){
					pthread_join(threads[j], NULL);
					// Cleanup node
					free(args[j].node);
				}
				free(node);
				// Destroy mutex lock
				pthread_mutex_destroy(&lock);
				// Return error
				return MUTEX_FAILURE;
			}

			dataOffset += numValues;
			nodeCount++;
		}
		else {
			// Execute get priority in thread
			args[i].tid = i + 1;
			args[i].node = node;
			args[i].add = 0;
			err = pthread_create(&threads[i], NULL, kern_get_priority_task, &args[i]);
			if (err != 0){
				// Print error message
				fprintf(stderr, "ERROR: Failed to create thread %d. Error Code: %d\n", i + 1, err);
				// Join threads that did start
				for (int j = 0; j < i; j++){
					pthread_join(threads[j], NULL);
					// Cleanup node
					free(args[j].node);
				}
				free(node);
				// Destroy mutex lock
				pthread_mutex_destroy(&lock);
				// Return error
				return MUTEX_FAILURE;
			}
			numGets++;
			if (numGets > nodeCount){
				numOutofOrderGets++;
			}
		}
	}

	int retrievedIds[nodeCount];

	// Wait for all threads to finish
	int numEmptyQueues = 0;
	for (int i = 0; i < numThreads; i++){
		err = pthread_join(threads[i], NULL);
		if (err != 0){
			// Print error message
			fprintf(stderr, "ERROR: Failed to join thread %d. Error Code: %d\n", i + 1, err);
		}

		// If node being retrieved
		queue_node_421_t* node = args[i].node;
		if (args[i].add == 1){
			queue_node_421_t* node = args[i].node;
		}
		else {
			if (args[i].rc == 0){
				// Collect retrieved node id
				if (nodesRetrieved < nodeCount){
					retrievedIds[nodesRetrieved++] = node->id;
				}
			}
			else {
				if (args[i].rc == ENOENT){
					numEmptyQueues++;
				}
			}
		}
	}

	// Sort retrieved node ids
	qsort(retrievedIds, nodesRetrieved, sizeof(int), compareIntegers);

	// Tally results
	int successCount = 0;
	for (int i = 0; i < nodesRetrieved; i++){
		if (retrievedIds[i] == nodes[i]->id){
			successCount++;
		}
	}
	if (successCount < nodeCount){
		// Retrieve missing nodes if possible
		int numRetrievedUnthreaded = getRemainingNodes();
		nodesRetrieved += numRetrievedUnthreaded;
	}

	// Cleanup nodes
	for (int i = 0; i < numThreads; i++){
		free(args[i].node);
	}
	free(nodes);

	// Destroy mutex lock
	if ((err = pthread_mutex_destroy(&lock)) != 0){
		// Print error message and return error
		fprintf(stderr, "ERROR: Failed to destroy mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}	

	// Return success or failure
	return nodesRetrieved != nodeCount;
}

/**
 * Initializes and frees application randomly using threads.
 * @param numThreads	number of threads to run.
 * @returns 0 if successful, non-zero otherwise.
 */
long random_init_free_application_threaded(int numThreads){
	// Initialize threads and mutex lock
	pthread_t threads[numThreads];
	thread_arg_t args[numThreads];
	int err = pthread_mutex_init(&lock, NULL);
	if (err != 0){
		// Print error message and return error
		fprintf(stderr, "ERROR: Failed to initialize mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}

	// Randomly init or free application
	for (int i = 0; i < numThreads; i++){
		// Determine whether to init or free application
		int init = getRandomInt(2) == 1;

		// Execute initialize application in thread
		args[i].tid = i + 1;

		long rc;
		if (init){
			// Initialize application
			args[i].add = 1;
			err = pthread_create(&threads[i], NULL, init_kern_application_task, &args[i]);
			if (err != 0){
				// Print error message
				fprintf(stderr, "ERROR: Failed to create thread %d. Error Code: %d\n", i + 1, err);
				// Join threads that did start
				for (int j = 0; j < i; j++){
					pthread_join(threads[j], NULL);
				}
				// Destroy mutex lock
				pthread_mutex_destroy(&lock);
				// Return error
				return MUTEX_FAILURE;
			}
		}
		else {
			// Free application
			args[i].add = 0;
			err = pthread_create(&threads[i], NULL, free_kern_application_task, &args[i]);
			if (err != 0){
				// Print error message
				fprintf(stderr, "ERROR: Failed to create thread %d. Error Code: %d\n", i + 1, err);
				// Join threads that did start
				for (int j = 0; j < i; j++){
					pthread_join(threads[j], NULL);
				}
				// Destroy mutex lock
				pthread_mutex_destroy(&lock);
				// Return error
				return MUTEX_FAILURE;
			}
		}
	}

	// Wait for all threads to finish
	int freeSuccessCount = 0;
	int initSuccessCount = 0;
	int knownErrors = 0;
	for (int i = 0; i < numThreads; i++){
		err = pthread_join(threads[i], NULL);
		if (err != 0){
			// Print error message
			fprintf(stderr, "ERROR: Failed to join thread %d. Error Code: %d\n", i + 1, err);
		}

		// Tally results
		if (args[i].add){
			if (args[i].rc == 0){
				initSuccessCount++;
			}
			else if (args[i].rc == EPERM){
				knownErrors++;
			}
		}
		else {
			if (args[i].rc == 0){
				freeSuccessCount++;
			}
			else if (args[i].rc == EPERM){
				knownErrors++;
			}
		}
	}

	// Return success or failure
	return initSuccessCount + freeSuccessCount + knownErrors != numThreads;
}

/**
 * Runs non-threaded application initialization tests.
 */
void test_init_app(){
	// Test initializing application
	long rc = init_kern_application();
	if (rc == 0){
		printPass("test_init_kern_application_returns_0");
	}
	else {
		printFail("test_init_kern_application_returns_0");
	}

	// Test initializing initialized queue
	rc = init_kern_application();
	if (rc == EPERM){
		printPass("test_init_kern_application_returns_EPERM");
	}
	else {
		printFail("test_init_kern_application_returns_EPERM");
	}
}

/**
 * Runs non-threaded add priority tests.
 * @param nodes		array of test priority nodes.
 */
void test_add_priority(queue_node_421_t** nodes){
	// Initialize application
	long rc = init_kern_application();

	// Test enqueue
	rc = kern_add_priority(nodes[0]);
	if (rc == 0){
		printPass("test_kern_add_priority_returns_0");
	}
	else {
		printFail("test_kern_add_priority_returns_0");
	}

	// Free queue (premise: that free_kern_application works!)
	free_kern_application();

	// Test add priority on uninitialized application
	rc = kern_add_priority(nodes[1]);
	if (rc == EPERM){
		printPass("test_kern_add_priority_returns_EPERM");
	}
	else {
		printFail("test_kern_add_priority_returns_EPERM");
	}

	// Test add priority on uninitialized queue
	printf("NO WAY TO TEST - kern_add_priority_returns_ENOENT (cannot uninitialize individual queue from user space, skipping...\n");
	//rc = kern_add_priority(nodes[1]);
	//if (rc == ENOENT){
	//	printPass("test_kern_add_priority_returns_ENOENT");
	//}
	//else {
	//	printFail("test_kern_add_priority_returns_ENOENT");
	//}

	// Test add priority failed to allocate kernel memory (TBD)
	printf("NO WAY TO TEST - kern_add_priority_returns_ENOMEM (cannot force kmalloc() failure, skipping...\n");
	//rc = kern_add_priority(nodes[2]);
	//if (rc == ENOMEM){
	//	printPass("test_kern_add_priority_returns_ENOMEM");
	//}
	//else {
	//	printFail("test_kern_add_priority_returns_ENOMEM");
	//}

	// Test add priority failed to copy node to kernel memory (TBD)
	printf("NO WAY TO TEST - kern_add_priority_returns_EIO (cannot force copy_from_user() failure, skipping...\n");
	//rc = kern_add_priority(nodes[3]);
	//if (rc == EIO){
	//	printPass("test_kern_add_priority_returns_EIO");
	//}
	//else {
	//	printFail("test_kern_add_priority_returns_EIO");
	//}
}
 
/**
 * Runs non-threaded get priority tests.
 * @param nodes		array of test priority nodes.
 */
void test_get_priority(queue_node_421_t** nodes){
	// Initialize application
	long rc = init_kern_application();

	// Test get priority on empty queues
	queue_node_421_t node;
	rc = kern_get_priority(&node);
	if (rc == ENOENT){
		printPass("test_kern_get_priority_returns_ENOENT");
	}
	else {
		printFail("test_kern_get_priority_returns_ENOENT");
	}

	// Add test nodes
	for (int i = 0; i < 5; i++){
		kern_add_priority(nodes[i]);
	}

	// Test get priority on populated queues
	rc = kern_get_priority(&node);
	if (rc == 0){
		printPass("test_kern_get_priority_returns_0");
	}
	else {
		printFail("test_kern_get_priority_returns_0");
	}

	// Free queue (premise: that free_kern_application works!)
	free_kern_application();

	// Test get priority uninitialized application
	rc = kern_get_priority(&node);
	if (rc == EPERM){
		printPass("test_kern_get_priority_returns_EPERM");
	}
	else {
		printFail("test_kern_get_priority_returns_EPERM");
	}

	// Test get priority failed to copy result to user space
	printf("NO WAY TO TEST - kern_get_priority_returns_EIO (cannot force copy_to_user() failure, skipping...\n");
	//rc = kern_get_priority(&node);
	//if (rc == EIO){
	//	printPass("test_kern_get_priority_returns_EIO");
	//}
	//else {
	//	printFail("test_kern_get_priority_returns_EIO");
	//}
}

/**
 * Runs non-threaded application deallocation tests.
 * @param nodes		array of test priority nodes.
 */
void test_free_app(queue_node_421_t** nodes){
	// Add test nodes
	for (int i = 0; i < NUM_NODES; i++){
		kern_add_priority(nodes[i]);
	}

	// Test free application with populated queues
	long rc = free_kern_application();	
	if (rc == 0){
		printPass("test_free_kern_application_returns_0_for_populated_queues");
	}
	else {
		printFail("test_free_kern_application_returns_0_for_populated_queues");
	}

	// Initialize application
	rc = init_kern_application();
	// Add test nodes (one with each priority)
	queue_node_421_t** newNodes = cloneNodes(nodes, 3);
	newNodes[0]->priority = HIGH;
	newNodes[1]->priority = MEDIUM;
	newNodes[2]->priority = LOW;
	for (int i = 0; i < 3; i++){
		kern_add_priority(newNodes[i]);
	}

	// Test free application with single node queues
	rc = free_kern_application();	
	if (rc == 0){
		printPass("test_free_kern_application_returns_0_for_single_node_queues");
	}
	else {
		printFail("test_free_kern_application_returns_0_for_single_node_queues");
	}

	// Cleanup
	cleanupNodeArray(newNodes, 3);

	// Initialize application
	rc = init_kern_application();

	// Test free application with empty queues
	rc = free_kern_application();
	if (rc == 0){
		printPass("test_free_kern_application_returns_0_for_empty_queues");
	}
	else {
		printFail("test_free_kern_application_returns_0_for_empty_queues");
	}

	// Test free application on uninitialized application
	rc = free_kern_application();	
	if (rc == EPERM){
		printPass("test_free_kern_application_returns_EPERM");
	}
	else {
		printFail("test_free_kern_application_returns_EPERM");
	}
}

/**
 * Deallocates array of dynamically allocated node elements.
 * @param array		array of dynamically allocated elements.
 * @param numElements	number of elements in array.
 */
void cleanupNodeArray(queue_node_421_t** array, int numElements){
	if (array != NULL){
		// Deallocate dyanamically allocated array elements
		for (int i = 0; i < numElements; i++){
			free(array[i]);
		}
		// Deallocate array
		free(array);
	}
}

/**
 * Clones given number of priority nodes from an array. It is the
 * responibility of the caller to deallocate the result.
 * @param nodes		array of priority nodes.
 * @param numNodes	number of nodes to clone from beginning of array.
 *			Must be <= size of array.
 * @returns array of cloned nodes.
 */
queue_node_421_t** cloneNodes(queue_node_421_t** nodes, int numNodes){
	size_t nodeSize = sizeof(queue_node_421_t);

	// Allocate result array
	queue_node_421_t** result = (void*)malloc(sizeof(queue_node_421_t*) * numNodes);

	// Clone nodes
	for (int i = 0; i < numNodes; i++){
		// Allocate space for node and copy source node to target
		result[i] = (void*)malloc(nodeSize);
		memcpy(result[i], nodes[i], nodeSize);
	}

	// Return result
	return result;
}

/**
 * Concatenates given number of string array elements starting from given
 * offset.
 * @param array		string array.
 * @param numElements	total number of elements in array.
 * @param offset	0-relative starting offset.
 * @param count		number of elements to return.
 * @param delim		concatenation delimiter.
 * @returns concatenated elements using given delimiter.
 */
char* concatElements(char** array, int numElements, int start, int count, char* delim){
	int bufSize = 1024;
	char* buffer = malloc(bufSize);
	int delimLen = strlen(delim);
	int pos = 0;
	if (start < numElements){
		int end = start + count;
		for (int i = start; i < end && array[i] != NULL; i++){
			int len = strlen(array[i]);
			if (pos + len < bufSize - 1){
				buffer = realloc(buffer, bufSize + len + delimLen + 1024);
			}
			if (i > start){
				strcpy(buffer + pos, delim);
				pos += delimLen;
			}
			strcpy(buffer + pos, array[i]);
			pos += len;
		}
	}
	buffer[pos] = '\0';
	char* result = strdup(buffer);
	free(buffer);
	return result;
}

/**
 * Creates given number of priority nodes. It is the responsibility of the
 * caller to deallocate the result.
 * @param numNodes	number of nodes to create.
 * @param data		array of test data.
 * @param numData	number of array elements.
 * @returns array of priority nodes.
 */
queue_node_421_t** createPriorityNodes(int numNodes, char** data, int numData){
	queue_node_421_t** result = NULL;

	if (numNodes <= 0){
		return result;
	}

	result = (void *)malloc(sizeof(queue_node_421_t*) * numNodes);
	int dataOffset = 0;
	for (int i = 0; i < numNodes; i++){
		result[i] = (void *)malloc(sizeof(queue_node_421_t));
		result[i]->id = i + 1;
		result[i]->priority = getPriority(getRandomInt(3));
		int numValues = getRandomInt(10);
		char* dataString = concatElements(data, numData, dataOffset, numValues, " ");
		strncpy(result[i]->data, dataString, sizeof(result[i]->data) - 1);
		free(dataString);

		dataOffset += numValues;
	}

	return result;
}

/**
 * Returns length of null-terminated array.
 * @param array	array of strings.
 * @returns length of array.
 */
int getArrayLength(char** array){
	int len = 0;
	while (*array != NULL) {
		len++;
		array++;
	}
	return len;
}

/**
 * Returns a queue priority corresponding to an integer between 1 and 3.
 * @param priorityNum	priority number between 1 and 3, inclusive,
 *                      where 1 is HIGH and 3 is LOW.
 * @returns queue priority or low if number is out of range.
 */
priority_421_t getPriority(int priorityNum){
	switch (priorityNum){
		case 1: return HIGH;
		case 2: return MEDIUM;
		case 3: return LOW;
		default: return LOW;
	}
}

/**
 * Returns random integer between 1 and given maximum value.
 * @param max	maximum value.
 * @returns randomly generated integer.
 */
int getRandomInt(int max){
	int min = 1;
	return (rand() % (max - min + 1)) + min;	
}

/**
 * Extracts array of white-space separated tokens from a string.
 * @param string	a string.
 * @returns array of tokens.
 */
char** getTokens(const char* string){
	// Copy original string (copy will be modified)
	char *copy = strdup(string);	
	// Allocate space for result
	int resultSize = 1024;
	char** result = malloc(sizeof(char*) * resultSize);
	// Extract tokens from string
	int numTokens = 0;
	char *delimiters = " \t\n";
	char* token = strtok(copy, delimiters);
	while (token != NULL){
		if (numTokens == resultSize - 1){
			resultSize += 1024;
			result = realloc(result, sizeof(char*) * resultSize);
		}
		result[numTokens++] = token;
		token = strtok(NULL, delimiters);
	}
	// Null terminate array
	result[numTokens] = NULL;
	// Return array of tokens
	return result;
}

/**
 * Prints color-coded test passed message.
 * @param message	a message.
 */
void printPass(char* message){
	printf("[\033[0;32mPASS\033[0m]: %s\n", message);
}

/**
 * Prints color-coded test failed message.
 * @param message	a message.
 */
void printFail(char* message){
	printf("[\033[0;31mFAILURE\033[0m]: %s\n", message);
}

/**
 * Compare two integers for sorting purposes.
 * @param a	first integer.
 * @param b	second integer.
 * @returns -1 if first integer is less than second, 1 if first integer is
 *		greater than second, or 0 if arguments are equal.
 */
int compareIntegers(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

/**
 * Retrieves any remaining nodes in priority queues.
 * @returns count of nodes retrieved.
 */
int getRemainingNodes(){
	int result = 0;

	queue_node_421_t node;
	int rc;
	while (kern_get_priority(&node) == 0){
		result++;
	}

	return result;
}

