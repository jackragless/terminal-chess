#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>
#include <string>

#include "piece.h"

class Knight : public Piece{
public:
	Knight();
	Knight(int inpColour, int inpRow, int inpCol, Piece*** inpBoard);
	void scan_legal_moves();
	~Knight();

};




#endif