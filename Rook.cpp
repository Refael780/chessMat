#include "Rook.h"

Rook::Rook(Player *p,char sign,int row, int col, Board *b): Piece(p,sign,row,col,b)
{
}

bool Rook::isLegalMove(int dstRow  , int dstCol) const
{
	bool isRow = true;
	
	if ((this->_col == dstCol && this->_row != dstRow))
	{
		if (this->_brd->isFreeWay(this->_row, this->_col, dstRow, dstCol, isRow, this->getSign()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (this->_col != dstCol && this->_row == dstRow)
	{
		if (this->_brd->isFreeWay(this->_row, this->_col, dstRow, dstCol, !isRow, this->getSign()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
	
}
