#include <string>
#include <vector>

#include "piece.h"
#include "rook.h"

Rook::Rook() : Piece()
{
	type = "rook";
	sprite = "R";
}

Rook::Rook(int inpColour, int inpRow, int inpCol, Piece ***inpBoard) : Piece("rook","R", inpColour, inpRow, inpCol, inpBoard)
{}

void Rook::scan_legal_moves(){
	legalMoves.clear();
	// swap sign
	for (int sign = -1; sign<=1; sign+=2)
	{
		// rows
		int i = 1;
		while(curRow+(sign*i)<8 && curRow+(sign*i)>=0)
		{
			if(board[curRow+(sign*i)][curCol]==NULL)
			{
				legalMoves.push_back(curRow+(sign*i));
				legalMoves.push_back(curCol);
			}
			else if(board[curRow+(sign*i)][curCol]->get_colour()!=colour)
			{
				legalMoves.push_back(curRow+(sign*i));
				legalMoves.push_back(curCol);
				break;
			}
			else if(board[curRow+(sign*i)][curCol]->get_colour()==colour)
			{
				break;
			}
			i++;
		}
		//  columns
		i=1;
		while(curCol+(sign*i)<8 && curCol+(sign*i)>=0)
		{
			if(board[curRow][curCol+(sign*i)]==NULL)
			{
				legalMoves.push_back(curRow);
				legalMoves.push_back(curCol+(sign*i));
			}
			else if(board[curRow][curCol+(sign*i)]->get_colour()!=colour)
			{
				legalMoves.push_back(curRow);
				legalMoves.push_back(curCol+(sign*i));
				break;
			}
			else if(board[curRow][curCol+(sign*i)]->get_colour()==colour)
			{
				break;
			}
			i++;
		}
	}
}

Rook::~Rook()
{
	legalMoves.clear();
}