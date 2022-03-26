#include "CardThree.h"
#include <fstream>

CardThree::CardThree(const CellPosition & pos) :Card( pos)
{
	cardNumber=3;
}


CardThree::~CardThree(void)
{
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply (pGrid, pPlayer);

	Output * Out = pGrid -> GetOutput();
	Input * In = pGrid -> GetInput();
	Out -> PrintMessage("Card3 gives the player an extra dice roll|| Click to continue ..");
	int x,y;
	In -> GetPointClicked(x,y);
	Out -> ClearStatusBar();
	pGrid->setcurrPlayerNumber(pGrid->getCurrPlayerNumber()-1);


}
void CardThree::ReadCardParameters(Grid * pGrid)
{

}
void CardThree ::  Save(ofstream &OutFile ,int type){
	if (type ==2 ){
		OutFile<<cardNumber<<" ";
		Card ::Save(OutFile,2);
	}
}
void CardThree::Load(ifstream &infile,Grid*pGrid){

	
	Card::Load( infile,pGrid);
	pGrid->AddObjectToCell(this);
}