
#include "CardEight.h"

#include <fstream>
CardEight::CardEight(const CellPosition & pos):Card( pos)
{
	cardNumber=8;
}


CardEight::~CardEight(void)
{
}
void CardEight::ReadCardParameters(Grid * pGrid)
{
	Input * In= pGrid -> GetInput();
	Output * Out = pGrid -> GetOutput();

	Out -> PrintMessage ("New CardEight:   || the amount of coins needed to go out of the prison :");
	NeededAmount = In->GetInteger(Out);

	Out->PrintMessage("if you want to pay press 1 || prison press 0:");
	choice = In->GetInteger(Out);

	Out -> ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Player* currp = pGrid->GetCurrentPlayer();
	if (choice)
	{
		if(pPlayer->GetWallet()-NeededAmount<0)
			choice=false;
		else
			pPlayer->SetWallet(pPlayer->GetWallet()-NeededAmount);
	}
	if(!choice)
	{
		pPlayer->IamPrisoned();

	}
}
void CardEight::Save(ofstream &OutFile,int type){
	if (type ==2  ){
		OutFile <<cardNumber<<" ";
		Card :: Save(OutFile,2);
		OutFile<<NeededAmount;
	}
}
void CardEight::Load(ifstream &Infile,Grid*pGrid){
	
	
		int amount ;
		Card ::Load(Infile,pGrid);
		Infile>>amount;
		NeededAmount= amount ;
	pGrid->AddObjectToCell(this);
}


