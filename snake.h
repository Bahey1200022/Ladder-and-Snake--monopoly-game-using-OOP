#pragma once
#include "GameObject.h"
#include "Output.h"
class Snake : public GameObject
{
	CellPosition endCellPos; //tail of the snake 
public:
	Snake (const CellPosition & headCellPos, const CellPosition & tailCellPos);

	 void Draw(Output* pOut) const; // Draws a snake 

	virtual void Apply(Grid* pGrid, Player* pPlayer);//snake effect

	CellPosition gettailcell() const ;
	//saving and loading :
	virtual void Save(ofstream &OutFile, int type); 

	virtual void Load(ifstream&Infile,Grid*pGrid);

	virtual ~Snake(); // Virtual destructor
};
