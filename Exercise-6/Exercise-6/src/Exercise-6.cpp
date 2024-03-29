// Exercise-6.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "dbents.h"
#include "arxHeaders.h"

static void listObjects()
{
	// Get the current database
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	// Get the current space object
	AcDbBlockTableRecord* pBlockTableRecord;
	Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord,
		pDb->currentSpaceId(),
		AcDb::kForRead);
	// Create a new block iterator that will be used to
	// step through each object in the current space
	AcDbBlockTableRecordIterator* pItr;
	pBlockTableRecord->newIterator(pItr);
	// Create a variable AcDbEntity type which is a generic 
	// object to represent a Line, Circle, Arc, among other objects
	AcDbEntity* pEnt;
	// Step through each object in the current space
	for (pItr->start(); !pItr->done(); pItr->step())
	{
		// Get the entity and open it for read
		pItr->getEntity(pEnt, AcDb::kForRead);
		// Display the class name for the entity before
		// closing the object
		acutPrintf(_T("\nClass name: %s"), pEnt->isA()->name());
		pEnt->close();
	}
	// Close the current space object
	pBlockTableRecord->close();
	// Remove the block iterator object from memory
	delete pItr;
	// Display the AutoCAD Text Window
	acedTextScr();
}

extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt)
{
	switch (Msg)
	{
	case AcRx::kInitAppMsg:
		acrxUnlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		acutPrintf(L"\n Command Loaded");
		acedRegCmds->addCommand(_T("AUCommands"), _T("ListObjects"),
                      			_T("ListObjects"), ACRX_CMD_MODAL, listObjects);
		break;

	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading createLine project...\n"));
		// Command Groups to remove
		acedRegCmds->removeGroup(_T("AUCommnds"));
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}

