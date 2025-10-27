
#ifndef UMBC_KERN_PROJ_TEMPLATE_H 
#define UMBC_KERN_PROJ_TEMPLATE_H 

// kernel-space headers
#include <linux/mutex.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/errno.h>

// common structures
#include "421proj3structs.h"

// the Queue structure
typedef struct priority_queue_421 {
  queue_node_421_t*   head;
  queue_node_421_t*   tail;
  struct mutex*       lock;
  int                 num_nodes;
} priority_queue_421_t;

// the application context which stores each queue
typedef struct proj_app_ctx {
  priority_queue_421_t* highQueue;
  priority_queue_421_t* mediumQueue;
  priority_queue_421_t* lowQueue;
} proj_app_ctx_t;

#endif
