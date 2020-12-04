#include "WinApiReversed.h"
#include <chrono>
#include <thread>

using namespace std;




int main() {
	//read_test_helper.exe

	win_api::get()->initialize();
	DWORD procid = win_api::get()->get_proc_id_by_name("csgo.exe");
	std::cout << std::dec << "procid: " << procid << std::endl;
	DWORD handle = win_api::get()->open_process(procid);
	std::cout << std::dec << "proc_handle: " << handle << std::endl;

	//PDEBUG_BUFFER buffer = win_api::get()->rtl_create_buffer(0, false);
	//DWORD result = win_api::get()->rtl_get_debug_info(procid, PDI_MODULES, buffer);

	//PDEBUG_MODULES_STRUCT modInfo = (PDEBUG_MODULES_STRUCT)buffer->ModuleInformation;
	//std::cout << modInfo->Count << std::endl;

	//for (int i = 0; i < modInfo->Count; ++i) {
	//	std::cout << "ImageBase : " << std::hex << "0x" << modInfo->DbgModInfo[i].ImageBase << std::endl;
	//	std::cout << "ImageSize : " << std::hex << "0x" << modInfo->DbgModInfo[i].ImageSize << std::endl;
	//}

	//DWORD destroy = win_api::get()->rtl_destroy_buffer(buffer);





	//ProcEntry* csgo = engine::get()->init_proc("csgo.exe");
	//ModuleEntry* client_dll = engine::get()->get_module_entry(csgo, "client.dll");

	//std::cout << std::hex << "c_mod: " << client_dll->name << " @ " << client_dll->baseAddress << std::endl;

/*

	for (;;) {
		char p_localplayer[55];
		win_api::get()->read_process_memory(csgo->h_proc, 0x24903214, &p_localplayer, sizeof(p_localplayer));

		std::cout << std::dec << "me: " << p_localplayer << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
*/
    getchar();


	return 0;
}