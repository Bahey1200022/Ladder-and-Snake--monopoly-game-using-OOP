#include "NewGame.h"
#include "Grid.h"
#include "Player.h"
#include "Input.h"
#include "Output.h"
NewGame::NewGame(ApplicationManager *pApp):Action(pApp)
{
}

void NewGame::ReadActionParameters()
{
	// there is no parameters to add to this function 
}

void NewGame :: Execute(){

	CellPosition newgcell(8, 0); //the first cell in the game has vcell 8 (last row) and hcell 0 (first column)
	Grid *g = pManager->GetGrid();

	g->player0(); // start resetting from player 0 

	for (int i = 0 ;i<MaxPlayerCount;i++){
		g->UpdatePlayerCell(g->GetCurrentPlayer(),newgcell);
		g->GetCurrentPlayer()->setprison(0);
		g->GetCurrentPlayer()->setprevent(false);
		g->GetCurrentPlayer()->setturncount(0); //setting  the initial conditions of the game to every player
		g->GetCurrentPlayer()->SetWallet(100);
		g->AdvanceCurrentPlayer();              //going from player i to player i+1
	}
	
}

NewGame::~NewGame()
{
}
