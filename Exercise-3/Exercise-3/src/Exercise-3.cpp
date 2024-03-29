// Exercise-3.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "dbents.h"
#include "arxHeaders.h"

static void Greetings()
{
	acutPrintf(_T("\n Greetings function called!"));
}

extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(_T("\nLoading AU 2014 project...\n"));
		// Commands to add
		acedRegCmds->addCommand(_T("AUCommands"), _T("First"),
			_T("Uno"), ACRX_CMD_MODAL, Greetings);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading AU 2014 project...\n"));
		// Command Groups to remove
		acedRegCmds->removeGroup(_T("AUCommnds"));
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


