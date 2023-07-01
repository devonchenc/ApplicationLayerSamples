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

#ifndef APPLICATION_MACRO
#define APPLICATION_MACRO

template <typename T> inline T *getPtrHelper(T *ptr) { return ptr; }
#define APP_WARNING_PUSH        __pragma(warning(push))
#define APP_WARNING_POP         __pragma(warning(pop))
#define APP_CAST_IGNORE_ALIGN(body) APP_WARNING_PUSH body APP_WARNING_POP
#define APP_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() \
    { APP_CAST_IGNORE_ALIGN(return reinterpret_cast<Class##Private *>(getPtrHelper(d_ptr));) } \
    inline const Class##Private* d_func() const \
    { APP_CAST_IGNORE_ALIGN(return reinterpret_cast<const Class##Private *>(getPtrHelper(d_ptr));) } \
    friend class Class##Private;

#define APP_DECLARE_PUBLIC(Class)                                   \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); }  \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;

#define APP_D(Class) Class##Private * const d = d_func()
#define APP_D_C(Class) const Class##Private* d = d_func()
#define APP_Q(Class) Class * const q = q_func()
#endif

#ifndef POINT3
#define POINT3
typedef struct RawPoint3
{
    RawPoint3()
        : real(0)
        , imag(0)
        , ampl(0)
    {}

    float real;     // ʵ��
    float imag;     // �鲿
    float ampl;     // ��ֵ
}Point3;
#endif

#include <string>

// ���������ļ�·��
std::string APPLICATIONLAYER_EXPORT appConfigPath();

// ���������ļ�·��
void APPLICATIONLAYER_EXPORT setAppConfigPath(const std::string& path);

// �����豸����״̬
bool APPLICATIONLAYER_EXPORT testConnection();

#include "DoublePoint.h"