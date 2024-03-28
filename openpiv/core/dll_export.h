#pragma once

#ifndef DLL_EXPORT

#if defined(_MSC_VER) && defined(_EXPORT_DLL_SYMBOLS)
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#endif