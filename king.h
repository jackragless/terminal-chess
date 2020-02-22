#ifndef KING_H
#define KING_H

#include <vector>
#include <string>

#include "piece.h"

class King : public Piece{
public:
	King();
	King(int inpColour, int inpRow, int inpCol, Piece*** inpBoard);
	void scan_legal_moves();
	~King();

};




#endif