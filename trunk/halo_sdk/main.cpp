#include "main.h"
#include "Engine/objects.h"
#include "Debug/debug.h"
#include "Direct3D9/d3d9hook.h"

int __stdcall hkMain(int argc, char* argv[])
{
	bool infinite_loop = true;

	//hkD3D9Hook();
	CObjects objects;

	while(infinite_loop)
	{
		if(GetAsyncKeyState(VK_F2)&1)
			objects.PrintObjectInfo();
		// Exit hkMain thread safely
		if(GetAsyncKeyState(VK_DELETE)&1)
			infinite_loop = false;

		Sleep(1);
	}
	return 0;
}

bool __stdcall DllMain(HMODULE hMod, unsigned long ulReason, void* pvReserved)
{
	switch(ulReason)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hMod);

			#ifdef HALODEBUG
			InitDebug(hMod);
			#endif

			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)hkMain, 0, 0, 0);
			break;

		case DLL_PROCESS_DETACH:

			#ifdef HALODEBUG
			ExitDebug();
			#endif

			break;

		case DLL_THREAD_ATTACH:
			break;

		case DLL_THREAD_DETACH:
			break;
	}

    return true;
}