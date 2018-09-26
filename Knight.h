#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Player*, char sign, int row, int col, Board*);
	virtual bool isLegalMove(int, int) const;

private:

};