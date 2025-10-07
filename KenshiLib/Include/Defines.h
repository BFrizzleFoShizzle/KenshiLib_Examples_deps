#pragma once

#ifdef KENSHILIB_EXPORT
#define KLIB_EXPORT __declspec(dllexport)
#else
#define KLIB_EXPORT __declspec(dllimport)
#endif