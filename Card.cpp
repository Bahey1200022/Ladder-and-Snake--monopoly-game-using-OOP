#include "Card.h"
#include<fstream>

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	//  validation
	if (cnum >=1 && cnum<=12) cardNumber=cnum;
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card ::setpos( CellPosition & pos)
{
	position =pos;}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position,cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click
	Input *inp=pGrid->GetInput();
	Output*out=pGrid->GetOutput();
	int a,b;

	out->PrintMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
	inp->GetPointClicked(a,b);
	out->ClearStatusBar();
}


void Card ::Save(ofstream &Outfile,int type){
	if (type ==2)
		Outfile << position.GetCellNum()<<" ";
	//saving the cell numberand  in an output file 
}

void Card :: Load(ifstream &infile,Grid*pGrid ){
	
	
		int pos;
		infile >> pos;//setting from the input file the card number and pos of the card.
		position=CellPosition(pos);
	pGrid->AddObjectToCell(this);
}
Card::~Card()
{
}