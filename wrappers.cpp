#include "wrappers.h"

DWORD security_cookie;













DWORD wrappers::h_memset;
DWORD wrappers::hNtMapViewSection;
DWORD wrappers::hRtlRestoreLastWin32Error;
DWORD wrappers::hNtUnmapViewOfSection;
DWORD wrappers::hBaseSetLastNTError;





/*CREATE TOOLHELP 32 SNAPSHOT */




__declspec(naked) /*void**/ void unwrapped_create_toolhelp_32_snapshot() {
    /*
    __asm {
        mov edi, edi
        push ebp
        mov ebp, esp
        push 0xFFFFFFFE
        push kernel32.77001B08
        push <kernel32.__except_handler4>
        mov eax, dword ptr fs : [0x0]
        push eax
        push ecx
        push ecx
        sub esp, 0x6C
        push ebx
        push esi
        push edi
        mov eax, dword ptr ds : [<___security_cookie>]
        xor dword ptr ss : [ebp - 0x8] , eax
        xor eax, ebp
        push eax
        lea eax, dword ptr ss : [ebp - 0x10]
        mov dword ptr fs : [0x0] , eax
        or dword ptr ss : [ebp - 0x54] , 0xFFFFFFFF
        or dword ptr ss : [ebp - 0x64] , 0xFFFFFFFF
        and dword ptr ss : [ebp - 0x34] , 0x0
        and dword ptr ss : [ebp - 0x5C] , 0x0
        and dword ptr ss : [ebp - 0x38] , 0x0
        and dword ptr ss : [ebp - 0x24] , 0x0
        and dword ptr ss : [ebp - 0x58] , 0x0
        and dword ptr ss : [ebp - 0x20] , 0x0
        and dword ptr ss : [ebp - 0x1C] , 0x0
        and dword ptr ss : [ebp - 0x4C] , 0x0
        and dword ptr ss : [ebp - 0x50] , 0x0
        and dword ptr ss : [ebp - 0x2C] , 0x0
        and dword ptr ss : [ebp - 0x28] , 0x0
        cmp dword ptr ss : [ebp + 0xC] , 0x0
        jne kernel32.76F95987
        call dword ptr ds : [<&GetCurrentProcessId>]
        mov dword ptr ss : [ebp + 0xC] , eax
        and dword ptr ss : [ebp - 0x4] , 0x0
        lea eax, dword ptr ss : [ebp - 0x40]
        push eax
        lea eax, dword ptr ss : [ebp - 0x1C]
        push eax
        lea eax, dword ptr ss : [ebp - 0x38]
        push eax
        lea eax, dword ptr ss : [ebp - 0x48]
        push eax
        lea eax, dword ptr ss : [ebp - 0x20]
        push eax
        lea eax, dword ptr ss : [ebp - 0x5C]
        push eax
        lea eax, dword ptr ss : [ebp - 0x34]
        push eax
        mov edx, dword ptr ss : [ebp + 0xC]
        mov ecx, dword ptr ss : [ebp + 0x8]
        call <kernel32._ThpCreateRawSnap@36>
        mov dword ptr ss : [ebp - 0x24] , eax
        cmp dword ptr ss : [ebp - 0x24] , 0x0
        jge kernel32.76F959C8
        push dword ptr ss : [ebp - 0x24]
        call <kernel32._BaseSetLastNTError@4>
        jmp kernel32.76F95C21
        cmp dword ptr ss : [ebp - 0x1C] , 0x0
        je kernel32.76F95AC2
        mov eax, dword ptr ss : [ebp - 0x38]
        mov eax, dword ptr ds : [eax + 0x38]
        mov dword ptr ss : [ebp - 0x28] , eax
        mov eax, dword ptr ss : [ebp - 0x1C]
        cmp eax, dword ptr ss : [ebp - 0x28]
        ja kernel32.76F95A12
        mov eax, dword ptr ss : [ebp - 0x28]
        add eax, 0x44
        cmp eax, dword ptr ss : [ebp - 0x28]
        jb kernel32.76F95A12
        mov eax, dword ptr ss : [ebp - 0x1C]
        add eax, dword ptr ss : [ebp - 0x40]
        cmp eax, dword ptr ss : [ebp - 0x1C]
        jb kernel32.76F95A12
        mov eax, dword ptr ss : [ebp - 0x28]
        add eax, 0x44
        mov ecx, dword ptr ss : [ebp - 0x1C]
        add ecx, dword ptr ss : [ebp - 0x40]
        cmp eax, ecx
        ja kernel32.76F95A12
        mov dword ptr ss : [ebp - 0x68] , 0x1
        jmp kernel32.76F95A16
        and dword ptr ss : [ebp - 0x68] , 0x0
        movzx eax, byte ptr ss : [ebp - 0x68]
        test eax, eax
        jne kernel32.76F95A2D
        push C000003E
        call <kernel32._BaseSetLastNTError@4>
        jmp kernel32.76F95C21
        mov eax, dword ptr ss : [ebp - 0x28]
        mov eax, dword ptr ds : [eax]
        mov dword ptr ss : [ebp - 0x4C] , eax
        cmp dword ptr ss : [ebp - 0x4C] , 0x1
        jbe kernel32.76F95AC2
        lea eax, dword ptr ss : [ebp - 0x30]
        push eax
        mov ecx, dword ptr ss : [ebp - 0x4C]
        dec ecx
        push 0x40
        pop edx
        call <kernel32._ULongMult@12>
        mov dword ptr ss : [ebp - 0x60] , eax
        cmp dword ptr ss : [ebp - 0x60] , 0x0
        jge kernel32.76F95A67
        push 0xC000003E
        call <kernel32._BaseSetLastNTError@4>
        jmp kernel32.76F95C21
        mov eax, dword ptr ss : [ebp - 0x28]
        add eax, 0x44
        mov dword ptr ss : [ebp - 0x3C] , eax
        mov eax, dword ptr ss : [ebp - 0x1C]
        cmp eax, dword ptr ss : [ebp - 0x3C]
        ja kernel32.76F95AA7
        mov eax, dword ptr ss : [ebp - 0x3C]
        add eax, dword ptr ss : [ebp - 0x30]
        cmp eax, dword ptr ss : [ebp - 0x3C]
        jb kernel32.76F95AA7
        mov eax, dword ptr ss : [ebp - 0x1C]
        add eax, dword ptr ss : [ebp - 0x40]
        cmp eax, dword ptr ss : [ebp - 0x1C]
        jb kernel32.76F95AA7
        mov eax, dword ptr ss : [ebp - 0x3C]
        add eax, dword ptr ss : [ebp - 0x30]
        mov ecx, dword ptr ss : [ebp - 0x1C]
        add ecx, dword ptr ss : [ebp - 0x40]
        cmp eax, ecx
        ja kernel32.76F95AA7
        mov dword ptr ss : [ebp - 0x6C] , 1
        jmp kernel32.76F95AAB
        and dword ptr ss : [ebp - 0x6C] , 0
        movzx eax, byte ptr ss : [ebp - 0x6C]
        test eax, eax
        jne kernel32.76F95AC2
        push C000003E
        call <kernel32._BaseSetLastNTError@4>
        jmp kernel32.76F95C21
        cmp dword ptr ss : [ebp - 0x20] , 0
        je kernel32.76F95BC1
        mov eax, dword ptr ss : [ebp - 0x5C]
        mov eax, dword ptr ds : [eax + 0x30]
        mov dword ptr ss : [ebp - 0x2C] , eax
        mov eax, dword ptr ss : [ebp - 0x20]
        cmp eax, dword ptr ss : [ebp - 0x2C]
        ja kernel32.76F95B10
        mov eax, dword ptr ss : [ebp - 0x2C]
        add eax, 0x120
        cmp eax, dword ptr ss : [ebp - 0x2C]
        jb kernel32.76F95B10
        mov eax, dword ptr ss : [ebp - 0x20]
        add eax, dword ptr ss : [ebp - 0x48]
        cmp eax, dword ptr ss : [ebp - 0x20]
        jb kernel32.76F95B10
        mov eax, dword ptr ss : [ebp - 0x2C]
        add eax, 0x120
        mov ecx, dword ptr ss : [ebp - 0x20]
        add ecx, dword ptr ss : [ebp - 0x48]
        cmp eax, ecx
        ja kernel32.76F95B10
        mov dword ptr ss : [ebp - 0x70] , 0x1
        jmp kernel32.76F95B14
        and dword ptr ss : [ebp - 0x70] , 0x0
        movzx eax, byte ptr ss : [ebp - 0x70]
        test eax, eax
        jne kernel32.76F95B2B
        push 0xC000003E
        call <kernel32._BaseSetLastNTError@4>
        jmp kernel32.76F95C21
        mov eax, dword ptr ss : [ebp - 0x2C]
        mov eax, dword ptr ds : [eax]
        mov dword ptr ss : [ebp - 0x50] , eax
        cmp dword ptr ss : [ebp - 0x50] , 0x1
        jbe kernel32.76F95BC1
        lea eax, dword ptr ss : [ebp - 0x30]
        push eax
        mov ecx, dword ptr ss : [ebp - 0x50]
        dec ecx
        mov edx, 0x120
        call <kernel32._ULongMult@12>
        mov dword ptr ss : [ebp - 0x60] , eax
        cmp dword ptr ss : [ebp - 0x60] , 0x0
        jge kernel32.76F95B67
        push 0xC000003E
        call <kernel32._BaseSetLastNTError@4>
        jmp kernel32.76F95C21
        mov eax, dword ptr ss : [ebp - 0x2C]
        add eax, 0x120
        mov dword ptr ss : [ebp - 0x44] , eax
        mov eax, dword ptr ss : [ebp - 0x20]
        cmp eax, dword ptr ss : [ebp - 0x44]
        ja kernel32.76F95BA9
        mov eax, dword ptr ss : [ebp - 0x44]
        add eax, dword ptr ss : [ebp - 0x30]
        cmp eax, dword ptr ss : [ebp - 0x44]
        jb kernel32.76F95BA9
        mov eax, dword ptr ss : [ebp - 0x20]
        add eax, dword ptr ss : [ebp - 0x48]
        cmp eax, dword ptr ss : [ebp - 0x20]
        jb kernel32.76F95BA9
        mov eax, dword ptr ss : [ebp - 0x44]
        add eax, dword ptr ss : [ebp - 0x30]
        mov ecx, dword ptr ss : [ebp - 0x20]
        add ecx, dword ptr ss : [ebp - 0x48]
        cmp eax, ecx
        ja kernel32.76F95BA9
        mov dword ptr ss : [ebp - 0x74] , 0x1
        jmp kernel32.76F95BAD
        and dword ptr ss : [ebp - 0x74] , 0x0
        movzx eax, byte ptr ss : [ebp - 0x74]
        test eax, eax
        jne kernel32.76F95BC1
        push C000003E
        call <kernel32._BaseSetLastNTError@4>
        jmp kernel32.76F95C21
        push dword ptr ss : [ebp - 0x4C]
        push dword ptr ss : [ebp - 0x50]
        push dword ptr ss : [ebp - 0x34]
        push dword ptr ss : [ebp + 0xC]
        push dword ptr ss : [ebp + 0x8]
        lea edx, dword ptr ss : [ebp - 0x58]
        lea ecx, dword ptr ss : [ebp - 0x54]
        call <kernel32._ThpAllocateSnapshotSection@28>
        mov dword ptr ss : [ebp - 0x24] , eax
        cmp dword ptr ss : [ebp - 0x24] , 0x0
        jge kernel32.76F95BEE
        push dword ptr ss : [ebp - 0x24]
        call <kernel32._BaseSetLastNTError@4>
        jmp kernel32.76F95C21
        push dword ptr ss : [ebp - 0x28]
        push dword ptr ss : [ebp - 0x38]
        push dword ptr ss : [ebp - 0x2C]
        push dword ptr ss : [ebp - 0x34]
        push dword ptr ss : [ebp - 0x58]
        mov edx, dword ptr ss : [ebp + 0xC]
        mov ecx, dword ptr ss : [ebp + 0x8]
        call <kernel32._ThpProcessToSnap@28>
        mov dword ptr ss : [ebp - 0x24] , eax
        cmp dword ptr ss : [ebp - 0x24] , 0x0
        jge kernel32.76F95C1B
        push dword ptr ss : [ebp - 0x24]
        call <kernel32._BaseSetLastNTError@4>
        jmp kernel32.76F95C21
        mov eax, dword ptr ss : [ebp - 0x54]
        mov dword ptr ss : [ebp - 0x64] , eax
        mov dword ptr ss : [ebp - 0x4] , 0xFFFFFFFE
        call kernel32.76F95C32
        jmp kernel32.76F95CCB
        mov eax, dword ptr ss : [ebp - 0x64]
        cmp eax, dword ptr ss : [ebp - 0x54]
        je kernel32.76F95C54
        push dword ptr ss : [ebp - 0x54]
        call dword ptr ds : [<&NtClose>]
        test eax, eax
        jl kernel32.76F95C50
        mov dword ptr ss : [ebp - 0x78] , 0x1
        jmp kernel32.76F95C54
        and dword ptr ss : [ebp - 0x78] , 0x0
        cmp dword ptr ss : [ebp - 0x58] , 0x0
        je kernel32.76F95C76
        push dword ptr ss : [ebp - 0x58]
        push 0xFFFFFFFF
        call dword ptr ds : [<&NtUnmapViewOfSection>]
        test eax, eax
        jl kernel32.76F95C72
        mov dword ptr ss : [ebp - 0x7C] , 0x1
        jmp kernel32.76F95C76
        and dword ptr ss : [ebp - 0x7C] , 0x0
        cmp dword ptr ss : [ebp - 0x34] , 0x0
        je kernel32.76F95CAC
        and dword ptr ss : [ebp - 0x80] , 0x0
        push 0x8000
        lea eax, dword ptr ss : [ebp - 0x80]
        push eax
        lea eax, dword ptr ss : [ebp - 0x34]
        push eax
        push 0xFFFFFFFF
        call dword ptr ds : [<&ZwFreeVirtualMemory>]
        test eax, eax
        jl kernel32.76F95CA5
        mov dword ptr ss : [ebp - 0x84] , 0x1
        jmp kernel32.76F95CAC
        and dword ptr ss : [ebp - 0x84] , 0x0
        cmp dword ptr ss : [ebp - 0x5C] , 0x0
        je kernel32.76F95CBB
        push dword ptr ss : [ebp - 0x5C]
        call dword ptr ds : [<&RtlDestroyQueryDebugBuffer>]
        cmp dword ptr ss : [ebp - 0x38] , 0x0
        je kernel32.76F95CCA
        push dword ptr ss : [ebp - 0x38]
        call dword ptr ds : [<&RtlDestroyQueryDebugBuffer>]
        ret
        mov eax, dword ptr ss : [ebp - 0x64]
        mov ecx, dword ptr ss : [ebp - 0x10]
        mov dword ptr fs : [0x0] , ecx
        pop ecx
        pop edi
        pop esi
        pop ebx
        leave
        ret 0x8
    }
    */
}

/*
void* wrappers::create_toolhelp_32_snapshot(

    ) {

}
*/