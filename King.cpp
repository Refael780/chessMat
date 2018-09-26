#include "King.h"

King::King(Player *p, char sign, int row, int col, Board *b) : Piece(p, sign, row, col, b)
{

}

bool King::isLegalMove(int dstRow, int dstCol) const
{
	if ((this->_row == dstRow + 1 && this->_col == dstCol) || (this->_row == dstRow + 1 && this->_col == dstCol + 1) || (this->_row == dstRow - 1 && this->_col == dstCol) || (this->_row == dstRow - 1 && this->_col == dstCol + 1) || (this->_row == dstRow - 1 && this->_col == dstCol - 1) || (this->_row == dstRow && this->_col == dstCol + 1) || (this->_row == dstRow + 1 && this->_col == dstCol - 1))
	{
		if (this->_brd->isMe(dstRow, dstCol, this->getSign()))
		{
			return false;
		}
		if (this->_brd->isEnamy(dstRow, dstCol, this->getSign()))
		{
			this->_brd->letsEat(dstRow, dstCol);
		}
		return true;
	}
	return false;
}

bool King::isChess()
{
	return false;
}
