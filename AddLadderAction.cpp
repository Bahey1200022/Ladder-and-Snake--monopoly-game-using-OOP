#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	Accept=true;
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

    

	///TODO: Make the needed validations on the read parameters
	              // Added this validation as in Phase 1 such as :cellposition 
		if(startPos.HCell() != endPos.HCell() )
	{
		pGrid->PrintErrorMessage("The operation is cancelled : end cell and start cell are not in the same column");
		Accept=false;
		return;
	}

	if (startPos.VCell() < endPos.VCell())
	{
	pGrid->PrintErrorMessage("The operation is cancelled :end cell cannot be smaller than start cell");
	Accept=false;
		return;
	}	
	if(startPos.HCell()==0 && startPos.VCell()== 8 )
	{
		pGrid->PrintErrorMessage("The operation is cancelled :start cell cannot be the first cell");
		Accept=false;
		return;

	}
		if(endPos.HCell()==10 && endPos.VCell()== 0 ) 
	{
	
		pGrid->PrintErrorMessage("The operation is cancelled :end cell cannot be the last cell");
Accept=false;
		return;
	}
		if (startPos.IsValidCell()==false)
	{
	pOut->PrintMessage("The operation is cancelled : Invalid cell");
	Accept=false;	
	return;
	}
	if (endPos.IsValidCell() == false)                    
	{
		pGrid->PrintErrorMessage("The operation is cancelled : invalid cell ");
		Accept=false;
		return;
	}
	if (startPos.VCell()==0)
	{
		pGrid->PrintErrorMessage("The operation is cancelled : Start cell cannot be the last row");
		Accept=false;	
		return;
	}
		if (pGrid->OverlappingLadders(startPos,endPos) == 1)
	{
	pGrid->PrintErrorMessage("Two Ladders cannot overlap");
     	return ;
	}
	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if(Accept==true)
	{
	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	
	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	}
}