#pragma once
#include "Card.h"
class CardSeven : public Card
{
public:
	CardSeven(const CellPosition & pos);
	~CardSeven(void);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);


	void  Save(ofstream &OutFile,int type);
	void Load(ifstream &Infile,Grid*pGrid);
};
