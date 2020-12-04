//#include "engine.h"
//
//ProcEntry* engine::init_proc(const std::string& name) {
//	ProcEntry* new_pe = new ProcEntry(name);
//	this->p_procs.insert(new_pe);
//	return new_pe;
//}
//
//ProcEntry* engine::get_proc_entry(const std::string& name) {
//	for (auto& p_proc : this->p_procs) {
//		if (p_proc->name == name) {
//			return p_proc;
//		}
//	}
//	return nullptr;
//}
//
//ModuleEntry* engine::get_module_entry(const std::string& proc, const std::string& module_name) {
//	for (auto& p_proc : this->p_procs) {
//		if (p_proc->name == proc) {
//			for (auto& p_mod : p_proc->p_modules) {
//				if (p_mod->name == module_name) {
//					return p_mod;
//				}
//			}
//		}
//	}
//	return nullptr;
//}
//
//ModuleEntry* engine::get_module_entry(ProcEntry* proc, const std::string& module_name) {
//	if (!proc) {
//		return nullptr;
//	}
//
//	for (auto& p_mod : proc->p_modules) {
//		if (p_mod->name == module_name) {
//			return p_mod;
//		}
//	}
//
//	return nullptr;
//}