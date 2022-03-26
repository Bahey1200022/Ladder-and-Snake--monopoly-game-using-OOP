
#include "OpenGridAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
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
#include <fstream>

OpenGridAction::OpenGridAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

OpenGridAction::~OpenGridAction()
{
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut ->PrintMessage("Enter the name of saved file:");
	FileName = pIn ->GetSrting(pOut);
	pOut ->ClearStatusBar();
}

void OpenGridAction::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();

	ifstream InFile(FileName + ".txt");

	if (!InFile){
		pGrid->PrintErrorMessage("ERROR: This File does not exist! Click to continue ... ");
		return;
	}

	int nrOfLadders;
	InFile >> nrOfLadders;
	Ladder*NLadder;

	for (int i = 0; i < nrOfLadders; i++)
		NLadder->Load(InFile,pGrid);

	//int numofsnakes;
//	InFile >> numofsnakes;
	//Snake*Nsnake;
	//if(numofsnakes==0)
	//{
	//}
	//else
	//{
	//for(int i=0 ;i<numofsnakes;i++)
	//	Nsnake->Load(InFile,pGrid);
	//}
	int numofcards;
	InFile>>numofcards;
	CardOne *c1;
	CardTwo *c2;
	for(int i=0;i<numofcards;i++)
	{
		int cardnumber;
		InFile>>cardnumber;
		if(cardnumber==1)
		{
			
			c1->Load(InFile,pGrid);
		}
		else if(cardnumber==2)
		{
			
			c2->Load(InFile,pGrid);
		}
		else if(cardnumber==3)
		{
			CardThree *c;
			c->Load(InFile,pGrid);
		}
		else if(cardnumber==4)
		{
			CardFour *c;
			c->Load(InFile,pGrid);
		}
		else if(cardnumber==5)
		{
			CardFive *c;
			c->Load(InFile,pGrid);
		}
		else if(cardnumber==6)
		{
			CardSix *c;
			c->Load(InFile,pGrid);
		}
		else if(cardnumber==7)
		{
			CardSeven *c;
			c->Load(InFile,pGrid);
		}
		else if(cardnumber==8)
		{
			CardEight *c;
			c->Load(InFile,pGrid);

		}
		else if(cardnumber==9)
		{
			CardNine *c;
			c->Load(InFile,pGrid);
		}
		else if(cardnumber==10)
		{
			CardTen *c;
			c->Load(InFile,pGrid);
		}
		else if(cardnumber==11)
		{
			CardEleven *c;
			c->Load(InFile,pGrid);
		}
		else if(cardnumber==12)
		{
			CardTwelve *c;
			c->Load(InFile,pGrid);
		}
		

	}
	InFile.close();
}