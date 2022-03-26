
#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this ->wallet=100;
	this->stepCount=0;
	this->Prevent=false;
	prison=0;
	//if (playerNum >=0 && playerNum <=MaxPlayerCount-1) this->playerNum=playerNum;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet>0) this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{

	return turnCount;
}
void Player :: setturncount(int c){
	if (c>=0 && c<=3) turnCount =c;}

int Player :: getplayernum()const {
	return playerNum ;}

bool Player ::getprevent() const {return Prevent;}
int Player :: getprison(){return prison;}
void Player ::setprison(int p) {prison=p;};
void Player ::Cardowner(Player* cowner)
{
	cardowner =cowner;
}
//===================functions for cards=======================================
void Player ::setprevent(bool prev){Prevent=prev;}

void Player::setPrevent()
{
	Prevent=true;
}
int Player::getjustRolledDiceNum()
{
	return justRolledDiceNum; 
}


void Player::IamPrisoned()
{
	prison=3;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,playerColor);
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;

	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,cellColor);
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{
	Input *I =pGrid->GetInput();
	Output *O =pGrid->GetOutput();
	int NewDiceNumber;
	if(diceNumber<0)
		NewDiceNumber=-diceNumber;
	else NewDiceNumber=diceNumber;
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Player*mainplayer=pGrid->GetCurrentPlayer();
	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount=turnCount+1;
	if(prison ==0)
	{
		// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
		//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
		if (Prevent==false)
		{
			if (turnCount ==3) 

			{wallet = wallet +(NewDiceNumber*10);
			turnCount=0;
			return;}
			if (mainplayer->GetWallet()==0)
			{
				return;
			}
			// 3- Set the justRolledDiceNum with the passed diceNumber
			justRolledDiceNum=diceNumber;
			// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
			//    Using the appropriate function of CellPosition class to update "pos"
			CellPosition pos = mainplayer->GetCell()->GetCellPosition();
			pos.AddCellNum(justRolledDiceNum);
			// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
			//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
			pGrid->UpdatePlayerCell(mainplayer,pos);
			// 6- Apply() the game object of the reached cell (if any)
			while (mainplayer->GetCell()->GetGameObject() !=NULL)
			{
				mainplayer->GetCell()->GetGameObject()->Apply(pGrid,mainplayer);
				 if (mainplayer->GetCell()->HasCard())break;
			}                      
			//checks for every cell wether it has a game object or not then it applies the movement.
			// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
			if (pos.GetCellNum()==99)
				pGrid->SetEndGame(true);
		}
		else Prevent=false;

	}
	else prison--;
	pGrid->UpdateInterface();
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}