#include <iostream>
#include <string>
#include <cstddef>

#include "board.h"
#include "piece.h"
#include "rook.h"
#include "pawn.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "queen.h"


Board::Board()
{
	winner = -1; // -1 no winner, 0 white winner, 1 black winner

	// fill with null pointers
	pieceArray = new Piece**[8];
	for (int i = 0; i<8; i++)
	{
		pieceArray[i] = new Piece*[8];
		for (int j = 0; j<8; j++)
		{
			pieceArray[i][j] = NULL;
		}
	}
}

Piece*** Board::get_pieceArray() // returns piece array pointer for pieces to use
{
	return pieceArray;
}

void Board::fill_board()
{	// King
	// black
	pieceArray[0][4] = new King(1,0,4,pieceArray);
	// white
	pieceArray[7][4] = new King(0,7,4,pieceArray);

	// Queen
	// black
	pieceArray[0][3] = new Queen(1,0,3,pieceArray);
	// white
	pieceArray[7][3] = new Queen(0,7,3,pieceArray);

	// Bishops
	// black
	pieceArray[0][2]  = new Bishop(1,0,2,pieceArray);
	pieceArray[0][5]  = new Bishop(1,0,5,pieceArray);
	// white
	pieceArray[7][2]  = new Bishop(0,7,2,pieceArray);
	pieceArray[7][5]  = new Bishop(0,7,5,pieceArray);

	//Knights
	// black
	pieceArray[0][1]  = new Knight(1,0,1,pieceArray);
	pieceArray[0][6]  = new Knight(1,0,6,pieceArray);
	// white
	pieceArray[7][1]  = new Knight(0,7,1,pieceArray);
	pieceArray[7][6]  = new Knight(0,7,6,pieceArray);

	// Rooks
	// black
	pieceArray[0][0] = new Rook(1,0,0,pieceArray);
	pieceArray[0][7] = new Rook(1,0,7,pieceArray);
	// white
	pieceArray[7][0] = new Rook(0,7,0,pieceArray);
	pieceArray[7][7] = new Rook(0,7,7,pieceArray);
	
	// Pawns
	for (int i = 0; i<8; i++)
	{
		// black
		pieceArray[1][i] = new Pawn(1,1,i,pieceArray);
		// white
		pieceArray[6][i] = new Pawn(0,6,i,pieceArray);
	}
}

void Board::move_piece(int oldRow, int oldCol, int newRow, int newCol) // does not check if valid
{
	// check if king taken
	if (pieceArray[newRow][newCol] != NULL && pieceArray[newRow][newCol]->get_type() == "king")
	{
		winner = abs( ( pieceArray[newRow][newCol]->get_colour() )-1 ); // opposite of king taken (who one)
	}

	// move piece
	// delete piece in new position
	if (pieceArray[newRow][newCol] != NULL)
	{
		delete pieceArray[newRow][newCol]; 
	}
	// copy piece ptr to new position
	pieceArray[newRow][newCol] = pieceArray[oldRow][oldCol];
	// remove ptr in old position
	pieceArray[oldRow][oldCol] = NULL;

	// update piece position
	pieceArray[newRow][newCol]->change_position(newRow,newCol);
	// update piece hasMoved
	pieceArray[newRow][newCol]->set_hasMoved(true);
}

void Board::add_piece(Piece* inpPiece, int inpRow, int inpCol) // adds piece at location
{
	pieceArray[inpRow][inpCol] = inpPiece;
}

void Board::delete_piece_at(int inpRow, int inpCol)
{
	delete pieceArray[inpRow][inpCol];
	pieceArray[inpRow][inpCol] = NULL;
}

Piece* Board::get_piece_at(int inpRow, int inpCol) // returns piece pointer at position
{
	// if (pieceArray[inpRow][inpCol] == NULL)
	// {
	// 	std::cout << "\nget_piece_at: no piece at position\n";
	// }
	return pieceArray[inpRow][inpCol];
}

void Board::print_board()
{	
	// ansi rgb escape sequences - R;G;B
	std::string blackSquareColour = "156;105;49"; 
	std::string whiteSquareColour = "200;157;89";

	// ansi 16 bit escape sequences - bold;underlined;overlined;foreground:16bit:colour
	// Old formats: black over+underline = "1;4;53;38:5:16"	white over+underline "1;4;53;38:5:15"
	std::string blackPieceColour = "1;38:5:16"; 
	std::string whitePieceColour = "1;38:5:15"; 

	// Format Variables
	std::string whiteFormat = "\033[38;2;"+whiteSquareColour+"m";
	std::string blackFormat = "\033[38;2;"+blackSquareColour+"m";
	std::string format = "\033[38;2;"+whiteSquareColour+";48;2;"+blackSquareColour+"m";
	std::string endFormat = "\033[0m";

	std::string TBletters =     "          A      B      C      D      E      F      G      H          ";
	
	// Print Top Border
	std::cout << "\n" << whiteFormat+"      ▄"+endFormat;
	for (int l = 0; l<4; l++)
	{
		std::cout << blackFormat+"▄▄▄▄▄▄▄"+whiteFormat+"▄▄▄▄▄▄▄"+endFormat;
	}
	std::cout << blackFormat+"▄"+endFormat << std::endl;


	for (int i = 0; i<8; i++) // itterate rows
	{
		// row numbers
		int sideNumbers = 8-i;

		// borders for even rows
		std::string sideBorderLL = "   "; // left side border to the left of column numbers
		std::string sideBorderLR = "  "+format+" "+endFormat; // left side border to right of column numbers
		std::string sideBorderRL = whiteFormat+"█  "+endFormat; // right side border to left of column numbers
		std::string sideBorderRR = "   "; // right side border to right of column numbers
		// top and bottom for each row (without piece symbol)
		std::string lineSequence = format+"███████       ███████       ███████       ███████       "+endFormat;
		
		// borders for odd rows - overrides even row formatting
		if(i%2 != 0) 
		{
			sideBorderLL = "   ";
			sideBorderLR = whiteFormat+"  █"+endFormat;
			sideBorderRL = format+" "+endFormat+"  ";
			sideBorderRR = "   ";
			// top and bottom for each row (without piece symbol)
			lineSequence = format+"       ███████       ███████       ███████       ███████"+endFormat;
		}

		// Squares: Top Line
		std::cout << sideBorderLL << " " << sideBorderLR << lineSequence << sideBorderRL << " " << sideBorderRR << std::endl;


		// Squares: Middle line
		// std::cout << sideBorderLL << 8-i << sideBorderLR;
		std::cout << sideBorderLL << " " << sideBorderLR;
		for (int j = 0; j<8; j++)
		{
			// Black square formatting
			std::string wordSpaceL = format+"   "+endFormat; // format on left of sprite
			std::string wordSpaceR = format+"   "+endFormat; // format on right of sprite
			std::string nullSpace = format+"       "+endFormat; // if no sprite at location
			std::string bkgroundColour = blackSquareColour;
		
			// White square formatting - overrides black
			if ((i+j)%2 == 0)
			{
				wordSpaceL = format+"███"+endFormat;
				wordSpaceR = format+"███"+endFormat;
				nullSpace = format+"███████"+endFormat;
				bkgroundColour = whiteSquareColour;
			}

			// Print square with sprite
			if (pieceArray[i][j] == NULL)
			{
				std::cout << nullSpace;
			}
			else
			{
				if(pieceArray[i][j]->get_colour() == 0) // white piece sprite
				{
					std::cout << wordSpaceL << "\033["+whitePieceColour+";48;2;"+bkgroundColour+"m"+pieceArray[i][j]->get_sprite()+endFormat << wordSpaceR;
				}
				else // black piece sprite
				{
					std::cout << wordSpaceL << "\033["+blackPieceColour+";48;2;"+bkgroundColour+"m"+pieceArray[i][j]->get_sprite()+endFormat << wordSpaceR;
				} 
			}
			
		}
		// print right border
		std::cout << sideBorderRL << sideNumbers << sideBorderRR << std::endl;

		// Squares: Bottom line
		std::cout << sideBorderLL << " " << sideBorderLR << lineSequence << sideBorderRL << " " << sideBorderRR << std::endl;
	}
	// Print Bottom Border
	std::cout << blackFormat+"      ▀"+endFormat;
	for (int l = 0; l<4; l++)
	{
		std::cout << whiteFormat+"▀▀▀▀▀▀▀"+blackFormat+"▀▀▀▀▀▀▀"+endFormat;
	}
	std::cout << whiteFormat+"▀"+endFormat << std::endl;

	// Print Bottom letters
	std::cout << TBletters <<"\n\n";
}

int Board::castling_condition(int player)
{
	return 0;
}

int Board::check_if_winner()
{
	return winner;
}

// promotes piece at iRow iCol to type typeChar (q,b,k,r) with colour iColour
// (for pawn promotion)
void Board::promote_piece(int iRow, int iCol, char typeChar, int iColour)
{
	// delete old piece
	delete pieceArray[iRow][iCol];
	// add new piece
	switch (typeChar)
	{
		case 'q': // queen
		pieceArray[iRow][iCol] = new Queen(iColour,iRow,iCol,pieceArray); break;
		case 'b': // bishop
		pieceArray[iRow][iCol] = new Bishop(iColour,iRow,iCol,pieceArray); break;
		case 'k': // knight
		pieceArray[iRow][iCol] = new Knight(iColour,iRow,iCol,pieceArray); break;
		case 'r': // rook
		pieceArray[iRow][iCol] = new Rook(iColour,iRow,iCol,pieceArray); break;
		default: 
		std::cout << "promotion type input error\n"; break;
	}
}

Board::~Board()
{
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j<8; j++)
		{
			delete pieceArray[i][j];
		}
		delete[] pieceArray[i];
	}
	delete[] pieceArray;
}