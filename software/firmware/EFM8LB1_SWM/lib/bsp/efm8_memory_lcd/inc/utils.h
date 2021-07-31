/////////////////////////////////////////////////////////////////////////////
// Utils.h
/////////////////////////////////////////////////////////////////////////////

#ifndef UTILS_H_
#define UTILS_H_

/////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifndef UNREFERENCED_ARGUMENT
#if defined __C51__
/// Macro for removing unreferenced arguments from compiler warnings
#define UNREFERENCED_ARGUMENT(arg) (0, arg)
#elif defined __ICC8051__
/// Macro for removing unreferenced arguments from compiler warnings
#define UNREFERENCED_ARGUMENT(arg) ((void)arg)
#endif
#endif

#endif /* UTILS_H_ */
