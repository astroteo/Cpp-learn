#ifndef EXAMPLE_DLL_H
#define EXAMPLE_DLL_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILDING_EXAMPLE_DLL
#define EXAMPLE_DLL __declspec(dllexport)
#else
#define EXAMPLE_DLL __declspec(dllimport)
#endif

void __stdcall EXAMPLE_DLL hello(const char *s);

int EXAMPLE_DLL Double(int x);

#ifdef __cplusplus
}
#endif

void EXAMPLE_DLL CppFunc(void);

#endif
