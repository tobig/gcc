/* { dg-do compile { target { powerpc*-*-* && lp64 } } } */
/* { dg-skip-if "" { *-*-darwin* } { "*" } { "" } } */
/* { dg-options "-O2 -mno-pointers-to-nested-functions" } */

extern void ext_call (int (func) (void));

int
outer_func (int init)	/* { dg-error "-mno-r11 must not be used if you have trampolines" "" } */
{
  int value = init;

  int inner (void)
  {
    return ++value;
  }

  ext_call (inner);
  return value;
}

