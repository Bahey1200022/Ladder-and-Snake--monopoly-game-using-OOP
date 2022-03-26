#pragma once
#include "Card.h"
//moves the player forward to the start of the next ladder in the grid
class CardTwo :	public Card
{
public:
	CardTwo(const CellPosition & pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	//save and load fn
	virtual void Save(ofstream &OutFile ,int type); 
	virtual void Load(ifstream& infile,Grid*pGrid);
};

