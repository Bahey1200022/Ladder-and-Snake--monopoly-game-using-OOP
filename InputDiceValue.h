
#pragma once
#include "Action.h"
class InputDiceValue :public Action
{
	int diceval;
public:
	InputDiceValue(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads InputDiceValue action parameters (dicevalue)

	virtual void Execute();            //sets the passed int as the dice value 

	virtual ~InputDiceValue(); // Virtual Destructor

};
