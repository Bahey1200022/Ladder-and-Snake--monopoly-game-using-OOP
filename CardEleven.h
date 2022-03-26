#pragma once
#include "card.h"

class CardEleven :
	public Card
{
protected:
	static int Initialize; //this value to read card parameters only once 
	static int CardPrice;
	static int Fees;
	Player *Owner;

public:
	CardEleven(const CellPosition & pos);
	Player* getplayer (); //getter for the owner
	void setplayer (Player *p);
	int getcardprice(); //getter for the price 
	virtual void ReadCardParameters(Grid *pGrid);
	virtual void Apply(Grid *pGrid , Player *p);
	~CardEleven(void);
	void  Save(ofstream &OutFile,int type);
	void Load(ifstream &Infile,Grid*pGrid);
};