#pragma once

#include <Defines.h>
#include <stdint.h>

namespace KenshiLib
{
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

	enum HookStatus
	{
		SUCCESS,
		FAIL
	};

	KLIB_EXPORT HookStatus AddHook(void* target, void* detour, void** original);

	// convenience functions
	template<typename T>
	inline HookStatus AddHook(intptr_t target, void* detour, T** original)
	{
		return AddHook((void*)target, detour, (void**)original);
	}
	template<typename T1, typename T2>
	inline HookStatus AddHook(T1* target, void* detour, T2** original)
	{
		return AddHook((void*)target, detour, (void**)original);
	}


#ifdef KENSHILIB_INTERNAL
	void InitRVAs();
#endif
}