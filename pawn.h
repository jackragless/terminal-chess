#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include <string>

#include "piece.h"

class Pawn : public Piece{
public:
	Pawn();
	Pawn(int inpColour, int inpRow, int inpCol, Piece*** inpBoard);
	void scan_legal_moves();
	~Pawn();
};


#endif