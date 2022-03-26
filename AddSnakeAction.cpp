#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	Accept=true;
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();



	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	

	///TODO: Make the needed validations on the read parameters
if (startPos.IsValidCell()==false)
	{
	pOut->PrintMessage("The operation is cancelled : Invalid cell");
	Accept=false;	
	return;
	}
	if (endPos.IsValidCell() == false)                   
	{
		pOut->PrintMessage("The operation is cancelled : Invalid cell");
		
	Accept=false;	
		
		return;
	}
			if(startPos.HCell() != endPos.HCell() )
	{
		pGrid->PrintErrorMessage("The operation is cancelled : end cell and start cell are not in the same column");
	Accept=false;	
		
		return;
	}
	if (startPos.VCell() > endPos.VCell())
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

	/*if (pGrid->OverlappingSnakes(startPos,endPos) == 1)
	{
	pOut->PrintMessage("Two Snakes cannot overlap");
     	return ;*/
	
		// Clear messages
	pOut->ClearStatusBar();
	//pGrid->UpdateInterface();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if(Accept==true)
	// Create a Snake object with the parameters read from the user
	{
		Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	// Ad
	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction
	}
}