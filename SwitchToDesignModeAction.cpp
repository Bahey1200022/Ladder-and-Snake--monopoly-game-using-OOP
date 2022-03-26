#include "SwitchToDesignModeAction.h"
#include "Input.h"
#include "Output.h"
#include"Player.h"
SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

SwitchToDesignModeAction::~SwitchToDesignModeAction()
{

}
void SwitchToDesignModeAction::ReadActionParameters()
{
	// no parameters to read from user
}
void SwitchToDesignModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();
	Player *pPlayer =pGrid->GetCurrentPlayer();
	pOut->CreateDesignModeToolBar();
	//Resets the players' parameters
	pGrid -> player0();
		CellPosition newgcell(8, 0); //the first cell in the game has vcell 8 (last row) and hcell 0 (first column)
	for (int i = 0 ;i<MaxPlayerCount;i++){
		pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(),newgcell);
		pGrid->GetCurrentPlayer()->setturncount(0); //setting  the initial conditions of the game to every player
		pGrid->GetCurrentPlayer()->SetWallet(100);
		pGrid->AdvanceCurrentPlayer();              //going from player i to player i+1
	}
	//Update interface with the changes
	pGrid->UpdateInterface();
}