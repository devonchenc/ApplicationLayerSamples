#pragma once

#ifndef BUILD_STATIC
# if defined(APPLICATIONLAYER_LIB)
#  define APPLICATIONLAYER_EXPORT __declspec(dllexport)
# else
#  define APPLICATIONLAYER_EXPORT __declspec(dllimport)
# endif
#else
# define APPLICATIONLAYER_EXPORT
#endif
