#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <sys/syscall.h>
#include "421proj3structs.h"

#define INIT_APP_SYSCALL 600
#define FREE_APP_SYSCALL 601
#define ADD_PRIORITY_SYSCALL 602
#define GET_PRIORITY_SYSCALL 603

#define NUM_THREADS_1 15
#define NUM_THREADS_2 20
#define MUTEX_FAILURE -999;

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
	int rc;
} thread_arg_t;

char* concatElements(char** string, int numElements, int start, int count, char* delim);
int getArrayLength(char** array);
priority_421_t getPriority(int priorityNum);
int getRandomInt(int max);
char** getTokens(const char* string);
void test0(char** data, int numData);
void test1(char** data, int numData);
void test2(char** data, int numData);

// System calls
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

	// Initialize application
	printf("Initializing application...\n");
	int rc = init_kern_application();
	if (rc != 0){
		// Print error message
		fprintf(stderr, "ERROR: Init failed with error code %d\n", rc);
		fprintf(stderr, "Attempting to fix...\n");
		// Attempt to free application
		if (free_kern_application() != 0){
			// Cleanup and exit with error
			fprintf(stderr, "ERROR: Fail to fix\n");
			free(data);
			exit(rc);
		}
	}

	// Run priority tests
	//test0(data, numData);
	test1(data, numData);
	test2(data, numData);

	// Free application
	printf("Freeing application...\n");
	free_kern_application();

	// Cleanup
	free(data);
	printf("Done\n");

	// Exit with success
	exit(0);
}

/**
 * Execute add/get priority tests using 15 nodes and add priority threading.
 * @param data		data array.
 * @param numData	length of array.
 */
void test0(char** data, int numData){
	printf("**** TEST 0 *****\n");

	int numNodes = NUM_THREADS_1;

	// Add priority nodes
	printf("Adding %d priority nodes...\n", numNodes);
	queue_node_421_t** nodes = (void *)malloc(sizeof(queue_node_421_t*) * numNodes);
	int offset = 0;
	for (int i = 0; i < numNodes; i++){
		nodes[i] = (void *)malloc(sizeof(queue_node_421_t));
		nodes[i]->id = i + 1;
		nodes[i]->priority = getPriority(getRandomInt(3));
		int numValues = getRandomInt(10);
		char* dataString = concatElements(data, numData, offset, numValues, " ");
		strncpy(nodes[i]->data, dataString, sizeof(nodes[i]->data) - 1);
		free(dataString);
		kern_add_priority(nodes[i]);

		printf("\tNode: %d (%d) data=%s\n", nodes[i]->id, nodes[i]->priority, nodes[i]->data);
		offset += numValues;
	}

	// Get all priority nodes
	printf("Getting all priority nodes...\n");
	for (int i = 0; i < numNodes; i++){
		queue_node_421_t* node = malloc(sizeof(queue_node_421_t));
		kern_get_priority(node);
		printf("\tNode: %d (%d)\n", node->id, node->priority);
		free(node);
	}

	// Cleanup
	free(nodes);
}


/**
 * Execute add/get priority tests using 15 nodes and add priority threading.
 * @param data		data array.
 * @param numData	length of array.
 */
void test1(char** data, int numData){
	printf("**** TEST 1 *****\n");

	// Initialize threads and mutex lock
	int numNodes = NUM_THREADS_1;
	pthread_t threads[NUM_THREADS_1];
	thread_arg_t args[NUM_THREADS_1];
	int err = pthread_mutex_init(&lock, NULL);
	if (err != 0){
		fprintf(stderr, "ERROR: Failed to initialize mutex. Error Code: %d\n", err);
		return;
	}

	// Add priority nodes
	printf("Adding %d priority nodes...\n", numNodes);
	queue_node_421_t** nodes = (void *)malloc(sizeof(queue_node_421_t*) * numNodes);
	int offset = 0;
	for (int i = 0; i < numNodes; i++){
		nodes[i] = (void *)malloc(sizeof(queue_node_421_t));
		nodes[i]->id = i + 1;
		nodes[i]->priority = getPriority(getRandomInt(3));
		int numValues = getRandomInt(10);
		char* dataString = concatElements(data, numData, offset, numValues, " ");
		strncpy(nodes[i]->data, dataString, sizeof(nodes[i]->data) - 1);
		free(dataString);

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
			// Cleanup
			free(nodes);
			// Destroy mutex lock
			pthread_mutex_destroy(&lock);
			return;
		}

		printf("\tNode: %d (%d)\n", nodes[i]->id, nodes[i]->priority);
		offset += numValues;
	}

	// Wait for all threads to finish
	for (int i = 0; i < numNodes; i++){
		err = pthread_join(threads[i], NULL);
		if (err != 0){
			// Print error message
			fprintf(stderr, "ERROR: Failed to join thread %d. Error Code: %d\n", i + 1, err);
		}
	}

	// Get all priority nodes
	printf("Getting all priority nodes...\n");
	for (int i = 0; i < numNodes; i++){
		queue_node_421_t* node = malloc(sizeof(queue_node_421_t));
		kern_get_priority(node);
		printf("\tNode: %d (%d)\n", node->id, node->priority);
		free(node);
	}

	// Cleanup
	free(nodes);

	// Destroy mutex lock
	if ((err = pthread_mutex_destroy(&lock)) != 0){
		fprintf(stderr, "ERROR: Failed to destroy mutex. Error Code: %d\n", err);
		return;
	}	
}

/**
 * Execute add/get priority tests using 20 nodes and get priority threading.
 * @param data		data array.
 * @param numData	number of array elements.
 */
void test2(char** data, int numData){
	printf("**** TEST 2 *****\n");

	// Initialize threads and mutex lock
	int numNodes = NUM_THREADS_2;
	pthread_t threads[NUM_THREADS_2];
	thread_arg_t args[NUM_THREADS_2];
	int err = pthread_mutex_init(&lock, NULL);
	if (err != 0){
		fprintf(stderr, "ERROR: Failed to initialize mutex. Error Code: %d\n", err);
		return;
	}

	// Add priority nodes
	printf("Adding %d priority nodes...\n", numNodes);
	queue_node_421_t** nodes = (void *)malloc(sizeof(queue_node_421_t*) * numNodes);
	int offset = 0;
	for (int i = 0; i < numNodes; i++){
		nodes[i] = (void *)malloc(sizeof(queue_node_421_t));
		nodes[i]->id = i + 1;
		nodes[i]->priority = getPriority(getRandomInt(3));
		int numValues = getRandomInt(10);
		char* dataString = concatElements(data, numData, offset, numValues, " ");
		strncpy(nodes[i]->data, dataString, sizeof(nodes[i]->data) - 1);
		free(dataString);
		kern_add_priority(nodes[i]);
		printf("\tNode: %d (%d)\n", nodes[i]->id, nodes[i]->priority);
		offset += numValues;
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
			// Cleanup
			free(nodes);
			// Destroy mutex lock
			pthread_mutex_destroy(&lock);
			return;
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

	// Cleanup
	free(nodes);

	// Destroy mutex lock
	if ((err = pthread_mutex_destroy(&lock)) != 0){
		fprintf(stderr, "ERROR: Failed to destroy mutex. Error Code: %d\n", err);
		return;
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

