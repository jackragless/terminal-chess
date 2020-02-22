#include <string>
#include <iostream>
#include <vector>
#include <cstddef> 

#include "piece.h"

Piece::Piece()
{
	colour = 0;
	type = "generic piece";
	sprite = "G";
	curCol = 0;
	curRow = 0;
	board = NULL;
	hasMoved = false;
}
Piece::Piece(std::string inpType, std::string inpSprite, int inpColour, int inpRow, int inpCol, Piece ***inpBoard)
{
	type = inpType;
	sprite = inpSprite;
	colour = inpColour;
	curCol = inpCol;
	curRow = inpRow;
	board = inpBoard;
	hasMoved = false;
}

int Piece::get_colour()
{
	return colour;
}

std::string Piece::get_type()
{
	return type;
}

void Piece::change_position(int inpRow, int inpCol)
{
	curRow = inpRow;
	curCol = inpCol;
}

std::string Piece::get_sprite()
{
	return sprite;
}

bool Piece::in_board_bounds(int inpRow, int inpCol)
{
	// std::cout << "Bounds checking: " << inpRow << "," << inpCol << std::endl;
	if(inpRow<0 || inpRow>7 || inpCol<0 || inpCol>7)
	{
		// std::cout << "false\n";
		return false;
	}
	// std::cout << "true\n";
	return true;
}

bool Piece::is_legal_move(int inpRow, int inpCol)
{
	for(int i = 0; i<legalMoves.size(); i+=2)
	{
		if(legalMoves[i] == inpRow)
		{
			if(legalMoves[i+1] == inpCol)
			{
				return true;
			}
		}
	}
	return false;
}

std::vector<int> Piece::get_legal_moves()
{
	return legalMoves;
}

void Piece::print_legal_moves()
{
	for(int i = 0; i<legalMoves.size(); i+=2)
	{
		std::cout<<legalMoves[i]<<" "<<legalMoves[i+1]<<std::endl;
	}
}

void Piece::print_piece()
{
	std::cout<< "\nType: " << type
		<< "\nColour: " << colour
		<< "\nSprite: " << sprite
		<< "\nPosition: " << curRow << ", " << curCol
		<< "\n";
}

void Piece::set_hasMoved(bool iHasMoved)
{
	hasMoved = iHasMoved;
}

Piece::~Piece()
{
	// legalMoves.clear();
}