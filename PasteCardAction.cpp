#include "PasteCardAction.h"
#include "AddCardAction.h"
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


PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters() 
{	
	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid=pManager->GetGrid();		//using class Grid to declare input and output pointers
	Input* pIn=pGrid->GetInput();
	Output* pOut=pGrid->GetOutput();
	// Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage( "Select the cell you want to paste the card to.."); //asking the user to click on the cell to place the card and setting member cardPosition to it
	cardPosition=pIn->GetCellClicked();
	// Clear messages
	pOut->ClearStatusBar();
}


void PasteCardAction::Execute()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters(); //to adjust cardcell
	pCard=pGrid->GetClipboard();
	if(pCard) //check if there is another object on this cell or not 
	{
		int cardNumber=pCard->GetCardNumber();

		switch (cardNumber) 
		{
		case 1: pCard = new CardOne(cardPosition); break;
		case 2: pCard = new CardTwo(cardPosition); break;
		case 3: pCard = new CardThree(cardPosition); break;
		case 4: pCard = new CardFour(cardPosition); break;
		case 5: pCard = new CardFive(cardPosition); break;	 
		case 6: pCard = new CardSix(cardPosition); break;
		case 7: pCard = new CardSeven(cardPosition); break;
		case 8: pCard = new CardEight(cardPosition); break;
		case 9: pCard = new CardNine(cardPosition); break;
		case 10: pCard = new CardTen(cardPosition); break;
		case 11: pCard = new CardEleven(cardPosition); break;
		/*case 12: pCard = new CardTwelve(cardPosition); break;*/
		}
	}
	else
	{
		pGrid->PrintErrorMessage("There is no card copied or cut");
		return;
	}
	if(cardPosition.IsValidCell()) //check if the click was on cell inside the grid
	{
		if(pCard) //double check
		{
			bool add= (pGrid-> AddObjectToCell(pCard));
			if (add) 
				pCard->Draw(pOut);
			pOut->ClearStatusBar();
		}
		else
		{
			pGrid->PrintErrorMessage("card Can't be added. Click to continue..");
			pOut->ClearStatusBar();
			return;
		}
	}
}