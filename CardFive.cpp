#include "CardFive.h"
#include <fstream>

CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}



CardFive::~CardFive(void)
{
}
void CardFive:: Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply (pGrid, pPlayer);

	Output * Out = pGrid -> GetOutput();
	Input * In = pGrid -> GetInput();
	Out -> PrintMessage("Card 5 gives the player an extra dice roll. || Click to continue ..");
	int x,y;
	In -> GetPointClicked(x,y);
	Out -> ClearStatusBar();

	pGrid->GetCurrentPlayer() -> Move (pGrid , - pPlayer -> getjustRolledDiceNum());

}
void CardFive::ReadCardParameters(Grid * pGrid)
{

}
void CardFive ::  Save(ofstream &OutFile ,int type){
	if (type ==2 ){
		OutFile<<cardNumber<<" ";
		Card ::Save(OutFile,2);
	}
}
void CardFive::Load(ifstream &infile,Grid*pGrid){
	
		Card::Load( infile,pGrid);
	pGrid->AddObjectToCell(this);
}