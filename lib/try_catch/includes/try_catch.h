#ifndef TRY_CATCH_H
#define TRY_CATCH_H
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
// @Author b0n3@1337

// @usage: see lib/try_catch/tests/test

// ! if you are using vs code make sure to install
// ! (better comments) extension  for better comments readability.

// ! please define these global variables every time you want to user try or catch 
// ! jmp_buf * __TRY_CATCH_LIB__raise_env = NULL;
// ! jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;
// ! exception  (int)


// used by macros for RAISE'd errors
extern jmp_buf * __TRY_CATCH_LIB__raise_env;
// used by macros for RETRY
extern jmp_buf * __TRY_CATCH_LIB__retry_env;
int  exception = 0;
// list of predefined  codekt˚
// todo: add more exceptions
enum {
  MALLOC_EXCEPTION = 1,// RAISE'd when malloc() == NULL in rmalloc()
  RETRY_EXCEPTION =2 ,             // RAISE'd when RETRY not within a CATCH block
  ILLEGAL_ARGUMENT_EXCEPTION = 3, 
  ILLEGAL_STATE_EXCEPTION = 4,
  INDEX_OUT_OF_BOUNDS_EXCEPTION = 5,
  NULL_POINTER_EXCEPTION = 6
};

#ifndef ERRORS_V
#define ERRORS_V
char errors[7][30]  = {
    "",
    "MALLOC_EXCEPTION",
    "RETRY_EXCEPTION",
    "ILLEGAL_ARGUMENT_EXCEPTION",
    "ILLEGAL_STATE_EXCEPTION",
    "INDEX_OUT_OF_BOUNDS_EXCEPTION",
    "NULL_POINTER_EXCEPTION"
};
#endif
// When below a TRY block in the call stack
//      pass the given exception code to the 
//      paired CATCH blocks
// When no TRY block is above in the call stack
//      exits with the given error code.
//
// NOTE:the given exception must be non-zero,
//      otherwise, the behaviour is undefined
#define RAISE(exception)  \
  if (__TRY_CATCH_LIB__raise_env)\
    longjmp(*__TRY_CATCH_LIB__raise_env,exception);\
  else{\
    printf("%s" , errors[exception]);\
    exit(exception);\
  }

// When below a CATCH block in the call stack
//      rerun the paired TRY block
// When no CATCH block is above in the call stack
//      raises a RETRY_EXCEPTION exception.
#define RETRY do {\
  if (__TRY_CATCH_LIB__retry_env)\
    longjmp(*__TRY_CATCH_LIB__retry_env,1);\
  else\
    RAISE(RETRY_EXCEPTION);\
} while(0)

// The TRY macro allows you to run the code
//    passed in the given block, passing
//    any RAISE'd exceptions to paired
//    CATCH blocks.
//
// The TRY macro may be paired with 
//    zero or more CATCH blocks,
//    but *must* be paired with a single
//    FINALLY block.
//
// If an exception is RAISE'd, but not
//    handled by any paired CATCH block,
//    then it will be passed to the
//    next TRY/CATCH/FINALLY up the
//    call stack after the paired 
//    FINALLY block is called.
//
//  TRY(
//    // some code
//  ) FINALLY (
//    // some code
//  );
//
//  TRY(
//    // some code
//  ) CATCH ( exception == 1,
//    // what to do with a 1 exception
//  ) CATCH ( exception == 2,
//    // what to do with a 2 exception
//    // ...
//  ) FINALLY (
//    // some code
//  );
#define TRY(block) do\
{\
\
  jmp_buf * const __TRY_CATCH_LIB__old_raise_env = __TRY_CATCH_LIB__raise_env;\
  jmp_buf * const __TRY_CATCH_LIB__old_retry_env = __TRY_CATCH_LIB__retry_env;\
  jmp_buf __TRY_CATCH_LIB__catch_raise_env;\
  int const __TRY_CATCH_LIB__reraise = setjmp(__TRY_CATCH_LIB__catch_raise_env);\
  \
  if (!__TRY_CATCH_LIB__reraise) {\
    jmp_buf __TRY_CATCH_LIB__try_raise_env;\
    int const __TRY_CATCH_LIB__exception = setjmp(__TRY_CATCH_LIB__try_raise_env);\
    jmp_buf __TRY_CATCH_LIB__try_retry_env;\
    int const __TRY_CATCH_LIB__retry  = setjmp(__TRY_CATCH_LIB__try_retry_env);\
    \
    __TRY_CATCH_LIB__raise_env = &__TRY_CATCH_LIB__try_raise_env; \
    __TRY_CATCH_LIB__retry_env = __TRY_CATCH_LIB__old_retry_env; \
    if (!__TRY_CATCH_LIB__exception || __TRY_CATCH_LIB__retry) {\
      block\
    }\
    else {\
      exception = __TRY_CATCH_LIB__exception;\
      \
      __TRY_CATCH_LIB__raise_env = &__TRY_CATCH_LIB__catch_raise_env;\
      __TRY_CATCH_LIB__retry_env = &__TRY_CATCH_LIB__try_retry_env;\
    }\
  }\
  }while(0);


// The CATCH macro allows a block of code
//    to be run conditionally on a matching
//    exception being RAISE'd within the paired
//    TRY block.
// 
// The CATCH macro must be paired with
//    a TRY block and a FINALLY block.
//
// The condition and the block can access
//    the `exception` variable to find
//    the value of the most recently RAISE'd exception.
//
// The block will be run if
//  * no prior CATCH block's `condition` matches the exception
//  * this `condition` evaluates to a non-zero value
//
// If the CATCH block raises an exception, it will be 
//    passed to the next TRY/CATCH/FINALLY block up the
//    scope after the paired FINALLY block is called.
#define CATCH(condition, block)\
      if (condition) {\
        block\
      }\
      else

// The FINALLY macro allows a block to be run after
//    the paired TRY block and CATCH blocks, whether 
//    or not it RAISE an exception.
//
// The FINALLY macro *must* be paired with a
//    single TRY block.
//
// Any exceptions RAISE'd in the finally block are
//    passed up the call stack to the nearest enclosing
//    TRY/CATCH/FINALLY block.

// Convenience method to allocate nbytes.
// returns a pointer to the allocated memory,
// RAISE's a MALLOC_EXCEPTION if the memory is
// not allocated, so it is not necessary to check
// the return value.
void * rmalloc(size_t const nbytes);  // malloc(nbytes) || RAISE(MALLOC_EXCEPTION)

#endif