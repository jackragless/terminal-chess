#include <string>
#include <vector>
#include <iostream>
#include <cstddef> 

#include "piece.h"
#include "pawn.h"

Pawn::Pawn() : Piece(){
	type = "pawn";
	sprite = 'P';
}

Pawn::Pawn(int inpColour, int inpRow, int inpCol,Piece ***inpBoard) : Piece("pawn","P", inpColour, inpRow, inpCol, inpBoard)
{}

void Pawn::scan_legal_moves(){
	legalMoves.clear();

	// black pieces
	int forward = 1;
	int startRow = 1;
	
	// white pieces
	if (colour == 0) 
	{
		forward = -1;
		startRow = 6;
	}
	// check square ahead
	if(board[curRow+forward][curCol]==NULL){
		legalMoves.push_back(curRow+forward);
		legalMoves.push_back(curCol);
	}

	// check left diagonal if not on left border
	if(curCol>0 && board[curRow+forward][curCol-1]!= NULL && board[curRow+forward][curCol-1]->colour!=colour){
		legalMoves.push_back(curRow+forward);
		legalMoves.push_back(curCol-1);
	}

	// check right diagonal if not on right border
	if(curCol>0 && board[curRow+forward][curCol-1]!= NULL && board[curRow+forward][curCol-1]->colour!=colour){
		legalMoves.push_back(curRow+forward);
		legalMoves.push_back(curCol+1);
	}

	// starting position 2 forward
	if(curRow==startRow && board[curRow+(2*forward)][curCol]==NULL){
		legalMoves.push_back(curRow+(2*forward));
		legalMoves.push_back(curCol);
	}
}

Pawn::~Pawn()
{
	legalMoves.clear();
}