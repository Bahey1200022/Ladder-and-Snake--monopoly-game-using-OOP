#include "InputDiceValue.h"
#include "ApplicationManager.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"
InputDiceValue::InputDiceValue(ApplicationManager *pApp):Action(pApp)
{
}

void InputDiceValue:: ReadActionParameters(){

	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* O = pGrid->GetOutput();
	Input* I = pGrid->GetInput();
	//Getting the integer 
	pGrid->PrintErrorMessage("Please enter a dice value between 1-6");
	diceval= I->GetInteger(O); 
	//validation
	while (diceval <1 || diceval>6){
		O->PrintMessage("Please enter a dice value between 1-6");
		diceval= I->GetInteger(O);}
}

void InputDiceValue :: Execute(){

	Grid* pGrid = pManager->GetGrid();
	//check if game ended 
	if (pGrid->GetEndGame() == true) return;
	else if (pGrid->GetCurrentPlayer()->getprevent() == true || pGrid->GetCurrentPlayer()->getprison() >0) return;
	else{
	ReadActionParameters();
	pGrid->GetCurrentPlayer()->Move(pGrid,diceval);
	pGrid->AdvanceCurrentPlayer();}
}

InputDiceValue::~InputDiceValue(void)
{
}
