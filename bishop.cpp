#include <string>
#include <vector>
#include <cstddef> 

#include "piece.h"
#include "bishop.h"

Bishop::Bishop() : Piece(){
	type = "bishop";
	sprite = 'B';
}

Bishop::Bishop(int inpColour, int inpRow, int inpCol, Piece ***inpBoard) : Piece("bishop","B", inpColour, inpRow, inpCol, inpBoard)
{}

void Bishop::scan_legal_moves(){
	legalMoves.clear();
	int i=1;
	while(curRow+i<8 && curCol+i<8)
	{
		if(board[curRow+i][curCol+i]==NULL)
		{
			legalMoves.push_back(curRow+i);
			legalMoves.push_back(curCol+i);
		}
		else if(board[curRow+i][curCol+i]->colour!=colour)
		{
			legalMoves.push_back(curRow+i);
			legalMoves.push_back(curCol+i);
			break;
		}
		else
		{
			break;
		}
		i++;
	}
	i=1;
	while(curRow-i>=0 && curCol-i>=0)
	{
		if(board[curRow-i][curCol-i]==NULL)
		{
			legalMoves.push_back(curRow-i);
			legalMoves.push_back(curCol-i);
		}
		else if(board[curRow-i][curCol-i]->colour!=colour)
		{
			legalMoves.push_back(curRow-i);
			legalMoves.push_back(curCol-i);
			break;
		}
		else
		{
			break;
		}
		i++;
	}
	i=1;
	while(curRow+i<8 && curCol-i>=0)
	{
		if(board[curRow+i][curCol-i]==NULL)
		{
			legalMoves.push_back(curRow+i);
			legalMoves.push_back(curCol-i);
		}
		else if(board[curRow+i][curCol-i]->colour!=colour)
		{
			legalMoves.push_back(curRow+i);
			legalMoves.push_back(curCol-i);
			break;
		}
		else
		{
			break;
		}
		i++;
	}
	i=1;
	while(curRow-i>=0 && curCol+i<8)
	{
		if(board[curRow-i][curCol+i]==NULL)
		{
			legalMoves.push_back(curRow-i);
			legalMoves.push_back(curCol+i);
		}
		else if(board[curRow-i][curCol+i]->colour!=colour)
		{
			legalMoves.push_back(curRow-i);
			legalMoves.push_back(curCol+i);
			break;
		}
		else
		{
			break;
		}
		i++;
	}
}

Bishop::~Bishop()
{
	legalMoves.clear();
}