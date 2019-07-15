#ifndef LIB_H
#define LIB_H

#include <QtGlobal>

#define EXTERNC extern "C"
#ifdef Q_OS_WIN
    #define DLLEXPORT __declspec(dllexport)
#else
     #define DLLEXPORT
#endif

#endif // LIB_H
