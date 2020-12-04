#pragma once

#include <iostream>
#include "utils.h"
//wrappers include winapi_defines.h
#include "wrappers.h"
#include <set>


struct win_module_func {
    std::string name;
    DWORD handle;

    inline win_module_func(const std::string& name) {
        this->name = name;
    }

    inline bool operator == (const win_module_func& rhs)
    {
        return this->name == rhs.name;
    }
};

struct win_module {
    std::string name;
    DWORD handle;
    std::set<win_module_func*> functions;

    inline win_module(const std::string& name) {
        this->name = name;
    }

    inline void push_function(win_module_func* func) {
        this->functions.insert(func);
    }

    inline void push_function(const std::string& func_name) {
        this->functions.insert(new win_module_func(func_name));
    }

    inline bool operator == (const win_module& rhs)
    {
        return this->name == rhs.name;
    }
};


class win_api
{
public:
    static win_api* get()
    {
        static win_api    instance; // Guaranteed to be destroyed.
                              // Instantiated on first use.
        return &instance;
    }
private:
    std::set<win_module*> win_modules;

    win_api() {}                    // Constructor? (the {} brackets) are needed here.

public:

    void initialize();

    DWORD get_module_handle(const char* dllName);
    DWORD get_proc_address(DWORD hModule, const char* funcName);
    DWORD get_api_func_handle(const std::string& dll_module, const std::string& func_name);
    DWORD get_proc_id_by_name(const std::string& name);
    DWORD rtl_get_debug_info(ULONG ProcessId, ULONG DebugInfoClassMask, PDEBUG_BUFFER  DebugBuffer);
    PDEBUG_BUFFER rtl_create_buffer(ULONG Size, BOOLEAN EventPair);
    DWORD rtl_destroy_buffer(PDEBUG_BUFFER DebugBuffer);
    DWORD open_process(DWORD procID);
    DWORD close_handle(void* handle);
    void read_process_memory(DWORD pHandle, DWORD BaseAddress, void* buffer, DWORD bytes_to_read, DWORD* bytes_readed = 0x0);
};

