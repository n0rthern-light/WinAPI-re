#pragma once

#include "winapi_defines.h"

//__declspec(naked) void kernel32__ThpCreateRawSnap();


namespace wrappers {

    extern DWORD h_memset;
    extern DWORD hNtMapViewSection;
    extern DWORD hRtlRestoreLastWin32Error;
    extern DWORD hNtUnmapViewOfSection;
    extern DWORD hBaseSetLastNTError;

    inline DWORD nt_open_process(DWORD hNtOpenProcess, DWORD* pHandle, DWORD DesiredAccess, OBJECT_ATTRIBUTES* ObjectAttributes, CLIENT_ID* client_id) {
        __asm {
            push client_id
            push ObjectAttributes
            push DesiredAccess
            push pHandle
            call hNtOpenProcess
        }
    }

    inline void nt_read_virtual_memory(DWORD hNtReadVirutalMemory, DWORD pHandle, DWORD BaseAddress, void* buffer, DWORD bytes_to_read, DWORD* bytes_readed) {
        __asm {
            push bytes_readed
            push bytes_to_read
            push buffer
            push BaseAddress
            push pHandle
            call hNtReadVirutalMemory
        }
    }

    inline DWORD nt_close(DWORD hNtClose, void* pHandle) {
        __asm {
            push pHandle
            call hNtClose
        }
    }

    inline DWORD rtl_get_buffer(DWORD hRtlQueryProcessDebugInformation, ULONG ProcessId, ULONG  DebugInfoClassMask, PDEBUG_BUFFER  DebugBuffer) {
        __asm {
            push DebugBuffer
            push DebugInfoClassMask
            push ProcessId
            call hRtlQueryProcessDebugInformation
        }
    }
    inline DWORD rtl_create_buffer(DWORD hRtlCreateQueryDebugBuffer, ULONG sizeOfSize, BOOLEAN eventPair) {
        __asm {
            push eventPair
            push sizeOfSize
            call hRtlCreateQueryDebugBuffer
        }
    }
    inline DWORD rtl_destroy_buffer(DWORD hRtlDestroyQueryDebugBuffer, PDEBUG_BUFFER debugBuffer) {
        __asm {
            push debugBuffer
            call hRtlDestroyQueryDebugBuffer
        }
    }
    inline __declspec(naked) DWORD rtl_create_buffer2() {

    }
}