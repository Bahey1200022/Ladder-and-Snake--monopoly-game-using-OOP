#pragma once
#include "Grid.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

class CardTwelve:public Card
{
public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	void Save(ofstream& outFile, int type); // Overriding the Card Save member function

	void Load(ifstream& InFile,Grid*pGrid); // Overriding the Card Load member function

	virtual ~CardTwelve(); // A Virtual Destructor
};