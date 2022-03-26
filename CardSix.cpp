#include "CardSix.h"
#include <fstream>

CardSix::CardSix(const CellPosition & pos):Card(pos)
{
	cardNumber = 6;
}


CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid * pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input * In= pGrid -> GetInput();
	Output * Out = pGrid -> GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it

	int ans=0;
	while (ans==0)
	{
		Out -> PrintMessage ("New Card6:   || CellNum you want to go to :");
		int c=In -> GetInteger(Out);
		if (c >0 && c<100) 
		{
			CellNum=c; ans=1;
		}
	}


	// 3- Clear the status bar
	Out -> ClearStatusBar();
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply (pGrid, pPlayer);
	pGrid->UpdatePlayerCell( pPlayer,CellPosition(CellNum) );
	pPlayer->GetCell()->GetGameObject()->Apply(pGrid,pPlayer);


}
void CardSix ::  Save(ofstream &OutFile ,int type){
	if (type ==2 ){
		OutFile<<cardNumber<<" ";
		Card ::Save(OutFile,2);
		OutFile<<CellNum;
	}
}
void CardSix::Load(ifstream &infile,Grid*pGrid){
	//pGrid->AddObjectToCell(this);
	int cellnumber  ;
	Card::Load(infile,pGrid);
	infile>>cellnumber;
	CellNum=cellnumber;
	pGrid->AddObjectToCell(this);
	
}