#include "CardFour.h"

#include <fstream>
CardFour::CardFour(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number( 4 here)
}


void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	pPlayer->setPrevent();
	Card::Apply (pGrid, pPlayer);

	Output * Out = pGrid -> GetOutput();
	Input * In = pGrid -> GetInput();
	Out -> PrintMessage("This player is now prevented|| Click to continue ..");
	int x,y;
	In -> GetPointClicked(x,y);
	Out -> ClearStatusBar();


}
void CardFour::ReadCardParameters(Grid * pGrid)
{

}
void CardFour ::  Save(ofstream &OutFile ,int type){
	if (type ==2 ){
		OutFile<<cardNumber<<" ";
		Card ::Save(OutFile,2);
	}
}
void CardFour::Load(ifstream &infile,Grid*pGrid)
{

	Card::Load( infile,pGrid);
	pGrid->AddObjectToCell(this);
}