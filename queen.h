#include <string>
#include "piece.h"
#include "rook.h"
#include "bishop.h"

#ifndef QUEEN_h
#define QUEEN_h

class Queen : public Rook, public Bishop
{
public:
	Queen();
	Queen(int inpColour, int inpRow, int inpCol, Piece*** inpBoard);
	void scan_legal_moves();
	~Queen();
	
};
#endif