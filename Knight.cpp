#include "Knight.h"
#define STEP 1
Knight::Knight(Player *p, char sign, int row, int col, Board *b) : Piece(p, sign, row, col, b)
{
}

bool Knight::isLegalMove(int destRow, int destCol) const
{
	if ((this->_row + STEP == destRow && this->_col + STEP * 2 == destCol) || (this->_row + STEP == destRow && this->_col - STEP * 2 == destCol) || (this->_row - STEP == destRow && this->_col + STEP * 2 == destCol) || (this->_row - STEP == destRow && this->_col - STEP * 2 == destCol) || (this->_row + STEP * 2 == destRow && this->_col + STEP == destCol) || (this->_row + STEP * 2 == destRow && this->_col - STEP == destCol) || (this->_row - STEP * 2 == destRow && this->_col + STEP == destCol) || (this->_row - STEP * 2 == destRow && this->_col - STEP == destCol))
	{
		if (this->_brd->isMe(destRow, destCol, this->getSign()))
		{
			return false;
		}
		if (this->_brd->isEnamy(destRow, destCol, this->getSign()))
		{
			this->_brd->letsEat(destRow, destCol);
		}
		return true;
	}

	return false;
}
