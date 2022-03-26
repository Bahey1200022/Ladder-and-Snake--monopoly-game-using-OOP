#include "CardTwo.h"
#include<fstream>
#include "Ladder.h"

CardTwo::CardTwo(const CellPosition & pos) : Card(pos)
{
	cardNumber = 2;
}
void  CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply (pGrid, pPlayer);
	Input * In= pGrid -> GetInput();
	Output * Out = pGrid -> GetOutput();
	Ladder * ladder = pGrid -> GetNextLadder (pPlayer->GetCell()->GetCellPosition().GetCellNum());
	if (ladder == NULL)
	{
		int x,y;
		Out -> PrintMessage ("No Ladder ahead...||Click to Continue ");
		In->GetPointClicked(x,y);
		Out ->ClearStatusBar();
	}
	else 
	{
		pGrid -> UpdatePlayerCell (pPlayer, ladder-> GetPosition());
	}
}void CardTwo ::  Save(ofstream &OutFile ,int type){
	if (type ==2 ){
		OutFile<<cardNumber<<" ";
		Card ::Save(OutFile,2);
	}
}
void CardTwo::Load(ifstream &infile,Grid*pGrid){
	//pGrid->AddObjectToCell(this);
	Card::Load( infile,pGrid);
	pGrid->AddObjectToCell(this);
	}
