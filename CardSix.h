#pragma once
#include "Card.h"

// [ CardOne ] Summary:
// Its Apply() Function: Decrements the value of the passing player�s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardSix :	public Card
{
	// Cardsix Parameters:
	int CellNum;; // the cell num to move to

public:
	CardSix(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of Card6 which is: cellnum

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card6 on the passed Player
	                                                  
	
	virtual ~CardSix(); // A Virtual Destructor

	void  Save(ofstream &OutFile,int type);
	void Load(ifstream &Infile,Grid*pGrid);
};