#ifndef BISHOP_H
#define BISHOP_H

#include <vector>
#include <string>

#include "piece.h"

class Bishop : virtual public Piece
{
public:
	Bishop();
	Bishop(int inpColour, int inpRow, int inpCol, Piece*** inpBoard);
	void scan_legal_moves();
	~Bishop();

};




#endif