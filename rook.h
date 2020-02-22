#include <string>
#include "piece.h"


#ifndef ROOK_H
#define ROOK_H

class Rook : virtual public Piece
{
public:
	Rook();
	Rook(int inpColour, int inpRow, int inpCol, Piece*** inpBoard);
	void scan_legal_moves();
	~Rook();
};

#endif