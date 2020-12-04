#pragma once

#define win_api_debug true

#if defined(_WIN64)
 typedef unsigned __int64 ULONG_PTR;
#else
 typedef unsigned long ULONG_PTR;
#endif


typedef unsigned long       DWORD;
typedef unsigned short       WORD;
typedef unsigned char        BYTE;
typedef wchar_t              WCHAR;
using PVOID = void*;
typedef PVOID HANDLE;
typedef unsigned long ULONG;
typedef BYTE BOOLEAN;
typedef char CHAR;
typedef unsigned short USHORT;
typedef ULONG_PTR SIZE_T;




#define OBJ_INHERIT                         0x00000002L
#define OBJ_PERMANENT                       0x00000010L
#define OBJ_EXCLUSIVE                       0x00000020L
#define OBJ_CASE_INSENSITIVE                0x00000040L
#define OBJ_OPENIF                          0x00000080L
#define OBJ_OPENLINK                        0x00000100L
#define OBJ_KERNEL_HANDLE                   0x00000200L
#define OBJ_FORCE_ACCESS_CHECK              0x00000400L
#define OBJ_IGNORE_IMPERSONATED_DEVICEMAP   0x00000800L
#define OBJ_DONT_REPARSE                    0x00001000L
#define OBJ_VALID_ATTRIBUTES                0x00001FF2L

#define MAXIMUM_ALLOWED                  (0x02000000L)
#define DELETE 0x00010000


#define IMAGE_DIRECTORY_ENTRY_EXPORT          0   // Export Directory
#define IMAGE_DIRECTORY_ENTRY_IMPORT          1   // Import Directory
#define IMAGE_DIRECTORY_ENTRY_RESOURCE        2   // Resource Directory
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION       3   // Exception Directory
#define IMAGE_DIRECTORY_ENTRY_SECURITY        4   // Security Directory
#define IMAGE_DIRECTORY_ENTRY_BASERELOC       5   // Base Relocation Table
#define IMAGE_DIRECTORY_ENTRY_DEBUG           6   // Debug Directory
//      IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7   // (X86 usage)
#define IMAGE_DIRECTORY_ENTRY_ARCHITECTURE    7   // Architecture Specific Data
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR       8   // RVA of GP
#define IMAGE_DIRECTORY_ENTRY_TLS             9   // TLS Directory
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    10   // Load Configuration Directory
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   11   // Bound Import Directory in headers
#define IMAGE_DIRECTORY_ENTRY_IAT            12   // Import Address Table
#define IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   13   // Delay Load Import Descriptors
#define IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14   // COM Runtime descriptor

typedef struct _IMAGE_DOS_HEADER {      // DOS .EXE header
    unsigned short   e_magic;                     // Magic number
    unsigned short   e_cblp;                      // Bytes on last page of file
    unsigned short   e_cp;                        // Pages in file
    unsigned short   e_crlc;                      // Relocations
    unsigned short   e_cparhdr;                   // Size of header in paragraphs
    unsigned short   e_minalloc;                  // Minimum extra paragraphs needed
    unsigned short   e_maxalloc;                  // Maximum extra paragraphs needed
    unsigned short   e_ss;                        // Initial (relative) SS value
    unsigned short   e_sp;                        // Initial SP value
    unsigned short   e_csum;                      // Checksum
    unsigned short   e_ip;                        // Initial IP value
    unsigned short   e_cs;                        // Initial (relative) CS value
    unsigned short   e_lfarlc;                    // File address of relocation table
    unsigned short   e_ovno;                      // Overlay number
    unsigned short   e_res[4];                    // Reserved words
    unsigned short   e_oemid;                     // OEM identifier (for e_oeminfo)
    unsigned short   e_oeminfo;                   // OEM information; e_oemid specific
    unsigned short   e_res2[10];                  // Reserved words
    long   e_lfanew;                    // File address of new exe header
} IMAGE_DOS_HEADER, * PIMAGE_DOS_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, * PIMAGE_DATA_DIRECTORY;

typedef struct _IMAGE_OPTIONAL_HEADER {
    //
    // Standard fields.
    //

    unsigned short    Magic;
    unsigned char    MajorLinkerVersion;
    unsigned char    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
    DWORD   BaseOfData;

    //
    // NT additional fields.
    //

    DWORD   ImageBase;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    unsigned short    MajorOperatingSystemVersion;
    unsigned short    MinorOperatingSystemVersion;
    unsigned short    MajorImageVersion;
    unsigned short    MinorImageVersion;
    unsigned short    MajorSubsystemVersion;
    unsigned short    MinorSubsystemVersion;
    DWORD   Win32VersionValue;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    unsigned short    Subsystem;
    unsigned short    DllCharacteristics;
    DWORD   SizeOfStackReserve;
    DWORD   SizeOfStackCommit;
    DWORD   SizeOfHeapReserve;
    DWORD   SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER32, * PIMAGE_OPTIONAL_HEADER32;

typedef struct _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    NumberOfSections;
    DWORD   TimeDateStamp;
    DWORD   PointerToSymbolTable;
    DWORD   NumberOfSymbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, * PIMAGE_FILE_HEADER;

typedef struct _IMAGE_NT_HEADERS {
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
} IMAGE_NT_HEADERS32, * PIMAGE_NT_HEADERS32;

typedef struct _IMAGE_EXPORT_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   Name;
    DWORD   Base;
    DWORD   NumberOfFunctions;
    DWORD   NumberOfNames;
    DWORD   AddressOfFunctions;     // RVA from base of image
    DWORD   AddressOfNames;         // RVA from base of image
    DWORD   AddressOfNameOrdinals;  // RVA from base of image
} IMAGE_EXPORT_DIRECTORY, * PIMAGE_EXPORT_DIRECTORY;




















/* For open process as NtOpenProcess */

typedef struct _UNICODE_STRING {
    unsigned short Length;
    unsigned short MaximumLength;
    wchar_t*  Buffer;
} UNICODE_STRING;
typedef UNICODE_STRING* PUNICODE_STRING;

typedef struct _OBJECT_ATTRIBUTES {
    unsigned long Length;
    void* RootDirectory;
    PUNICODE_STRING ObjectName;
    unsigned long Attributes;
    void* SecurityDescriptor;
    void* SecurityQualityOfService;
} OBJECT_ATTRIBUTES;
typedef OBJECT_ATTRIBUTES* POBJECT_ATTRIBUTES;

#ifndef InitializeObjectAttributes
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }
#endif

typedef struct _CLIENT_ID {
    void* UniqueProcess;
    void* UniqueThread;
} CLIENT_ID;

#define MAX_MODULE_NAME32 255
#define MAX_PATH          260

typedef struct tagMODULEENTRY32W
{
    DWORD   dwSize;
    DWORD   th32ModuleID;       // This module
    DWORD   th32ProcessID;      // owning process
    DWORD   GlblcntUsage;       // Global usage count on the module
    DWORD   ProccntUsage;       // Module usage count in th32ProcessID's context
    BYTE* modBaseAddr;        // Base address of module in th32ProcessID's context
    DWORD   modBaseSize;        // Size in bytes of module starting at modBaseAddr
    void*   hModule;            // The hModule of this module in th32ProcessID's context
    WCHAR   szModule[MAX_MODULE_NAME32 + 1];
    WCHAR   szExePath[MAX_PATH];
} MODULEENTRY32W;





typedef struct _DEBUG_BUFFER {
    HANDLE  SectionHandle;
    PVOID  SectionBase;
    PVOID  RemoteSectionBase;
    ULONG  SectionBaseDelta;
    HANDLE  EventPairHandle;
    ULONG  Unknown[2];
    HANDLE  RemoteThreadHandle;
    ULONG  InfoClassMask;
    ULONG  SizeOfInfo;
    ULONG  AllocatedSize;
    ULONG  SectionSize;
    PVOID  ModuleInformation;
    PVOID  BackTraceInformation;
    PVOID  HeapInformation;
    PVOID  LockInformation;
    PVOID  Reserved[8];
} DEBUG_BUFFER, * PDEBUG_BUFFER;

typedef struct _DEBUG_MODULE_INFORMATION
{
    HANDLE Section;
    PVOID MappedBase;
    PVOID ImageBase;
    ULONG ImageSize;
    ULONG ImageFlags;
    USHORT LoadOrderIndex;
    USHORT InitOrderIndex;
    USHORT LoadCount;
    USHORT ModuleNameOffset;
    CHAR ImageName[256];
} DEBUG_MODULE_INFORMATION, * PDEBUG_MODULE_INFORMATION;

// Changed name in version 2.05 because of a bug.
typedef struct _DEBUG_MODULES_STRUCT
{
    ULONG Count;
    DEBUG_MODULE_INFORMATION DbgModInfo[1];
} DEBUG_MODULES_STRUCT, * PDEBUG_MODULES_STRUCT;


#define PDI_MODULES                       0x01
#define PDI_BACKTRACE                     0x02
#define PDI_HEAPS                         0x04
#define PDI_HEAP_TAGS                     0x08
#define PDI_HEAP_BLOCKS                   0x10
#define PDI_LOCKS                         0x20