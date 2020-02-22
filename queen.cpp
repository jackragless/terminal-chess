#include <string>
#include <vector>

#include "piece.h"
#include "queen.h"

Queen::Queen() : Bishop()
{
	type = "queen";
	sprite = "Q";
}

Queen::Queen(int inpColour, int inpRow, int inpCol, Piece ***inpBoard)
{
	type = "queen";
	sprite = "Q";
	colour = inpColour;
	curRow = inpRow;
	curCol = inpCol;
	board = inpBoard;
	hasMoved = false;
}

void Queen::scan_legal_moves()
{
	Bishop::scan_legal_moves();
	std::vector<int> bishopLegalMoves = Bishop::get_legal_moves();
	Rook::scan_legal_moves();
	legalMoves.insert(legalMoves.end(),bishopLegalMoves.begin(),bishopLegalMoves.end());
	bishopLegalMoves.clear();
}

Queen::~Queen()
{
	legalMoves.clear();
}