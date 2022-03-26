#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include "ApplicationManager.h"
#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Input *i =pManager->GetGrid()->GetInput();
	Output*o =pManager->GetGrid()->GetOutput();
	int x,y;
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pManager->GetGrid()->GetEndGame()== true){
		return;}

	// -- If not ended, do the following --:
	else {
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
		o->PrintMessage("dice roll = " + to_string(diceNumber));
		i->GetPointClicked(x,y);
		o->ClearStatusBar();
		// 3- Get the "current" player from pGrid
		Player * cur=pManager->GetGrid()->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		cur->Move(pManager->GetGrid(),diceNumber); 
		// 5- Advance the current player number of pGrid
		pManager->GetGrid()->AdvanceCurrentPlayer();

		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

	}
}
RollDiceAction::~RollDiceAction(){};