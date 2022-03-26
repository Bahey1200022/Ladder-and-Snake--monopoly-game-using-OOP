
#pragma once
#include "Card.h"
//Card3 gives the player an extra dice roll.
class CardThree :public Card
{
public:
	CardThree(const CellPosition & pos);
	~CardThree(void);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void ReadCardParameters(Grid * pGrid);
	void  Save(ofstream &OutFile,int type);
	void Load(ifstream &Infile,Grid*pGrid);
};