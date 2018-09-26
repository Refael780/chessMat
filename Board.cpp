#define _CRT_SECURE_NO_WARNINGS
#define  BOARD_SIZE 8
#define STEP 1

#include "Board.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Pawn.h"
#include "NullPiece.h"


using namespace std;
Board::Board(Player *pl1, Player *pl2)///build the game
{
	int i,j = 0;
	int tempSize = 15;
	Piece *n;

	_brd[0][0] = new Rook(pl1, 'R', 0, 0, this);
	_brd[0][1] = new Knight(pl1, 'N', 0, 1, this);

	_brd[0][2] = new Bishop(pl1, 'B', 0, 2, this);

	_brd[0][3] = new Queen(pl1, 'Q', 0, 3, this);

	_brd[0][4] = new King(pl1, 'K', 0, 4, this);

	_brd[0][5] = new Bishop(pl1, 'B', 0, 5, this);

	_brd[0][6] = new Knight(pl1, 'N', 0, 6, this);

	_brd[0][7] = new Rook(pl1, 'R', 0, BOARD_SIZE - 1, this);



	_brd[1][0] = new Pawn(pl1, 'P', 1, 0, this);
	_brd[1][1] = new Pawn(pl1, 'P', 1, 1, this);
	_brd[1][2] = new Pawn(pl1, 'P', 1, 2, this);
	_brd[1][3] = new Pawn(pl1, 'P', 1, 3, this);
	_brd[1][4] = new Pawn(pl1, 'P', 1, 4, this);
	_brd[1][5] = new Pawn(pl1, 'P', 1, 5, this);
	_brd[1][6] = new Pawn(pl1, 'P', 1, 6, this);
	_brd[1][7] = new Pawn(pl1, 'P', 1, 7, this);


	for ( i=2 ; i< 6; i++)
	{
		for ( j = 0; j < BOARD_SIZE; j++)
		{

			_brd[i][j] = new NullPiece(i+1, j+1);


		}
	}
	_brd[BOARD_SIZE - 2][0] = new Pawn(pl2, 'p', 6, 0, this);
	_brd[BOARD_SIZE - 2][1] = new Pawn(pl2, 'p', 6, 1, this);
	_brd[BOARD_SIZE - 2][2] = new Pawn(pl2, 'p', 6, 2, this);
	_brd[BOARD_SIZE - 2][3] = new Pawn(pl2, 'p', 6, 3, this);
	_brd[BOARD_SIZE - 2][4] = new Pawn(pl2, 'p', 6, 4, this);
	_brd[BOARD_SIZE - 2][5] = new Pawn(pl2, 'p', 6, 5, this);
	_brd[BOARD_SIZE - 2][6] = new Pawn(pl2, 'p', 6, 6, this);
	_brd[BOARD_SIZE - 2][BOARD_SIZE - 1] = new Pawn(pl2, 'p', 6, 7, this);


	_brd[BOARD_SIZE-1][0] = new Rook(pl2, 'r', 7, 0, this);
	_brd[BOARD_SIZE - 1][1] = new Knight(pl2, 'n', 7, 1, this);

	_brd[BOARD_SIZE - 1][2] = new Bishop(pl2, 'b', 7, 2, this);

	_brd[BOARD_SIZE - 1][3] = new Queen(pl2, 'q', 7, 3, this);

	_brd[BOARD_SIZE - 1][4] = new King(pl2, 'k', 7, 4, this);

	_brd[BOARD_SIZE - 1][5] = new Bishop(pl2, 'b', 7, 5, this);

	_brd[BOARD_SIZE - 1][6] = new Knight(pl2, 'n', 7, 6, this);

	_brd[BOARD_SIZE - 1][BOARD_SIZE - 1] = new Rook(pl2, 'r', 7, 7, this);



	


}

Board::~Board()
{
}

void Board::print() const//print the game in cmd
{
	int i = 0;
	int j=0;
	int count = 0;
	for (i = 0; i <= BOARD_SIZE - 1; i++)
	{
		cout << i << " ";
		for ( j = 0; j <= BOARD_SIZE - 1; j++)
		{

			count++;
			cout << _brd[i][j]->getSign();

		}
		cout <<  endl;
	}
}
void Board::getString(char res[]) const
{


	int i, j = 0;
	int count = 0;
	for ( i = 0; i <= BOARD_SIZE-1; i++)
	{
		cout <<i<< " ";
		for ( j = 0; j <= BOARD_SIZE-1; j++)
		{
			res[count]=_brd[i][j]->getSign();
			count++;
			cout <<  _brd[i][j]->getSign();

		}
		cout << endl;
	}
	res[count] = '0';
	cout << endl << "RES:";
	for ( i = 0; i < count; i++)
	{
		cout<<res[i];
	}
	cout << endl;
	
	
	




	
}

bool Board::isPieceOfPlayer(int row, int col, Player * pl) const//if the right player play
{
	char signC=this->_brd[row][col]->getSign();
	cout << signC << endl;
	if (!pl->isWhite())
	{
		if ((signC >= 'a'&&signC <= 'z'))
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	else
	{
		if (signC >= 'A'&&signC <= 'Z')
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

bool Board::tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const
{
	int i;
	if (this->_brd[srcRow][srcCol]->isLegalMove(dstRow , dstCol))//try to move
	{
	
		return true;
		
	}
	else
	{
		return false;
	}
	this->print();

}


///if the piece is white
bool Board::isCapitalLetter(char sign)const
{
	if (sign >= 'A'&&sign <= 'Z')
	{
		return true;
	}
	return false;
}
///if the piece is black
bool Board::isSmallCaps(char sign)const
{
	if (sign >= 'a'&&sign <= 'z' )
	{
		return true;
	}
	return false;
}
///if its pieces
bool Board::isLatter(char sign)const
{
	if ((sign >= 'a'&&sign <= 'z' || sign >= 'A'&&sign <= 'Z'))
	{
		return true;
	}
	return false;

}

bool Board::isFreeWay(int srcRow ,int srcCol ,int dstRow, int dstCol, bool isMovInRow,char sign) //if the piece can move to destantion
{
	int i,tempDst,tempI;
	char tempSign;
	tempSign = toupper(sign);
	switch (tempSign)
	{
	case 'P':
	{
		
			if ((this->isLatter(this->_brd[dstRow][dstCol]->getSign())))//if the place alredy taken
			{
				return false;
			}
			else
			{
				return true;
			}
		

		break;
	}
	case 'R':
	{
		if (isMoveStraight(srcRow, srcCol, dstRow, dstCol, isMovInRow, sign))//for the piece that move Straight
		{
			return true;
		}
		break;

	}
	case 'B':
	{
		if (isFreeDiag(srcRow, srcCol, dstRow, dstCol, sign)) 
		{
			return true;
		}
		break;
	}
	case 'Q':
	{
		if (isMovInRow == NULL)
		{
			if (isFreeDiag(srcRow, srcCol, dstRow, dstCol, sign))
			{
				return true;
			}
		}
	   if (isMoveStraight(srcRow, srcCol, dstRow, dstCol, isMovInRow, sign))
		{
			return true;
		}
		return false;
		break;
	}

	default:
		break;
	}

	
}

void Board::letsEat(int dstRow, int dstCol)
{
	
	_brd[dstRow][dstCol] = new NullPiece(dstRow, dstCol);

}

bool Board::isFreeDiag(int srcRow, int srcCol, int dstRow, int dstCol, char sign)
{
	int i, j;
	if (srcRow >= dstRow&&srcCol>=dstCol)
	{
		srcRow *= -1;
		dstRow *= -1;
		srcCol *= -1;
		dstCol *= -1;
	}
	else if (srcRow >= dstRow&&srcCol <= dstCol)
	{
		srcRow *= -1;
		dstRow *= -1;
		
	}
	else if (srcRow <= dstRow&&srcCol >= dstCol)
	{
		srcCol *= -1;
		dstCol *= -1;
	}



	for ( i = srcRow+1,j=srcCol+1; i < dstRow,j<dstCol; i++,j++)
	{
		
			
			if (this->isLatter(this->_brd[abs(i)][abs(j)]->getSign()))
			{
				return false;
			}

		

	}
	srcRow = abs(srcRow);
	srcCol = abs(srcCol);
	dstRow = abs(dstRow);
	dstCol = abs(dstCol);

	if (this->isEnamy(dstRow, dstCol,sign)) 
	{
		this->letsEat(dstRow, dstCol);
		return true;
	}
	if (this->isMe(dstRow, dstCol, sign)) 
	{
		return false;
	}
	return true;
	
}
//if the marked piece belong to currnt player
bool Board::isMe(int row, int col, char sign)
{
	if (this->_brd[row][col]->getSign() >= 'A'&&this->_brd[row][col]->getSign() <= 'Z')
	{
		if (this->isCapitalLetter(sign))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (this->_brd[row][col]->getSign() >= 'a'&&this->_brd[row][col]->getSign() <= 'z')
	{
		if (this->isSmallCaps(sign))
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

Piece ** Board::getBoard() const
{
	return nullptr;
}

void Board::Move(int srcRow, int srcCol, int dstRow, int dstCol)
{

	cout << "\nBEFOREin the SORCE place-> in place" << srcRow << ", " << srcCol << "the tool that going to move : " << this->_brd[srcRow][srcCol]->getSign() << endl;
	this->_brd[srcRow][srcCol]->setPosition(dstRow , dstCol);
	//this->_brd[dstRow ][dstCol ]->setPosition(srcRow, srcCol);
	Piece *tempPiece;
	tempPiece = this->_brd[dstRow][dstCol];
	this->_brd[dstRow][dstCol] = this->_brd[srcRow][srcCol];
	this->_brd[srcRow][srcCol] = tempPiece;
	cout << "\nAFTER->who in the place->" << srcRow << ", " << srcCol << "the tool/# that replacd : " << this->_brd[srcRow][srcCol]->getSign() << endl;
	cout << "\nAFTERin the DEST place-> in place" << dstRow << ", " << dstCol << "the tool that going to move : " << this->_brd[dstRow][dstCol]->getSign() << endl;


}

void Board::undoLastMove()
{
}

bool Board::isEatable(int srcRow, int srcCol, int dstRow, int dstCol, char SrcSign)
{



	switch (SrcSign)
	{

	case 'p':
	{
		cout << endl << "Who want to eat :" << this->_brd[srcRow][srcCol]->getSign() << "\nhis place from row-col: " << srcRow << ", " << srcCol << "\nwho is eating: " << this->_brd[dstRow][dstCol]->getSign() << "\nhis place row col: " << dstRow << ", " << dstCol << endl;
		if (((dstRow == srcRow - STEP) && (dstCol == srcCol + STEP) && (this->isCapitalLetter(this->_brd[dstRow][dstCol]->getSign()))) || (dstRow == srcRow - STEP && dstCol == srcCol - STEP && (this->isCapitalLetter(this->_brd[dstRow][dstCol]->getSign()))))
		{
			this->letsEat(dstRow, dstCol);
			return true;
			break;
		}
		return false;

	}
	case 'P':
		if (((dstRow == srcRow + STEP) && (dstCol == srcCol + STEP) && (this->isSmallCaps(this->_brd[dstRow][dstCol]->getSign()))) || (dstRow == srcRow + STEP && dstCol == srcCol - STEP && (this->isSmallCaps(this->_brd[dstRow][dstCol]->getSign()))))
		{
			this->letsEat(dstRow, dstCol);
			return true;
			break;
		}
	/*case 'r':
	case 'R':
	{

		if (this->isEnamy(dstRow, dstCol, SrcSign))
		{
			this->letsEat(dstRow, dstCol);
			return true;
			break;
		}

	}*/
	default:
		break;
	}


}
bool Board::isEnamy(int dstrow,int dstcol,char Mysign) 
{
	if (this->_brd[dstrow][dstcol]->getSign() >= 'A'&&this->_brd[dstrow][dstcol]->getSign() <= 'Z')
	{
		if (Mysign >= 'a'&&Mysign <= 'z')
		{
			return true;
		}
	}
	else if (this->_brd[dstrow][dstcol]->getSign() >= 'a'&&this->_brd[dstrow][dstcol]->getSign() <= 'z')
	{
		if (Mysign >= 'A'&&Mysign <= 'Z')
		{
			return true;
		}
	}

	return false;
}

bool Board::isMoveStraight(int srcRow, int srcCol, int dstRow, int dstCol,bool isMovinRow, char sign)
{
	int i, tempDst, tempI;
	char tempSign;

	if (srcRow > dstRow)
	{
		srcRow *= -1;
		dstRow *= -1;

	}
	if (srcCol > dstCol)
	{
		srcCol *= -1;
		dstCol *= -1;
	}
	if (!isMovinRow)//movin horizotally
	{

		for (i = srcCol + 1; i <= dstCol; i++)
		{
				if (this->isMe(srcRow, abs(i),sign))
				{
					return false;
				}
			

		}
	}
	else////movin verticaly
	{
		for (i = srcRow + 1; i <= dstRow; i++)
		{

			
				if (this->isMe(abs(i),srcCol,sign))
				{
					return false;
				}
			
		}
	}

	dstRow = abs(dstRow);
	dstCol = abs(dstCol);
	if (this->isEnamy(dstRow, dstCol, sign))
	{
		this->letsEat(dstRow, dstCol);
		return true;
	}
	return true;
}

