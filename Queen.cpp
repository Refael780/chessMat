#include "Queen.h"

Queen::Queen(Player *p,char sign,int row, int col, Board *b): Piece(p,sign,row,col,b)
{

}
Queen::Queen() : Piece()
{

}
bool Queen::isLegalMove(int dstRow, int dstCol) const
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
	}
	else if ((abs(this->_row - dstRow) == abs(this->_col - dstCol)) || abs((dstRow - this->_row) == abs(dstCol - this->_col)))
	{
		if (this->_brd->isFreeWay(this->_row, this->_col, dstRow, dstCol, NULL, this->getSign()))
		{

			return true;
		}

	}
	return false;
}
