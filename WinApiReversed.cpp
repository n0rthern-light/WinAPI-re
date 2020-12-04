#include "WinApiReversed.h"

void win_api::initialize() {

    win_module* ntdll = new win_module("ntdll.dll");
    ntdll->push_function("NtOpenProcess");
    ntdll->push_function("ZwOpenProcess");
    ntdll->push_function("NtReadVirtualMemory");
    ntdll->push_function("NtClose");
    ntdll->push_function("NtMapViewOfSection");
    ntdll->push_function("NtUnmapViewOfSection");
    ntdll->push_function("RtlRestoreLastWin32Error");
    ntdll->push_function("NtFreeVirtualMemory");
    ntdll->push_function("RtlCreateQueryDebugBuffer");
    ntdll->push_function("RtlDestroyQueryDebugBuffer");
    ntdll->push_function("RtlQueryProcessDebugInformation");
    ntdll->push_function("Wow64Transition");
    ntdll->push_function("NtAllocateVirtualMemory");
    ntdll->push_function("ZwCreateSection");
    ntdll->push_function("RtlWow64GetProcessMachines");
    ntdll->push_function("ZwWow64CallFunction64");
    ntdll->push_function("ZwTerminateThread");
    ntdll->push_function("RtlQueryProcessBackTraceInformation");
    ntdll->push_function("RtlQueryProcessLockInformation");
    ntdll->push_function("RtlQueryProcessHeapInformation");
    ntdll->push_function("NtQueryInformationThread");
    ntdll->push_function("ZwWaitForSingleObject");
    ntdll->push_function("memset");
    this->win_modules.insert(ntdll);

    win_module* kernel32 = new win_module("kernel32.dll");
    kernel32->push_function("BaseSetLastNTError");
    kernel32->push_function("ULongMult");
    this->win_modules.insert(kernel32);

    win_module* kernelbase = new win_module("kernelbase.dll");
    kernelbase->push_function("GetCurrentProcessId");
    this->win_modules.insert(kernelbase);

    for (auto& module : this->win_modules) {
        module->handle = this->get_module_handle(module->name.c_str());

        if (!module->handle) {
            continue;
        }

        for (auto& func : module->functions) {
            func->handle = this->get_proc_address(module->handle, func->name.c_str());

            if (win_api_debug) {
                std::cout << "[" << module->name << "] @ " << std::hex << module->handle << "  ->  [" << func->name << "] @ " << func->handle << std::endl;
            }
        }
    }

}













DWORD win_api::get_module_handle(const char* dllName) {
    void* PEB = 0,
        * Ldr = 0,
        * Flink = 0,
        * p = 0,
        * BaseAddress = 0;

    void* FullDllName = 0;

    __asm
    {
        mov eax, fs: [0x30]
        mov PEB, eax
    }
    Ldr = *((void**)((unsigned char*)PEB + 0x0c));
    Flink = *((void**)((unsigned char*)Ldr + 0x0c));
    p = Flink;
    do
    {
        BaseAddress = *((void**)((unsigned char*)p + 0x18));
        FullDllName = *((void**)((unsigned char*)p + 0x28));


        char cFullDllName[256];
        sprintf(cFullDllName, "%ws", FullDllName);
        //printf("%s\n", cFullDllName);


        if (strstr(utils::char_ptr_to_lower(cFullDllName), dllName)) {
            return (DWORD)BaseAddress;
        }

        p = *((void**)p);
    } while (Flink != p);
    return 0;
}

DWORD win_api::get_proc_address(DWORD hModule, const char* funcName) {
    auto pImageDOSHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(hModule);
    auto pImageNtHeader = reinterpret_cast<PIMAGE_NT_HEADERS32>(hModule + pImageDOSHeader->e_lfanew);
    auto pExport = reinterpret_cast<PIMAGE_DATA_DIRECTORY>(&pImageNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT]);
    auto pExports = reinterpret_cast<PIMAGE_EXPORT_DIRECTORY>(hModule + pExport->VirtualAddress);
    unsigned int* NameRVA = (unsigned int*)(hModule + pExports->AddressOfNames);

    for (int i = 0; i < pExports->NumberOfNames; i++) {
        char* name = (char*)(hModule + NameRVA[i]);
        //printf("%s\n", name);
        if (strstr(name, funcName)) {
            unsigned short NameOrdinal = ((unsigned short*)(hModule + pExports->AddressOfNameOrdinals))[i];
            DWORD addr = ((DWORD*)(hModule + pExports->AddressOfFunctions))[NameOrdinal];
            return (DWORD)(hModule + addr);
        }

    }

    return 0;
}


DWORD win_api::get_api_func_handle(const std::string& dll_module, const std::string& func_name) {
    
    if (win_api_debug) {
    std::cout << "get_api_func_handle called" << std::endl;
    }

    for (auto& module : this->win_modules) {
        if (module->name != dll_module) {
            continue;
        }

        for (auto& func : module->functions) {
            if (func->name != func_name) {
                continue;
            }

            return func->handle;
        }
    }

    return 0x0;
}

DWORD win_api::get_proc_id_by_name(const std::string& name) {
    std::istringstream f(utils::exec_cmd("tasklist"));
    std::string line;
    while (std::getline(f, line)) {
        if (line.find(name) != std::string::npos) {
            std::string str_res = "";
            std::regex reg(" [0-9][0-9]+ ");
            std::smatch reg_res;
            if (std::regex_search(line, reg_res, reg)) {
                str_res += reg_res[0];
                std::string trimmd = "";
                for (auto& c : str_res) {
                    if (c != ' ') {
                        trimmd += c;
                    }
                }

                DWORD result = atoi(trimmd.c_str());
                return result;
            }
        }
    }
    return 0;
}

DWORD win_api::open_process(DWORD procID) {
    static DWORD hNtOpenProcess = this->get_api_func_handle("ntdll.dll", "NtOpenProcess");

    if (!hNtOpenProcess) {
        std::cout << "!hNtOpenProcess" << std::endl;
        return 0;
    }

    //DWORD DesiredAccess = MAXIMUM_ALLOWED;
    OBJECT_ATTRIBUTES* pOA = new OBJECT_ATTRIBUTES();
    InitializeObjectAttributes(pOA, NULL, OBJ_KERNEL_HANDLE, NULL, NULL);
    CLIENT_ID* pCI = new CLIENT_ID();
    pCI->UniqueProcess = reinterpret_cast<void*>(procID);
    pCI->UniqueThread = NULL;


    DWORD hHandle = 0;
    auto open_status = wrappers::nt_open_process(hNtOpenProcess, &hHandle, MAXIMUM_ALLOWED, pOA, pCI);
    /*
    std::cout << "open status: " << std::hex << open_status << std::endl;
    std::cout << "hHandle: " << std::hex << hHandle << std::endl;
    */
    return hHandle;
}

DWORD win_api::close_handle(void* handle) {
    if (!handle) {
        return 0xcc;
    }
    static DWORD hNtClose = this->get_api_func_handle("ntdll.dll", "NtClose");

    return wrappers::nt_close(hNtClose, handle);
}

void win_api::read_process_memory(DWORD pHandle, DWORD BaseAddress, void* buffer, DWORD bytes_to_read, DWORD* bytes_readed) {
    static DWORD hNtReadVirutalMemory = this->get_api_func_handle("ntdll.dll", "NtReadVirtualMemory");

    /*
    std::cout << "hNtReadVirutalMemory : " << std::hex << hNtReadVirutalMemory << std::endl;
    */

    if (!hNtReadVirutalMemory) {
        return;
    }

    wrappers::nt_read_virtual_memory(hNtReadVirutalMemory, pHandle, BaseAddress, buffer, bytes_to_read, bytes_readed);
}

DWORD win_api::rtl_get_debug_info(ULONG ProcessId, ULONG DebugInfoClassMask, PDEBUG_BUFFER  DebugBuffer) {
    static DWORD hRtlQueryProcessDebugInformation = this->get_api_func_handle("ntdll.dll", "RtlQueryProcessDebugInformation");

    if (!hRtlQueryProcessDebugInformation) {
        return 0x0;
    }

    return wrappers::rtl_get_buffer(hRtlQueryProcessDebugInformation, ProcessId, DebugInfoClassMask, DebugBuffer);
}


PDEBUG_BUFFER win_api::rtl_create_buffer(ULONG Size, BOOLEAN EventPair) {
    static DWORD hRtlCreateQueryDebugBuffer = this->get_api_func_handle("ntdll.dll", "RtlCreateQueryDebugBuffer");

    if (!hRtlCreateQueryDebugBuffer) {
        return (PDEBUG_BUFFER)0x0;
    }

    return (PDEBUG_BUFFER)wrappers::rtl_create_buffer(hRtlCreateQueryDebugBuffer, Size, EventPair);
}
DWORD win_api::rtl_destroy_buffer(PDEBUG_BUFFER DebugBuffer) {
    static DWORD hRtlDestroyQueryDebugBuffer = this->get_api_func_handle("ntdll.dll", "RtlDestroyQueryDebugBuffer");

    if (!hRtlDestroyQueryDebugBuffer) {
        return 0x0;
    }

    return wrappers::rtl_destroy_buffer(hRtlDestroyQueryDebugBuffer, DebugBuffer);
}