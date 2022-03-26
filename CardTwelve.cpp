#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos): Card(pos) {
	cardNumber = 12;
}


void CardTwelve::Apply(Grid* pGrid, Player* pPlayer) {
	Player *current =pGrid->GetCurrentPlayer();
	pGrid->player0();
	int min=100000;
	Player *least;
	for (int i=0;i<MaxPlayerCount;i++){
		if(pGrid->GetCurrentPlayer()->GetWallet() <min){min =pGrid->GetCurrentPlayer()->GetWallet();least=pGrid->GetCurrentPlayer();}
		pGrid->AdvanceCurrentPlayer();
	}
	if (current ==least) return;
	/*if (CardNine::getplayer()==current && CardTen::getplayer() == current && CardEleven::getplayer()==current)
	{if (CardNine ::getcardprice() >CardTen::getprice() && CardNine ::getcardprice() >CardEleven::getprice()) CardNine ::setplayer(least);
	else if (CardTen ::getcardprice() >CardNine::getprice() && CardTen ::getcardprice() >CardEleven::getprice()) CardTen ::setplayer(least);
	else if (CardEleven::getcardprice() >CardTen::getprice() && CardEleven ::getcardprice() >CardNine::getprice()) CardEleven ::setplayer(least);
	}
	else if (CardNine::getplayer()==current && CardTen::getplayer() == current)
	{if (CardNine ::getcardprice() >CardTen::getprice()) CardNine ::setplayer(least);
	else if (CardTen ::getcardprice() >CardNine::getprice()) CardTen ::setplayer(least);
	}
	else if (CardNine::getplayer()==current && CardEleven::getplayer() == current){
		if(CardNine ::getcardprice() >CardEleven::getprice()) CardNine ::setplayer(least);
		else if (CardEleven ::getcardprice() >CardNine::getprice()) CardEleven ::setplayer(least);}
	else if (CardTen::getplayer() == current && CardEleven::getplayer()==current){
		if (CardEleven::getcardprice() >CardTen::getprice()) CardEleven ::setplayer(least);
		else if (CardTen ::getcardprice() >CardEleven::getprice())CardTen ::setplayer(least);}
	else if (CardNine::getplayer()==current) CardNine ::setplayer(least);
	else if (CardTen::getplayer() == current) CardTen ::setplayer(least);
	else if (CardEleven::getplayer()==current) CardEleven ::setplayer(least);*/

}

void CardTwelve::Save(ofstream& outFile, int type) {
	if (type ==2)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, 2);
	}
}

void CardTwelve::Load(ifstream& InFile,Grid*pGrid) {
	Card::Load(InFile,pGrid);
	pGrid->AddObjectToCell(this);
}

CardTwelve:: ~CardTwelve() {} // A Virtual Destructor