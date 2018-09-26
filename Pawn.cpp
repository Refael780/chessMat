#include "Pawn.h"
#define STEP 1

Pawn::Pawn(Player *p, char sign, int row, int col, Board *b) : Piece(p, sign, row, col, b)
{
}

bool Pawn::isLegalMove(int destRow, int destCol) const
{
	if (this->_brd->isSmallCaps(this->getSign())) ///if the pawn is Black
	{
		
		if ((destRow+ STEP == this->_row)&&(destCol == this->_col))//if the move is legel
		{
			if (this->_brd->isFreeWay(NULL,NULL,destRow, destCol,NULL, this->getSign()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (this->_row != destRow && this->_col != destCol) ///special case for eating in diagonally
		{
			if (this->_brd->isEatable(this->_row, this->_col, destRow, destCol, this->getSign()))
			{
				return true;
			}
			return false;
		}


	}
	else   ///if the pawn is white
	{
		

		if (destRow - STEP == this->_row&&destCol == this->_col)
		{
			if (this->_brd->isFreeWay(NULL,NULL,destRow, destCol,NULL, this->getSign()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		else if (this->_row != destRow && this->_col != destCol) ///special case for eating in diagonally
		{
			if (this->_brd->isEatable(this->_row, this->_col, destRow, destCol, this->getSign()))
			{
				return true;
			}
			return false;
		}
	}

	return false;
}
