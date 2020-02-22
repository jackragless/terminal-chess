#include <string>
#include <vector>
#include <cstddef>
#include <iostream>

#include "piece.h"
#include "knight.h"

Knight::Knight() : Piece(){
	type = "knight";
	sprite = 'H';
}

Knight::Knight(int inpColour, int inpRow, int inpCol, Piece ***inpBoard) : Piece("Knight","H", inpColour, inpRow, inpCol, inpBoard)
{}

void Knight::scan_legal_moves(){
	legalMoves.clear();
	for (int one = -1; one<2; one+=2)
	{
		for (int two = -2; two <3; two+=4){

			// std::cout << "Checking: " << curRow+two << "," << curCol+one << std::endl;
			if ( (in_board_bounds((curRow+two),(curCol+one)) == true) && ( board[curRow+two][curCol+one] == NULL || board[curRow+two][curCol+one]->get_colour()!=colour ))
			{
				legalMoves.push_back(curRow+two);
				legalMoves.push_back(curCol+one);
			}

			// std::cout << "Checking: " << curRow+one << "," << curCol+two << std::endl;
			if ( (in_board_bounds((curRow+one),(curCol+two)) == true) && ( board[curRow+one][curCol+two] == NULL || board[curRow+one][curCol+two]->get_colour()!=colour))
			{
				legalMoves.push_back(curRow+one);
				legalMoves.push_back(curCol+two);
			}
		}
	}
}

Knight::~Knight()
{
	legalMoves.clear();
}