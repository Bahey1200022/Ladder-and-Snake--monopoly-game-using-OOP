#include "CardEleven.h"
#include "AddCardAction.h"
#include <fstream>
int CardEleven:: Initialize=0;
int CardEleven:: CardPrice=0;
int CardEleven:: Fees=0;

CardEleven::CardEleven(const CellPosition & pos) : Card(pos)
{
	cardNumber=11;
}


CardEleven::~CardEleven(void)
{
}
void CardEleven::ReadCardParameters(Grid *pGrid)
{
	if(Initialize==0)
	{
		Output *pOut =pGrid->GetOutput();
		Input *pIn=pGrid->GetInput();
		pOut->PrintMessage("Enter Card Price Please:");
		int z;
		do
		{
			z=pIn->GetInteger(pOut);
			if(z>0)
				CardPrice=z;
			else
			{
				pOut->PrintMessage("Please Enter Valid Price");

			}
		} while (z<0);
		pOut->PrintMessage("Please Enter Fees should be payed When passing through this card:");
		int x;
		do
		{
			x=pIn->GetInteger(pOut);
			if (x>0)
				Fees=x;
			else
				pOut->PrintMessage("Please Enter Valid Value");
		} while (x<0);
		pOut->ClearStatusBar();
	}
	Initialize=1;
}
void CardEleven::Apply(Grid *pGrid , Player *p)
{
	Card::Apply(pGrid,p);

	Output *pOut= pGrid->GetOutput();
	Input *pIn= pGrid->GetInput();
	if (Owner==NULL)
	{
		int Decision;
		pOut->PrintMessage("Do you want to buy this card ? if Yes , click 1, if No , click 2");
		Decision=pIn->GetInteger(pOut);
		while (Decision != 1 || Decision !=2)
		{
			pOut->PrintMessage("Please enter valid answer (1 if yes)(2 if no)");
			Decision=pIn->GetInteger(pOut);
		}
		if (Decision==1)
		{
			int wallet =p->GetWallet();
			if(wallet >=CardPrice)
			{
				p->SetWallet(wallet-CardPrice);
				pOut->PrintMessage("Congratulations , You are the owner of the card Now");
				Owner=p;
			}
			else
				pGrid->PrintErrorMessage("you can't buy this card due to insuffecient ammount of coins");
		}
		else
		{
			pGrid->PrintErrorMessage("complete playing");
		}
	}
	else if (p!=Owner && Owner !=NULL)
	{
		int PasserWallet=p->GetWallet();
		int OwnerWallet=Owner->GetWallet();
		if(Fees<=PasserWallet)
		{
			p->SetWallet(PasserWallet-Fees);
			Owner->SetWallet(OwnerWallet+Fees);
		}
		else
		{

		}
	}
}
Player* CardEleven:: getplayer (){return Owner;}

void CardEleven :: setplayer (Player *p){Owner =p;}

int CardEleven ::getcardprice(){return CardPrice;}

void CardEleven :: Save(ofstream &OutFile ,int type){
	if (type ==2 ){
		OutFile<<cardNumber<<" ";
		Card ::Save(OutFile,2);
		OutFile <<CardPrice<<Fees<<endl;
	}
}
void CardEleven ::Load(ifstream &infile,Grid*pGrid){
	
		int cprice,fees ;
		Card::Load( infile,pGrid);
		infile >>cprice>>fees ;
		Fees=fees;
		CardPrice=cprice ;
	pGrid->AddObjectToCell(this);
}