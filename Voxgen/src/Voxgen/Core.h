#pragma once

#ifdef VG_PLATFORM_WINDOWS
	#pragma message("VG_PLATFORM_WINDOWS is defined")
	#ifdef VG_BUILD_DLL
		#pragma message("VG_BUILD_DLL is defined: exporting symbols")
		#define VOXGEN_API __declspec(dllexport)
	#else
		#pragma message("VG_BUILD_DLL is NOT defined: importing symbols")
		#define VOXGEN_API __declspec(dllimport)
	#endif
#else
	#define VOXGEN_API
	#error Voxgen only supports Windows!
#endif