
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_concurrent_RejectedExecutionHandler__
#define __java_util_concurrent_RejectedExecutionHandler__

#pragma interface

#include <java/lang/Object.h>

class java::util::concurrent::RejectedExecutionHandler : public ::java::lang::Object
{

public:
  virtual void rejectedExecution(::java::lang::Runnable *, ::java::util::concurrent::ThreadPoolExecutor *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __java_util_concurrent_RejectedExecutionHandler__
