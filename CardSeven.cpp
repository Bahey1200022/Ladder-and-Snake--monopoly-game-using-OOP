#include "CardSeven.h"
#include <fstream>

CardSeven::CardSeven(const CellPosition & pos): Card(pos)
{
	cardNumber = 7;
}


CardSeven::~CardSeven(void)
{
}
void CardSeven::ReadCardParameters(Grid * pGrid)
{

}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	/*/CellPosition newgcell(8, 0);
	pGrid->player0();
	Player** arr; int p = 0;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (pPlayer->GetCell()->GetCellPosition().GetCellNum() > currp->GetCell()->GetCellPosition().GetCellNum())
			arr[p] = pPlayer;
		p++;
		pGrid->AdvanceCurrentPlayer();
	}
	Player* next;
	int min = 10000000;
	for (int i = 0; i < p; i++) {
		if (arr[i]->GetCell()->GetCellPosition().GetCellNum() - currp->GetCell()->GetCellPosition().GetCellNum()) {
			min = arr[i]->GetCell()->GetCellPosition().GetCellNum(); next = arr[i];
		}
	}
		pGrid->UpdatePlayerCell(next, newgcell);

*/
	Card::Apply (pGrid, pPlayer);
	Player * currp =pGrid->GetCurrentPlayer();
	for(int i=0; i<MaxPlayerCount-1;i++)
	{
		pGrid->AdvanceCurrentPlayer();
		if(pPlayer->GetCell()->GetCellPosition().GetCellNum() > currp->GetCell()->GetCellPosition().GetCellNum())
		{
			pGrid->UpdatePlayerCell( pPlayer,CellPosition(1) );
			break;
		}
		else pGrid->AdvanceCurrentPlayer();
	}
}
void CardSeven ::  Save(ofstream &OutFile ,int type){
	if (type ==2 ){
		OutFile<<cardNumber<<" ";
		Card ::Save(OutFile,2);
	}
}
void CardSeven::Load(ifstream &infile,Grid*pGrid){
	//pGrid->AddObjectToCell(this);
	Card::Load( infile,pGrid);
	pGrid->AddObjectToCell(this);
}
