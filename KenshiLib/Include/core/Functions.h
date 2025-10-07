#pragma once

#include <Defines.h>
#include <stdint.h>


KLIB_EXPORT intptr_t GetRealAddress(void* fun);

//       convenience functions

// usage: GetRealAddress(&Class::function)
// NOTE: doesn't work with virtual functions
template<typename T>
inline intptr_t GetRealAddress(T fun)
{
	return GetRealAddress((void*&)fun);
}

// NOTE: doesn't work with virtual functions
template<typename T>
inline T GetRealFunction(T fun)
{
	return (T)GetRealAddress(fun);
}

#ifdef KENSHILIB_EXPORT
void InitRVAs();
#endif