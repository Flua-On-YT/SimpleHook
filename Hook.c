#Include "Hook.h"

bool HookFunction(void* OriginalFunctionAddress, void* HookAddress)
{
  HANDLE CurrentProcessHandle = GetCurrentProcess();
  SIZE_T BytesWritten;
  char Patch[5] = {};
  memcpy_s(Patch, 1, "\xe9", 1);
  memcpy_s(Patch + 1, 4, &HookAddress, 4);

  WriteProcessMemory(CurrentProcessHandle, (LPVOID)(OriginalFunctionAddress), Patch, sizeof(Patch), &BytesWritten);
}
