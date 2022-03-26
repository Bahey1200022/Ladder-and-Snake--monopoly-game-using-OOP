#include "CopyCardAction.h"

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

CopyCardAction::CopyCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters() 
{	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	// 2- Read the "cardPosition" parameter (its cell position) and set its data member

	pOut->PrintMessage("click on the source cell");	    //asking the user to click on the cell to copy the card and setting member cardPosition to it
	cardPosition = pIn->GetCellClicked();          //Save the position of the card
	// Clear messages
	pOut->ClearStatusBar();

}


void CopyCardAction::Execute() 
{

	// The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	//  We get a pointer to the Grid from the ApplicationManager

	Grid* pGrid=pManager->GetGrid();		//using class Grid to declare input and output pointers and to set the clipboard
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pCard=pGrid->GetCard(cardPosition);
	pGrid->SetClipboard(pCard);
	if(cardPosition.IsValidCell()) //check if the selected cell is on the grid
	{
		if(pGrid->GetClipboard()==NULL) //check if the selected cell includes a card or not
		{
			pGrid->PrintErrorMessage("there is no card in this cell.Click to continue..");

		}
		else
		{
			pGrid->PrintErrorMessage("Copied successfully. Click to continue..");
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
