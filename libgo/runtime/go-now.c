// Copyright 2011 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

// Return current time.  This is the implementation of time.now().

struct time_now_ret
{
  int64_t sec;
  int32_t nsec;
};

struct time_now_ret now()
  __asm__ ("libgo_time.time.now")
  __attribute__ ((no_split_stack));

struct time_now_ret
now()
{
  struct timeval tv;
  struct time_now_ret ret;

  gettimeofday (&tv, NULL);
  ret.sec = tv.tv_sec;
  ret.nsec = tv.tv_usec * 1000;
  return ret;
}
