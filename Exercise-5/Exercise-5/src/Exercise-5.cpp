// Exercise-5.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "dbents.h"
#include "arxHeaders.h"


static void makeLayer()
{
	// Open the Layer table for read
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbLayerTable* pLayerTable;
	pDb->getLayerTable(pLayerTable, AcDb::kForRead);
	// Check to see if the layer exists
	if (pLayerTable->has(_T("OBJ")) == false)
	{
		// Open the Layer table for write
		pLayerTable->upgradeOpen();
		// Create the new layer and assign it the name 'OBJ'
		AcDbLayerTableRecord* pLayerTableRecord =
			new AcDbLayerTableRecord();
		pLayerTableRecord->setName(_T("OBJ"));
		// Set the color of the layer to cyan
		AcCmColor color;
		color.setColorIndex(4);
		pLayerTableRecord->setColor(color);
		// Add the new layer to the Layer table
		pLayerTable->add(pLayerTableRecord);
		// Close the Layer table and record
		pLayerTable->close();
		pLayerTableRecord->close();
	}
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
		acedRegCmds->addCommand(_T("AUCommands"), _T("MakeLayer"),
				                _T("MakeLayer"), ACRX_CMD_MODAL, makeLayer);
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
