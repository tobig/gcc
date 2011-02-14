/* Print floating point number in hexadecimal notation according to ISO C99.
   Copyright (C) 1997-2002,2004,2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <config.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NDEBUG
#include <assert.h>
#include "quadmath-printf.h"
#include "_itoa.h"
#include "_itowa.h"


/* Macros for doing the actual output.  */

#define outchar(ch)							      \
  do									      \
    {									      \
      register const int outc = (ch);					      \
      if (PUTC (outc, fp) == EOF)					      \
	return -1;							      \
      ++done;								      \
    } while (0)

#define PRINT(ptr, wptr, len)						      \
  do									      \
    {									      \
      register size_t outlen = (len);					      \
      if (wide)								      \
	while (outlen-- > 0)						      \
	  outchar (*wptr++);						      \
      else								      \
	while (outlen-- > 0)						      \
	  outchar (*ptr++);						      \
    } while (0)

#define PADN(ch, len)							      \
  do									      \
    {									      \
      if (PAD (fp, ch, len) != len)					      \
	return -1;							      \
      done += len;							      \
    }									      \
  while (0)



int
__quadmath_printf_fphex (struct __quadmath_printf_file *fp,
			 const struct printf_info *info,
			 const void *const *args)
{
  /* The floating-point value to output.  */
  ieee854_float128 fpnum;

  /* Locale-dependent representation of decimal point.	*/
  const char *decimal;
  wchar_t decimalwc;

  /* "NaN" or "Inf" for the special cases.  */
  const char *special = NULL;
  const wchar_t *wspecial = NULL;

  /* Buffer for the generated number string for the mantissa.  The
     maximal size for the mantissa is 128 bits.  */
  char numbuf[32];
  char *numstr;
  char *numend;
  wchar_t wnumbuf[32];
  wchar_t *wnumstr;
  wchar_t *wnumend;
  int negative;

  /* The maximal exponent of two in decimal notation has 5 digits.  */
  char expbuf[5];
  char *expstr;
  wchar_t wexpbuf[5];
  wchar_t *wexpstr;
  int expnegative;
  int exponent;

  /* Non-zero is mantissa is zero.  */
  int zero_mantissa;

  /* The leading digit before the decimal point.  */
  char leading;

  /* Precision.  */
  int precision = info->prec;

  /* Width.  */
  int width = info->width;

  /* Number of characters written.  */
  int done = 0;

  /* Nonzero if this is output on a wide character stream.  */
  int wide = info->wide;

  /* Figure out the decimal point character.  */
#ifdef USE_LOCALE_SUPPORT
  if (info->extra == 0)
    {
      decimal = nl_langinfo (DECIMAL_POINT);
      decimalwc = nl_langinfo_wc (_NL_NUMERIC_DECIMAL_POINT_WC);
    }
  else
    {
      decimal = nl_langinfo (MON_DECIMAL_POINT);
      if (*decimal == '\0')
	decimal = nl_langinfo (DECIMAL_POINT);
      decimalwc = nl_langinfo_wc (_NL_MONETARY_DECIMAL_POINT_WC);
      if (decimalwc == L'\0')
	decimalwc = nl_langinfo_wc (_NL_NUMERIC_DECIMAL_POINT_WC);
    }
  /* The decimal point character must never be zero.  */
  assert (*decimal != '\0' && decimalwc != L'\0');
#else
  decimal = ".";
  decimalwc = L_('.');
#endif

  /* Fetch the argument value.	*/
    {
      fpnum.value = **(const __float128 **) args[0];

      /* Check for special values: not a number or infinity.  */
      if (isnanq (fpnum.value))
	{
	  negative = fpnum.ieee.negative != 0;
	  if (isupper (info->spec))
	    {
	      special = "NAN";
	      wspecial = L_("NAN");
	    }
	  else
	    {
	      special = "nan";
	      wspecial = L_("nan");
	    }
	}
      else
	{
	  if (isinfq (fpnum.value))
	    {
	      if (isupper (info->spec))
		{
		  special = "INF";
		  wspecial = L_("INF");
		}
	      else
		{
		  special = "inf";
		  wspecial = L_("inf");
		}
	    }

	  negative = signbitq (fpnum.value);
	}
    }

  if (special)
    {
      int width = info->width;

      if (negative || info->showsign || info->space)
	--width;
      width -= 3;

      if (!info->left && width > 0)
	PADN (' ', width);

      if (negative)
	outchar ('-');
      else if (info->showsign)
	outchar ('+');
      else if (info->space)
	outchar (' ');

      PRINT (special, wspecial, 3);

      if (info->left && width > 0)
	PADN (' ', width);

      return done;
    }

    {
      /* We have 112 bits of mantissa plus one implicit digit.  Since
	 112 bits are representable without rest using hexadecimal
	 digits we use only the implicit digits for the number before
	 the decimal point.  */
      uint64_t num0, num1;

      assert (sizeof (long double) == 16);

      num0 = fpnum.ieee.mant_high;
      num1 = fpnum.ieee.mant_low;

      zero_mantissa = (num0|num1) == 0;

      if (sizeof (unsigned long int) > 6)
	{
	  numstr = _itoa_word (num1, numbuf + sizeof numbuf, 16,
			       info->spec == 'A');
	  wnumstr = _itowa_word (num1,
				 wnumbuf + sizeof (wnumbuf) / sizeof (wchar_t),
				 16, info->spec == 'A');
	}
      else
	{
	  numstr = _itoa (num1, numbuf + sizeof numbuf, 16,
			  info->spec == 'A');
	  wnumstr = _itowa (num1,
			    wnumbuf + sizeof (wnumbuf) / sizeof (wchar_t),
			    16, info->spec == 'A');
	}

      while (numstr > numbuf + (sizeof numbuf - 64 / 4))
	{
	  *--numstr = '0';
	  *--wnumstr = L_('0');
	}

      if (sizeof (unsigned long int) > 6)
	{
	  numstr = _itoa_word (num0, numstr, 16, info->spec == 'A');
	  wnumstr = _itowa_word (num0, wnumstr, 16, info->spec == 'A');
	}
      else
	{
	  numstr = _itoa (num0, numstr, 16, info->spec == 'A');
	  wnumstr = _itowa (num0, wnumstr, 16, info->spec == 'A');
	}

      /* Fill with zeroes.  */
      while (numstr > numbuf + (sizeof numbuf - 112 / 4))
	{
	  *--numstr = '0';
	  *--wnumstr = L_('0');
	}

      leading = fpnum.ieee.exponent == 0 ? '0' : '1';

      exponent = fpnum.ieee.exponent;

      if (exponent == 0)
	{
	  if (zero_mantissa)
	    expnegative = 0;
	  else
	    {
	      /* This is a denormalized number.  */
	      expnegative = 1;
	      exponent = IEEE854_FLOAT128_BIAS - 1;
	    }
	}
      else if (exponent >= IEEE854_FLOAT128_BIAS)
	{
	  expnegative = 0;
	  exponent -= IEEE854_FLOAT128_BIAS;
	}
      else
	{
	  expnegative = 1;
	  exponent = -(exponent - IEEE854_FLOAT128_BIAS);
	}
    }

  /* Look for trailing zeroes.  */
  if (! zero_mantissa)
    {
      wnumend = &wnumbuf[sizeof wnumbuf / sizeof wnumbuf[0]];
      numend = &numbuf[sizeof numbuf / sizeof numbuf[0]];
      while (wnumend[-1] == L_('0'))
	{
	  --wnumend;
	  --numend;
	}

      if (precision == -1)
	precision = numend - numstr;
      else if (precision < numend - numstr
	       && (numstr[precision] > '8'
		   || (('A' < '0' || 'a' < '0')
		       && numstr[precision] < '0')
		   || (numstr[precision] == '8'
		       && (precision + 1 < numend - numstr
			   /* Round to even.  */
			   || (precision > 0
			       && ((numstr[precision - 1] & 1)
				   ^ (isdigit (numstr[precision - 1]) == 0)))
			   || (precision == 0
			       && ((leading & 1)
				   ^ (isdigit (leading) == 0)))))))
	{
	  /* Round up.  */
	  int cnt = precision;
	  while (--cnt >= 0)
	    {
	      char ch = numstr[cnt];
	      /* We assume that the digits and the letters are ordered
		 like in ASCII.  This is true for the rest of GNU, too.  */
	      if (ch == '9')
		{
		  wnumstr[cnt] = (wchar_t) info->spec;
		  numstr[cnt] = info->spec;	/* This is tricky,
		  				   think about it!  */
		  break;
		}
	      else if (tolower (ch) < 'f')
		{
		  ++numstr[cnt];
		  ++wnumstr[cnt];
		  break;
		}
	      else
		{
		  numstr[cnt] = '0';
		  wnumstr[cnt] = L_('0');
		}
	    }
	  if (cnt < 0)
	    {
	      /* The mantissa so far was fff...f  Now increment the
		 leading digit.  Here it is again possible that we
		 get an overflow.  */
	      if (leading == '9')
		leading = info->spec;
	      else if (tolower (leading) < 'f')
		++leading;
	      else
		{
		  leading = '1';
		  if (expnegative)
		    {
		      exponent -= 4;
		      if (exponent <= 0)
			{
			  exponent = -exponent;
			  expnegative = 0;
			}
		    }
		  else
		    exponent += 4;
		}
	    }
	}
    }
  else
    {
      if (precision == -1)
	precision = 0;
      numend = numstr;
      wnumend = wnumstr;
    }

  /* Now we can compute the exponent string.  */
  expstr = _itoa_word (exponent, expbuf + sizeof expbuf, 10, 0);
  wexpstr = _itowa_word (exponent,
			 wexpbuf + sizeof wexpbuf / sizeof (wchar_t), 10, 0);

  /* Now we have all information to compute the size.  */
  width -= ((negative || info->showsign || info->space)
	    /* Sign.  */
	    + 2    + 1 + 0 + precision + 1 + 1
	    /* 0x    h   .   hhh         P   ExpoSign.  */
	    + ((expbuf + sizeof expbuf) - expstr));
	    /* Exponent.  */

  /* Count the decimal point.
     A special case when the mantissa or the precision is zero and the `#'
     is not given.  In this case we must not print the decimal point.  */
  if (precision > 0 || info->alt)
    width -= wide ? 1 : strlen (decimal);

  if (!info->left && info->pad != '0' && width > 0)
    PADN (' ', width);

  if (negative)
    outchar ('-');
  else if (info->showsign)
    outchar ('+');
  else if (info->space)
    outchar (' ');

  outchar ('0');
  if ('X' - 'A' == 'x' - 'a')
    outchar (info->spec + ('x' - 'a'));
  else
    outchar (info->spec == 'A' ? 'X' : 'x');

  if (!info->left && info->pad == '0' && width > 0)
    PADN ('0', width);

  outchar (leading);

  if (precision > 0 || info->alt)
    {
      const wchar_t *wtmp = &decimalwc;
      PRINT (decimal, wtmp, wide ? 1 : strlen (decimal));
    }

  if (precision > 0)
    {
      ssize_t tofill = precision - (numend - numstr);
      PRINT (numstr, wnumstr, MIN (numend - numstr, precision));
      if (tofill > 0)
	PADN ('0', tofill);
    }

  if ('P' - 'A' == 'p' - 'a')
    outchar (info->spec + ('p' - 'a'));
  else
    outchar (info->spec == 'A' ? 'P' : 'p');

  outchar (expnegative ? '-' : '+');

  PRINT (expstr, wexpstr, (expbuf + sizeof expbuf) - expstr);

  if (info->left && info->pad != '0' && width > 0)
    PADN (info->pad, width);

  return done;
}