#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v>=0 && v<=8  )
	{vCell = v;
	return true;}
	else return false;


	 
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h>=0 && h<=10){
			hCell=h;
			return true;}
	else return false;


}

int CellPosition::VCell() const 
{

	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if (vCell>=0 && vCell <=8 && hCell>=0 && hCell <=10)
		return true;
	else
	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
int cellNum;

if(cellPosition.vCell>8 || cellPosition.hCell>10) return -1;
cellNum= 10*(8-cellPosition.vCell)+(9-(cellPosition.vCell+1)+1)+cellPosition.hCell;
	

	return cellNum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	if (cellNum %11==0){
		position.hCell=10;
		position.vCell=9-(cellNum/11);}
	else if (cellNum<11){
		position.vCell=8;
		position.hCell=cellNum-1;}
	else {
		position.vCell=8-int(cellNum/11);
		position.hCell=(cellNum%11)-1;
	}
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO: Implement this function as described in the .h file
	
	 int cellnum;
	 cellnum = GetCellNum()+ addedNum;
	 CellPosition current(cellnum);
	 SetHCell(current.HCell());SetVCell(current.VCell());


	// Note: this function updates the data members (vCell and hCell) of the calling object

}