#include <string>
#include <vector>
#include <cstddef> 

#include "piece.h"
#include "king.h"

King::King() : Piece(){
	type = "king";
	sprite = 'K';
}

King::King(int inpColour, int inpRow, int inpCol, Piece ***inpBoard) : Piece("king","K", inpColour, inpRow, inpCol, inpBoard)
{}

void King::scan_legal_moves(){
	int a = 1, b = 1, c = 1, d = 1;
	if(curRow==0) // bottom border
	{a=0;} 
	if(curRow==7) // top border
	{b=0;}
	if(curCol==0) // left border
	{c=0;}
	if(curCol==7) // right border
	{d=0;}

	for(int i=(curRow-a); i<=(curRow+b); i++)
	{
		for(int j=(curCol-c); j<=(curCol+d); j++)
		{
			if(board[i][j]==NULL || board[i][j]->colour!=colour)
			{
				legalMoves.push_back(i);
				legalMoves.push_back(j);
			}
		}
	}
}

King::~King()
{
	legalMoves.clear();
}