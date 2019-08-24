#ifndef _IO_H_
#define _IO_H_

#include <nore.h>
#include <stdio.h>

#define _unused_(x) (void)(x)

#if MSVC
#  pragma warning(disable:4996) /* _CRT_SECURE_NO_WARNINGS  */
#endif

#if CLANG
#  pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif

#if GCC
#  pragma GCC diagnostic ignored "-Wdeprecated-declarations"
/* #  include <features.h> */
#endif

#endif /* end of _IO_H_ */
