#pragma once

#ifdef EM_PLATFORM_WINDOWS
	#ifdef EM_BUILD_DLL
		#define EvreninMotoru_API __declspec(dllexport)
	#else
		#define EvreninMotoru_API __declspec(dllimport)
	#endif // EM_BUILD_DLL
#else 
	#error EvreninMotoru only supports Windows
#endif // EM_PLATFORM_WINDOWS

#define BIT(x) (1 << x)


