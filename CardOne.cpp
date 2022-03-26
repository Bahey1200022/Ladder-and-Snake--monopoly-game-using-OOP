#include "CardOne.h"
#include <fstream>
CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{

	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input * In= pGrid -> GetInput();
	Output * Out = pGrid -> GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	Out -> PrintMessage ("New CardOne:   || Enter its wallet amount :");
	int check=In -> GetInteger(Out);
	if (check <0) check=0;
	walletAmount=check;
	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	Out -> ClearStatusBar();
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Card::Apply (pGrid, pPlayer);

	pPlayer -> SetWallet (pPlayer -> GetWallet() - walletAmount);
	Output * Out = pGrid -> GetOutput();
	Input * In = pGrid -> GetInput();

	Out -> PrintMessage("Your total wallet amount is now " + to_string (pPlayer -> GetWallet()) + " Coins || Click to continue ..");
	int x,y;
	In -> GetPointClicked(x,y);
	Out -> ClearStatusBar();
	
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

}
//save and load
void CardOne :: Save(ofstream &OutFile ,int type){
	if (type ==2 ){
		OutFile<<cardNumber<<" ";
		Card ::Save(OutFile,2);
		OutFile <<walletAmount<<endl;
	}
}
void CardOne::Load(ifstream &infile,Grid*pGrid)
{
	
		int  walletinput;
		Card::Load( infile,pGrid);
		infile>>walletinput;
		walletAmount=walletinput;
	pGrid->AddObjectToCell(this);
}