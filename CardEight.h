#pragma once
#include "Card.h"

class CardEight: public Card
{int NeededAmount;
bool choice;
public:
	CardEight(const CellPosition & pos);
	~CardEight(void);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void  Save(ofstream &OutFile,int type);
	void Load(ifstream &Infile,Grid*);
};