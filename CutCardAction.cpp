#include "CutCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"                
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"


CutCardAction::CutCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters() 
{	

	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid=pManager->GetGrid();		
	Input* pIn=pGrid->GetInput();
	Output* pOut=pGrid->GetOutput();

	// Read the PostionToDelete parameter
	pOut->PrintMessage("Cut Card: Click on its Cell ...");
	cardPosition= pIn->GetCellClicked();

	// Clear messages
	pOut->ClearStatusBar();

}

void CutCardAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	// get a pointer to the Grid from the ApplicationManager

	Grid* pGrid=pManager->GetGrid();		//using class Grid to set the clipboard
	Output* pOut=pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pCard=pGrid->GetCard(cardPosition);
	pGrid->SetClipboard(pCard);
	if(cardPosition.IsValidCell()) //check if the selected cell includes a card or not
	{
		if(pGrid->GetClipboard()==NULL)
		{
			pGrid->PrintErrorMessage("there is no card in this cell.Click to continue..");
		}
		else
		{
			pGrid->RemoveObjectFromCell(cardPosition);
			pGrid->UpdateInterface(); // Update interface with the changes 
			pGrid->PrintErrorMessage("cut successfully. Click to continue..");
			//by this line , the card is added to clickboard
		}
	}
	else
	{
		pOut->PrintMessage("invalid cell");
		return;
	}
	pOut->ClearStatusBar();
}


