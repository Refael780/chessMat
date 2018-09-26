

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Player*,char sign, int row, int col, Board*);
	Queen();
	virtual bool isLegalMove(int, int) const;

private:

};