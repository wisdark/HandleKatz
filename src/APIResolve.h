#pragma once

#include <stdint.h>
#include "windows.h"
#include "wininet.h"
#include "psapi.h"

#include <tlhelp32.h>

#include "Defines.h"

#define FAIL 0
#define SUCCESS 1

#define CRYPT_KEY 0x41424344

uint64_t getFunctionPtr(unsigned long, unsigned long);

// ----  KERNEL32 ----
#define CRYPTED_HASH_KERNEL32 0x3102ad31 
#define CRYPTED_HASH_LOADLIBRARYA 0x1efdb3bf
#define CRYTPED_HASH_VIRTUALALLOC 0x796e4cd3
#define CRYPTED_HASH_LSTRCATA 0x93fde827
#define CRYPTED_HASH_LSTRLENA 0x9386e84e
#define CRYPTED_HASH_CLOSEHANDLE 0x79328943
#define CRYPTED_HASH_VIRTUALFREE 0x27cd8c6a
#define CRYPTED_HASH_COPYMEMORY 0x14d8cfcf
#define CRYPTED_HASH_GETCURRENTTHREAD 0xa17b4b84
#define CRYPTED_HASH_TERMINATETHREAD 0xc6ec2902
#define CRYPTED_HASH_SETCURRENTDIRECTORY 0xff81e32e
#define CRYPTED_HASH_MULTIBYTETOWIDECHAR 0xa3bf99ca
#define CRYPTED_HASH_WIDECHARTOMULTIBYTE 0xa71f728a
#define CRYPTED_HASH_LSTRCATW 0x93fde83d
#define CRYPTED_HASH_LSTRLENW 0x9386e864
#define CRYPTED_HASH_CREATEFILEA 0xaad486be
#define CRYPTED_HASH_WRITEFILE 0x277eaff4
#define CRYPTED_HASH_SETFILEPOINTER 0x12ad28b6
#define CRYPTED_HASH_OPENPROCESS 0x3074be92
#define CRYPTED_HASH_CREATETOOLHELP32SNAPSHOT 0x27c751d1
#define CRYPTED_HASH_OPENPROCESSTOKEN 0x843993d3
#define CRYPTED_HASH_PROCESS32NEXT 0xd1553c6c
#define CRYPTED_HASH_PROCESS32FIRST 0xd33afb35
#define CRYPTED_HASH_GETLASTERROR 0x61c0a9a7
#define CRYPTED_HASH_DELETEFILEA 0x5d9ac45d
#define CRYPTED_HASH_COPYFILE 0xed601085
#define CRYPTED_HASH_LSTRCMPW 0x93fd9d45
#define CRYPTED_HASH_GETCURRENTPROCESS 0x8bcf3663
#define CRYPTED_HASH_LSTRCMPA 0x93fd9eaf
#define CRYPTED_HASH_LOOKUPPRIVILEGEVALUEA 0xfaec2dc0
#define CRYPTED_HASH_GETMODULEFILENAMEEXA 0xa5240a0e
#define CRYPTED_HASH_GETPROCESSIMAGEFILENAMEA 0x5f11c72d
#define CRYPTED_HASH_GETPROCESSID 0x8c484b5
#define CRYPTED_HASH_GETPROCESSHEAP 0x871a4e46
#define CRYPTED_HASH_HEAPALLOC 0x5ebf244a
#define CRYPTED_HASH_HEAPREALLOC 0x5f738261
#define CRYPTED_HASH_HEAPFREE 0x760ad081
#define CRYPTED_HASH_GETSYSTEMINFO 0xc24aacb2
#define CRYPTED_HASH_FREELIBRARY 0x71ac8d78
#define CRYPTED_HASH_ISPROCESSORFEATUREPRESENT 0x83081c4a
#define CRYPTED_HASH_VIRTUALQUERYEX 0x96d1a8db
#define CRYPTED_HASH_SETFILEPOINTEREX 0x4c387a8b
#define CRYPTED_HASH_LSTRCPYW 0x93fda8a9
#define CRYPTED_HASH_GETMODULEFILENAMEEXW 0xa5240a24
#define CRYPTED_HASH_ENUMPROCESSMODULES 0xe49cdcd6
#define CRYPTED_HASH_GETMODULEINFORMATION 0xb7f544b5
#define CRYPTED_HASH_GETMODULEBASENAMEW 0xbbcd9cda
#define CRYPTED_HASH_GETPROCADDRESS 0x8e73f85b

typedef BOOL(WINAPI* CLOSEHANDLE)(HANDLE);
typedef HMODULE(WINAPI* LOADLIBRARYA)(LPCSTR);
typedef LPSTR(WINAPI* LSTRCATA)(LPSTR, LPSTR);
typedef LPVOID(WINAPI* VIRTUALALLOC)(LPVOID, SIZE_T, DWORD, DWORD);
typedef int(WINAPI* LSTRLENA)(LPCSTR);
typedef BOOL(WINAPI* VIRTUALFREE)(LPVOID, SIZE_T, DWORD);
typedef BOOL(WINAPI* VIRTUALFREE)(LPVOID, SIZE_T, DWORD);
typedef void(WINAPI* COPYMEMORY)(PVOID, void*, SIZE_T);
typedef BOOL(WINAPI* TERMINATETHREAD)( HANDLE,  DWORD );
typedef HANDLE (WINAPI* GETCURRENTTHREAD)();
typedef BOOL(WINAPI* SETCURRENTDIRECTORY)(LPCTSTR);
typedef int(WINAPI* MULTIBYTETOWIDECHAR)(UINT, DWORD, LPCCH, int, LPWSTR, int);
typedef int(WINAPI* WIDECHARTOMULTIBYTE)(UINT, DWORD, LPCWCH, int, LPSTR, int, LPCCH, LPBOOL);
typedef LPWSTR(WINAPI* LSTRCATW)(LPWSTR, LPCWSTR);
typedef int (WINAPI* LSTRLENW)(LPCWSTR);
typedef HANDLE(WINAPI* CREATEFILEA)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
typedef BOOL(WINAPI* WRITEFILE)(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED);
typedef DWORD(WINAPI* SETFILEPOINTER)(HANDLE, LONG, PLONG, DWORD);
typedef HANDLE(WINAPI* OPENPROCESS)(DWORD, BOOL, DWORD);
typedef HANDLE(WINAPI* CREATETOOLHELP32SNAPSHOT)(DWORD, DWORD);
typedef BOOL(WINAPI* OPENPROCESSTOKEN)(HANDLE, DWORD, PHANDLE);
typedef BOOL(WINAPI* PROCESS32NEXT)(HANDLE, LPPROCESSENTRY32);
typedef BOOL(WINAPI* PROCESS32FIRST)(HANDLE, LPPROCESSENTRY32);
typedef DWORD(WINAPI* GETLASTERROR)(VOID);
typedef BOOL(WINAPI* DELETEFILEA)(LPCSTR);
typedef BOOL(WINAPI* COPYFILE)(LPCTSTR, LPCTSTR, BOOL);
typedef int(WINAPI* LSTRCMPW)(LPCWSTR, LPCWSTR);
typedef HANDLE(WINAPI* GETCURRENTPROCESS)(void);
typedef int (WINAPI* LSTRCMPA)(LPCSTR, LPCSTR);
typedef BOOL(WINAPI* LOOKUPPRIVILEGEVALUEA)(LPCSTR, LPCSTR, PLUID);
typedef DWORD(WINAPI* GETMODULEFILENAMEXA)(HANDLE, HMODULE, LPSTR, DWORD);
typedef DWORD(WINAPI* GETPROCESSIMAGEFILENAMEA)(HANDLE, LPSTR, DWORD);
typedef DWORD(WINAPI* GETPROCESSID)(HANDLE);
typedef HANDLE(WINAPI* GETPROCESSHEAP)();
typedef LPVOID(WINAPI* HEAPALLOC)(HANDLE, DWORD, SIZE_T);
typedef LPVOID(WINAPI* HEAPREALLOC)(HANDLE, DWORD, LPVOID, SIZE_T);
typedef BOOL(WINAPI* HEAPFREE)(HANDLE, DWORD, LPVOID);
typedef void(WINAPI* GETSYSTEMINFO)(LPSYSTEM_INFO);
typedef BOOL(WINAPI* FREELIBRARY)(HMODULE);
typedef BOOL(WINAPI* ISPROCESSORFEATUREPRESENT)(DWORD);
typedef SIZE_T(WINAPI* VIRTUALQUERYEX)(HANDLE, LPCVOID, PMEMORY_BASIC_INFORMATION, SIZE_T);
typedef BOOL(WINAPI* SETFILEPOINTEREX)(HANDLE, LARGE_INTEGER, PLARGE_INTEGER, DWORD);
typedef LPWSTR(WINAPI* LSTRCPYW)(LPWSTR, LPCWSTR);
typedef DWORD(WINAPI* GETMODULEFILENAMEEXW)(HANDLE, HMODULE, LPWSTR, DWORD);
typedef BOOL(WINAPI* ENUMPROCESSMODULES)(HANDLE, HMODULE*, DWORD, LPDWORD);
typedef BOOL(WINAPI* GETMODULEINFORMATION)(HANDLE, HMODULE, LPMODULEINFO, DWORD);
typedef BOOL(WINAPI* GETMODULEBASENAMEW)(HANDLE, HMODULE, LPWSTR, DWORD);
typedef FARPROC(WINAPI* GETPROCADDRESS)(HMODULE, LPCSTR);

// ---- USER32 ----
#define CRYPTED_HASH_USER32 0x985bec97
#define CRYPTED_HASH_WSPRINTFA 0xb9dafb87
#define CRYPTED_HASH_WSPRINTFW 0xb9dafb9d

typedef int(WINAPI* WSPRINTFA)(LPSTR, LPCSTR, ...);
typedef int(WINAPI* WSPRINTFW)(LPWSTR, LPCWSTR, ...);

// ---- Advapi32 ----
#define CRYPTED_HASH_ADVAPI32 0x2662c90d
#define CRYPTED_HASH_GETTOKENINFORMATION 0xcf963c68
#define CRYPTED_HASH_DUPLICATETOKENEX 0x3cd8cc5a

typedef BOOL(WINAPI* GETTOKENINFORMATION)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD);
typedef BOOL(WINAPI* DUPLICATETOKENEX)(HANDLE, DWORD, LPSECURITY_ATTRIBUTES, SECURITY_IMPERSONATION_LEVEL, TOKEN_TYPE, PHANDLE);

// ---- shlwapi.dll ----
#define CRYPTED_HASH_SHLWAPI 0xe64fd763
#define CRYPTED_HASH_STRSTRA 0x4ef4617c
#define CRYPTED_HASH_PATHFINDFILENAMEA 0x9ed91f31
#define CRYPTED_HASH_STRCMPW 0x4eef7d71

typedef PCSTR(WINAPI* STRSTRA)(PCSTR, PCSTR);
typedef LPCSTR(WINAPI* PATHFINDFILENAMEA)(LPCSTR);
typedef int(WINAPI* STRCMPW)(PCWSTR, PCWSTR);

// ---- Psapi.dll ----
#define CRYPTED_HASH_PSAPI 0xf82688

// ----  Api-ms-win-core-version-l1-1-0.dll
#define CRYPTED_HASH_API_MS_WIN_CORE_DLL 0xf5ce0ebb
#define CRYPTED_HASH_GETFILEVERSIONINFOSIZEW 0x504105cd
#define CRYPTED_HASH_GETFILEVERSIONINFOW 0x9436ba2a
#define CRYPTED_HASH_VERQUERYVALUEW 0x3927db18

typedef DWORD(WINAPI* GETFILEVERSIONINFOSIZEW)(LPCWSTR, LPDWORD);
typedef BOOL(WINAPI* GETFILEVERSIONINFOW)(LPCWSTR, DWORD, DWORD, LPVOID);
typedef BOOL(WINAPI* VERQUERYVALUEW)(LPVOID, LPCWSTR, LPVOID, PUINT);
