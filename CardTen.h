#pragma once
#include "card.h"

class CardTen :
	public Card
{
protected:
	static int Initialize; //this value to read card parameters only once 
	static int CardPrice;
	static int Fees;
	static Player *Owner;

public:
	Player* getplayer (); //getter for the owner
	void setplayer (Player *p);
	int getcardprice(); //getter for the price 
	CardTen(const CellPosition & pos);
	void ReadCardParameters(Grid *pGrid);
	void Apply(Grid *pGrid , Player *p);
	//save and load fn
	virtual void Save(ofstream &OutFile ,int type); 
	virtual void Load(ifstream& infile,Grid*);
	~CardTen(void);
};