#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <sys/syscall.h>
#include "421proj3structs.h"

#define INIT_APP_SYSCALL 600
#define FREE_APP_SYSCALL 601
#define ADD_PRIORITY_SYSCALL 602
#define GET_PRIORITY_SYSCALL 603

#define NUM_THREADS_1 100
#define NUM_THREADS_2 30
#define NUM_THREADS_3 20

#define MUTEX_FAILURE -999;


// Test data
const char* DATA = "Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal. "
""
"Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and so dedicated, can long endure. We are met on a great battle-field of that war. We have come to dedicate a portion of that field, as a final resting place for those who here gave their lives that that nation might live. It is altogether fitting and proper that we should do this. "
""
"But, in a larger sense, we can not dedicate—we can not consecrate—we can not hallow—this ground. The brave men, living and dead, who struggled here, have consecrated it, far above our poor power to add or detract. The world will little note, nor long remember what we say here, but it can never forget what they did here. It is for us the living, rather, to be dedicated here to the unfinished work which they who fought here have thus far so nobly advanced. It is rather for us to be here dedicated to the great task remaining before us—that from these honored dead we take increased devotion to that cause for which they gave the last full measure of devotion—that we here highly resolve that these dead shall not have died in vain—that this nation, under God, shall have a new birth of freedom—and that government of the people, by the people, for the people, shall not perish from the earth.";

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
char* concatElements(char** string, int numElements, int start, int count, char* delim);
int getArrayLength(char** array);
priority_421_t getPriority(int priorityNum);
int getRandomInt(int max);
char** getTokens(const char* string);
queue_node_421_t** createPriorityNodes(int numNodes, char** data, int numData);
long add_priority_threaded(queue_node_421_t** nodes, int numNodes);
long get_priority_threaded(queue_node_421_t** nodes, int numNodes);
long random_add_get_priority_threaded(char** data, int numData, int numThreads);
long random_init_free_application_threaded(int numthreads);
void test_threaded(char** data, int numData);
void test_nonthreaded(char** data, int numData);
void test_init_app();
void test_add_priority();
void test_get_priority();
void test_free_app();
void printPass(char* message);
void printFail(char* message);

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
	// Create test nodes
	queue_node_421_t** nodes = createPriorityNodes(5, data, numData);

	// Run init application tests
	test_init_app();

	// Run add priority tests
	test_add_priority(nodes);

	// Run get priority tests
	test_get_priority();

	// Run free application tests
	test_free_app();

	// Cleanup
	free(nodes);
}

/**
 * Runs threaded tests.
 * @param data		array of test data.
 * @param numData	number of array elements.
 */
void test_threaded(char** data, int numData){
	int numNodes = NUM_THREADS_1;

	// Initialize application
	long rc = init_kern_application();

	// Add priority nodes using threads
	queue_node_421_t** nodes = createPriorityNodes(numNodes, data, numData);
	
	rc = add_priority_threaded(nodes, numNodes);
	if (rc == 0){
		printPass("test_add_priority_100_threads");
	}
	else {
		printFail("test_add_priority_100_threads");
	}

	// Get priority nodes using threads
	rc = get_priority_threaded(nodes, numNodes);
	if (rc == 0){
		printPass("test_get_priority_100_threads");
	}
	else {
		printFail("test_get_priority_100_threads");
	}

	// Cleanup nodes
	free(nodes);

	// Free application
	rc = free_kern_application();	

	// Add/get priority nodes randomly using threads
	rc = random_add_get_priority_threaded(data, numData, NUM_THREADS_2);
	if (rc == 0){
		printPass("test_random_add_get_priority_30_threads");
	}
	else {
		printFail("test_random_add_get_priority_30_threads");
	}

	// Init/free application randomly using threads
	rc = random_init_free_application_threaded(NUM_THREADS_3);
	if (rc == 0){
		printPass("test_random_init_free_application_20_threads");
	}
	else {
		printFail("test_random_init_free_application_20_threads");
	}

	// Free application
	rc = free_kern_application();	
}

/**
 * Creates given number of priority nodes.
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
		fprintf(stderr, "ERROR: Failed to initialize mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}

	// Add priority nodes
	printf("Adding %d priority nodes...\n", numNodes);
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
			return MUTEX_FAILURE;
		}

		printf("\tNode: %d (%d)\n", nodes[i]->id, nodes[i]->priority);
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
		fprintf(stderr, "ERROR: Failed to initialize mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}

	// Get all priority nodes
	printf("Getting all priority nodes...\n");
	for (int i = 0; i < numNodes; i++){
		queue_node_421_t* node = malloc(sizeof(queue_node_421_t));

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
				free(args[i].node);
			}
			// Destroy mutex lock
			pthread_mutex_destroy(&lock);
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

		// Report and deallocate node
		queue_node_421_t* node = args[i].node;
		printf("\tNode: %d (%d)\n", node->id, node->priority);
		free(node);
	}

	// Destroy mutex lock
	if ((err = pthread_mutex_destroy(&lock)) != 0){
		fprintf(stderr, "ERROR: Failed to destroy mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}	

	// Return success
	return 0;
}

/**
 * Add and gets priority nodes randomly using threads.
 * @param data		array of test data.
 * @param numData	number of array elements.
 * @param numThreads	number of threads to run.
 */
long random_add_get_priority_threaded(char** data, int numData, int numThreads){
	// Initialize threads and mutex lock
	pthread_t threads[numThreads];
	thread_arg_t args[numThreads];
	int err = pthread_mutex_init(&lock, NULL);
	if (err != 0){
		fprintf(stderr, "ERROR: Failed to initialize mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}

	int maxNodes = numThreads / 2;
	queue_node_421_t** nodes = (void *)malloc(sizeof(queue_node_421_t*) * maxNodes);
	int nodeCount = 0;
	int nodesRetrieved = 0;

	// Add/get priority nodes
	printf("Adding/getting priority nodes using %d threads...\n", numThreads);
	int dataOffset = 0;
	for (int i = 0; i < numThreads; i++){
		// Determine whether to add or get priority nodes
		int add = getRandomInt(2) == 1;

		// If under retrieval threshold and should add node
		if (nodeCount + nodesRetrieved < numThreads && add){
			// Create node
			queue_node_421_t* node = (void *)malloc(sizeof(queue_node_421_t));
			node->id = i + 1;
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
				}
				// Destroy mutex lock
				pthread_mutex_destroy(&lock);
				return MUTEX_FAILURE;
			}

			printf("\tNode added: %d (%d)\n", nodes[i]->id, nodes[i]->priority);
			dataOffset += numValues;

			nodeCount++;
		}
		else {
			// Return node
			queue_node_421_t* node = malloc(sizeof(queue_node_421_t));

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
					free(args[i].node);
				}
				// Destroy mutex lock
				pthread_mutex_destroy(&lock);
				return MUTEX_FAILURE;
			}
		}
	}

	// Wait for all threads to finish
	for (int i = 0; i < numThreads; i++){
		err = pthread_join(threads[i], NULL);
		if (err != 0){
			// Print error message
			fprintf(stderr, "ERROR: Failed to join thread %d. Error Code: %d\n", i + 1, err);
		}

		// If node being retrieved
		if (!args[i].add){
			// Report and deallocate node
			queue_node_421_t* node = args[i].node;
			printf("\tNode retrieved: %d (%d)\n", node->id, node->priority);
			free(node);
		}
	}

	// Destroy mutex lock
	if ((err = pthread_mutex_destroy(&lock)) != 0){
		fprintf(stderr, "ERROR: Failed to destroy mutex. Error Code: %d\n", err);
		return MUTEX_FAILURE;
	}	

	// Return success
	return 0;
}

/**
 * Initializes and frees application randomly using threads.
 * @param numThreads	number of threads to run.
 */
long random_init_free_application_threaded(int numThreads){
	// Initialize threads and mutex lock
	pthread_t threads[numThreads];
	thread_arg_t args[numThreads];
	int err = pthread_mutex_init(&lock, NULL);
	if (err != 0){
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
				return MUTEX_FAILURE;
			}
		}
	}

	// Wait for all threads to finish
	int successCount = 0;
	int previousInit = 0;
	for (int i = 0; i < numThreads; i++){
		err = pthread_join(threads[i], NULL);
		if (err != 0){
			// Print error message
			fprintf(stderr, "ERROR: Failed to join thread %d. Error Code: %d\n", i + 1, err);
		}

		// Report results
		if (args[i].add){
			printf("\tApplication inited: %d)\n", args[i].tid);
			if (args[i].rc == 0 || previousInit && args[i].rc == EPERM){
				successCount++;
			}
			previousInit = 1;
		}
		else {
			printf("\tApplication freed: %d)\n", args[i].tid);
			if (args[i].rc == 0 || !previousInit && args[i].rc == EPERM){
				successCount++;
			}
			previousInit = 0;
		}
	}

	// Return success or failure
	return successCount == numThreads;
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
 * @param data		array of test data.
 * @param numData	number of array elements.
 */
void test_add_priority(queue_node_421_t** nodes){
	// Test enqueue
	long rc = kern_add_priority(nodes[0]);
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
//TBD: free queue
	rc = kern_add_priority(nodes[1]);
	if (rc == ENOENT){
		printPass("test_kern_add_priority_returns_ENOENT");
	}
	else {
		printFail("test_kern_add_priority_returns_ENOENT");
	}

	// Test enqueue failed to allocate kernel memory (TBD)
	rc = kern_add_priority(nodes[2]);
	if (rc == ENOMEM){
		printPass("test_kern_add_priority_returns_ENOMEM");
	}
	else {
		printFail("test_kern_add_priority_returns_ENOMEM");
	}

	// Test enqueue	failed to copy node to kernel memory (TBD)
	rc = kern_add_priority(nodes[3]);
	if (rc == EIO){
		printPass("test_kern_add_priority_returns_EIO");
	}
	else {
		printFail("test_kern_add_priority_returns_EIO");
	}
}
 
/**
 * Runs non-threaded get priority tests.
 */
void test_get_priority(){
	// Test get priority
	queue_node_421_t node;
	long rc = kern_get_priority(&node);
	if (rc == 0){
		printPass("test_kern_get_priority_returns_0");
	}
	else {
		printFail("test_kern_get_priority_returns_0");
	}

	// Test get priority empty queues
	rc = kern_get_priority(&node);
	if (rc == ENOENT){
		printPass("test_kern_get_priority_returns_ENOENT");
	}
	else {
		printFail("test_kern_get_priority_returns_ENOENT");
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

	// Test get priority failed to copy result to user space (TBD)
	rc = kern_get_priority(&node);
	if (rc == EIO){
		printPass("test_kern_get_priority_returns_EIO");
	}
	else {
		printFail("test_kern_get_priority_returns_EIO");
	}
}

/**
 * Runs non-threaded application deallocation tests.
 */
void test_free_app(){
	// Test free application
	long rc = free_kern_application();	
	if (rc == 0){
		printPass("test_free_kern_application_returns_0");
	}
	else {
		printFail("test_free_kern_application_returns_0");
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

