#pragma once
#include "Card.h"
//Moves the player backward with the same number of steps that he just rolled.
class CardFive:	public Card
{
public:
	CardFive(const CellPosition & pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	~CardFive(void);
	virtual void ReadCardParameters(Grid * pGrid);
	void  Save(ofstream &OutFile,int type);
	void Load(ifstream &Infile,Grid*pGrid);
};
