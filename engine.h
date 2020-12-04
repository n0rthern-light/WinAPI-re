//#pragma once
//
//#include "WinApiReversed.h"
//
//struct ModuleEntry {
//    std::string name;
//    DWORD baseAddress;
//
//    inline ModuleEntry(const MODULEENTRY32W& mod) {
//        char string[256];
//        sprintf(string, "%ls", mod.szModule);
//        this->name = std::string(string);
//        this->baseAddress = (DWORD)mod.modBaseAddr;
//        if (win_api_debug) {
//        std::cout << "[MODULE = " << this->name << "] -> " << std::hex << this->baseAddress << std::endl;
//        }
//    }
//};
//
//struct ProcEntry {
//    std::string name;
//    DWORD proc_id;
//    DWORD h_proc;
//    std::set<ModuleEntry*> p_modules;
//
//    inline ProcEntry(const std::string& name) {
//        this->name = name;
//        proc_id = win_api::get()->get_proc_id_by_name(name);
//        h_proc = win_api::get()->open_process(proc_id);
//        void* h_snap = win_api::get()->create_toolhelp_32_snapshot(0x00000008, proc_id);
//        MODULEENTRY32W ModEntry;
//        ModEntry.dwSize = sizeof(MODULEENTRY32W);
//        if (win_api::get()->module32_first_w(h_snap, &ModEntry)) {
//            this->p_modules.insert(new ModuleEntry(ModEntry));
//        }
//        while (win_api::get()->module32_next_w(h_snap, &ModEntry)) {
//            this->p_modules.insert(new ModuleEntry(ModEntry));
//        }
//        win_api::get()->close_handle(h_snap);
//        if (win_api_debug) {
//        std::cout << "[PROCESS = " << this->name << "]" << std::endl;
//        }
//    }
//};
//
//
//class engine
//{
//public:
//    static engine* get()
//    {
//        static engine    instance; // Guaranteed to be destroyed.
//                              // Instantiated on first use.
//        return &instance;
//    }
//private:
//    std::set<ProcEntry*> p_procs;
//
//    engine() {}                    // Constructor? (the {} brackets) are needed here.
//
//public:
//    ProcEntry* init_proc(const std::string& name);
//    ProcEntry* get_proc_entry(const std::string& name);
//    ModuleEntry* get_module_entry(const std::string& proc, const std::string& module_name);
//    ModuleEntry* get_module_entry(ProcEntry* proc, const std::string& module_name);
//};