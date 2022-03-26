#pragma once
#include "card.h"

class CardNine :
	public Card
{
protected:
	static int Initialize; //this value to read card parameters only once 
	static int CardPrice;
	static int Fees;
	static Player *Owner;

public:
	Player* getplayer (); //getter for the owner
	void setplayer (Player *p); //set owner
	int getcardprice(); //getter for the price 
	CardNine(const CellPosition & pos);
	virtual void ReadCardParameters(Grid *pGrid);
	virtual void Apply(Grid *pGrid , Player *p);
	~CardNine(void);
	void  Save(ofstream &OutFile,int type);
	void Load(ifstream &Infile,Grid*);
};