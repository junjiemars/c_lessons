#ifndef _GEO_H_
#define _GEO_H_

#include <nm_auto_config.h>
#include <nm_auto_header.h>

#if (MSYS_NT)

#define GEO_API __declspec(dllexport) __stdcall

#else

#define GEO_API

#endif

#ifdef __cplusplus
extern "C" {
#endif

double GEO_API area_of_rect(double, double);

#ifdef __cplusplus
}
#endif


#endif // _GEO_H_
