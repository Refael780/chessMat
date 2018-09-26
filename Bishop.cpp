#include "Bishop.h"

Bishop::Bishop(Player *p, char sign, int row, int col, Board *b) : Piece(p, sign, row, col, b)
{
	
}

bool Bishop::isLegalMove(int dstrow, int dstcol) const
{

	if ((abs(this->_row - dstrow ) == abs(this->_col - dstcol))||abs((dstrow -this->_row)==abs(dstcol -this->_col)))
	{
		if (this->_brd->isFreeWay(this->_row, this->_col, dstrow, dstcol, NULL, this->getSign()))
		{
			
			return true;
		}
		
	}

	
	return false;
}
