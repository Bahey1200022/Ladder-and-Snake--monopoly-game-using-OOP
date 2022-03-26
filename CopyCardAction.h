#pragma once
#include "Action.h"
#include"Card.h"

class CopyCardAction : public Action
{
	Card *pCard;
	
	// These parameters should be read in ReadActionParameters()

public:
	CopyCardAction(ApplicationManager *pApp) ;
	// [Action Parameters]
	CellPosition cardPosition; // cell position of the card

	// These parameters should be read in ReadActionParameters()

		
	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters (cardPosition)
	
	virtual void Execute(); // Creates a new Card Object of the specific Card Number
	                        // and Reads the Parameters of This Card Number (If the cell does not contain a card, cancel the operation)
	                        // then Sets this Card Object to GameObject Pointer of its Cell
	
	virtual ~CopyCardAction(void);
};
