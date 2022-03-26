#include "Snake.h"
#
#include <fstream>
Snake :: Snake(const CellPosition & headCellPos, const CellPosition & tailCellPos):GameObject(headCellPos){
	if (headCellPos.HCell() == tailCellPos.HCell() && tailCellPos.VCell() <headCellPos.VCell()) endCellPos=tailCellPos;}

void Snake::Draw(Output* pOut) const
{

	pOut->DrawSnake(position, endCellPos);
}
void Snake::Apply(Grid* pGrid, Player* pPlayer) 
{

	//same steps as the ladder class
	Input * i =pGrid->GetInput();
	Output *o =pGrid ->GetOutput();
	int x,y ;
	o->PrintMessage("You have reached a snake. Click to continue ...");
	i->GetPointClicked(x,y);
	o->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

	pGrid->UpdatePlayerCell(pPlayer,endCellPos);
}
void Snake ::Load(ifstream &Infile,Grid*pGrid){
	
		int headpos,tailpos;
		Infile >>headpos>>tailpos; //setting from the input file the start pos and end pos of the snake 
		position =CellPosition(headpos);
		endCellPos= CellPosition(tailpos);
	pGrid->AddObjectToCell(this);
}
void Snake :: Save (ofstream &OutFile,int type){
	if (type == 1)
		OutFile << position.GetCellNum() <<" "<<endCellPos.GetCellNum()<<endl;//saving the cell numbers in an output file 
} 
Snake ::~Snake(){};