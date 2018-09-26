#pragma once

#include "Piece.h"
#include "Player.h"

#include <string.h>
#include <iostream>

#define BOARD_SIZE 8

using namespace std;

class Player;
class Piece;

class Board
{
public:

	Board(Player*, Player*);
	
	~Board();
	void print() const;
	void getString(char res[]) const;
	bool isPieceOfPlayer(int row, int col, Player* pl) const;
	bool tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const;
	Piece** getBoard() const;
	void Move(int srcRow, int srcCol, int dstRow, int dstCol);
	void undoLastMove();

	bool isEatable(int srcRow, int srcCol, int dstRow, int dstCol, char sign);
	bool isEnamy(int row, int col, char sign);

	bool isMoveStraight(int srcRow, int srcCol, int dstRow, int dstCol,bool isMovInRow, char sign);

	bool isCapitalLetter(char)const;
	bool isSmallCaps(char)const;
	bool isLatter(char)const;
	bool isFreeWay(int srcRow, int srcCol,int dstRow, int dstCol, bool isMovinRow, char sign);
	void letsEat(int dstRow, int dstCol);
	bool isFreeDiag(int, int, int, int, char);
	bool isMe(int, int, char sign);
private:
	Piece* _brd[BOARD_SIZE][BOARD_SIZE];
	Piece * whitespace;
	int _lastSrcRow;
	int _lastSrcCol;
	int _lastDstRow;
	int _lastDstCol;
	Piece* _lastPiece;
};