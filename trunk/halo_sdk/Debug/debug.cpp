#include "debug.h"

ofstream ofile;	
char dlldir[320];

char *GetDirectoryFile(char* filename)
{
	static char path[320];
	strcpy(path, dlldir);
	strcat(path, filename);
	return path;
}

void __cdecl DEBUG(const char* fmt, ...)
{
	if(ofile != NULL)
	{
		if(!fmt)
			return;

		va_list va_alist;
		char logbuf[256] = { 0 };

		va_start ( va_alist, fmt );
		_vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), fmt, va_alist);
		va_end (va_alist);

		ofile << logbuf << endl;
	}
}

void InitDebug(HMODULE hModule)
{
	GetModuleFileNameA(hModule, dlldir, 512);

	for(int i = (int)strlen(dlldir); i > 0; i--) 
	{ 
		if(dlldir[i] == '\\')
		{ 
			dlldir[i + 1] = 0; 
			break;  
		}
	}

	ofile.open(GetDirectoryFile(LOGNAME), ios::app);

	DEBUG( "*-*-*-*-*-*-*-*-*-*-*-*-*-*" );
	DEBUG( "halo_sdk injected"             );
	DEBUG( "*-*-*-*-*-*-*-*-*-*-*-*-*-*" );
}

void ExitDebug( )
{
	DEBUG( "*-*-*-*-*-*-*-*-*-*-*-*-*-*"   );
	DEBUG( "halo_sdk exited"                 );
	DEBUG( "*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" );
	ofile.close( );
}