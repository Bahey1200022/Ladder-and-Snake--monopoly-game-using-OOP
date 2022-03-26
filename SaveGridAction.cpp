
#include "SaveGridAction.h"
#include "Grid.h"
#include "GameObject.h"
#include <fstream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void SaveGridAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Save Grid: Enter File Name ...");
	FileName = pIn->GetSrting(pOut);

	// Clear messages
	pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	// We get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid(); 
	// declare an object of ofstream and open the file for writing in it
	ofstream SaveFile(FileName + ".txt", ios::out);
	pGrid->SetNums();
	SaveFile<<pGrid->GetNumLadder()<<endl;
	pGrid->SaveAll(SaveFile,0);
	/*SaveFile<<pGrid->GetNumSnakes()<<endl;
	pGrid->SaveAll(SaveFile,1);*/ //snake error
	SaveFile<<pGrid->GetNumCards()<<endl;
	pGrid->SaveAll(SaveFile,2);
	SaveFile.close();
}

SaveGridAction::~SaveGridAction(){}