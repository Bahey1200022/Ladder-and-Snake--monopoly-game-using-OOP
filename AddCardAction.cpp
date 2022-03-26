#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include "CardTwelve.h"

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	//Done-Khaled

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Enter Card Number from 1 to 12:");
	int card; //the input card number
	card=pIn->GetInteger(pOut);
	if (card>=1 && card<=12)
		cardNumber=card;
	else
	{
		pGrid->PrintErrorMessage("invalid card , can not add this card");
		return;
	}

	pOut->PrintMessage("click on the cell");
	cardPosition = pIn->GetCellClicked();

	if (!cardPosition.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid cell Position");
		return;
	}
	pOut->ClearStatusBar();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces 



	// 2- Read the "cardNumber" parameter and set its data member

	// 3- Read the "cardPosition" parameter (its cell position) and set its data member

	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
}

void AddCardAction::Execute() 
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below \\Done by Khaled


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);
		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new CardSeven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
		break;
	case 9:
		pCard = new CardNine(cardPosition);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	/*case 12:
		pCard = new CardTwelve(cardPosition);
		break;*/
	}

		// A- Add the remaining cases



	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	// A- We get a pointer to the Grid from the ApplicationManager

	// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type

	// C- Add the card object to the GameObject of its Cell:

	// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

	if (pCard && cardPosition.IsValidCell())
	{
		pCard->ReadCardParameters(pGrid);

		if (!pGrid->AddObjectToCell(pCard))
		{
			pGrid->PrintErrorMessage("The Cell has another gameobject");
		}

	}



	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}