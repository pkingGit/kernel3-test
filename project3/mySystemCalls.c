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

proj_app_ctx_t* application = NULL;

SYSCALL_DEFINE0(init_kern_application) {
  return -1;
}

SYSCALL_DEFINE0(free_kern_application) {
  return -1;
}

SYSCALL_DEFINE1(kern_add_priority, void __user*, node) {
  return -1;
}

SYSCALL_DEFINE1(kern_get_priority, void __user*, dest) {
  return -1;
}
