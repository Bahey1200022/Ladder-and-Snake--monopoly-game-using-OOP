#include "Ladder.h"
#include<fstream>
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.HCell()==endCellPos.HCell() && endCellPos.GetCellNum()>startCellPos.GetCellNum()) this->endCellPos=endCellPos;


	///TODO: Do the needed validation

}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Input * i =pGrid->GetInput();
	Output *o =pGrid ->GetOutput();
	int x,y ;
	o->PrintMessage("You have reached a ladder. Click to continue ...");
	i->GetPointClicked(x,y);
	o->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer,endCellPos);
}   //this function moves the player to the end cell posistion 

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder :: Save(ofstream &OutFile,int type){
	if (type ==0)
		OutFile <<position.GetCellNum()<<" "<<endCellPos.GetCellNum()<<endl;
	//saving the cell numbers in an output file 

}
void Ladder :: Load(ifstream &Infile,Grid*pGrid){

	int sposition,endpos;
	Infile >>sposition >> endpos;//setting from the input file the start pos and end pos of the ladder.
	position =CellPosition(sposition);
	endCellPos=CellPosition(endpos);
	pGrid->AddObjectToCell(this);
}
Ladder::~Ladder()
{
}