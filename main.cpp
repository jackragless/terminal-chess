#include <string>
#include <iostream>
#include <cctype>
#include <limits> // for clearing input stream

#include "piece.h"
#include "board.h"

// for pawn promotion
// #include "queen.h"
// #include "bishop.h"
// #include "knight.h"
// #include "rook.h"

bool in_board_bounds(int iRow, int iCol)
{
	if(iRow<0 || iRow>7 || iCol<0 || iCol>7)
	{
		return false;
	}
	return true;
}

int main()
{
	int loopCount = 0;
	int turnColour;

	Board mainBoard = Board();
	mainBoard.fill_board();

	std::cout << "\nHow to play:\nEnter the coordinates of the piece you want to move and the position to move it to.\neg. A1 A3\n";

	// main game loop
	while(mainBoard.check_if_winner()==-1)
	{
		
		mainBoard.print_board();

		turnColour = loopCount%2; // 0 for white, 1 for black

		std::string playerLabels[2] = {"White","white"};
		if (turnColour == 1)
		{ playerLabels[0] = "Black"; playerLabels[1] = "black";}

		std::string iCurPos;
		int iCurRow;
		int iCurCol;
		std::string iNewPos;
		int iNewRow;
		int iNewCol;

		Piece* chosenPiece;
		

		bool valid_move = false;
		while(valid_move == false)
		{
			std::cout << std::endl;
			// get inputs
			std::cout << playerLabels[0] << " move: ";
			std::cin >> iCurPos;
			// check for user end game
			if (iCurPos == "end")
			{
				goto exitGameLoop;
			}
			// get second coord
			std::cin >> iNewPos;
			// clear input stream (ignore until end of line character)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << std::endl;

			// test inputs from text files
			// std::cout << "Your input: " << iCurPos << " " << iNewPos << "\n";

			// check input size
			if (iCurPos.length()!=2 || iNewPos.length()!=2) 
			{
				std::cout << "Invalid input!\nMust follow format: A1 -- G8.\n";
				continue;
			}
			
			// coordinate conversion
			iCurCol = tolower(iCurPos[0])-'a';
			// std::cout << "\niCurCol: " << iCurCol;
			iCurRow = 7-(iCurPos[1]-'1');
			// std::cout << "\niCurRow: " << iCurRow;
			iNewCol = tolower(iNewPos[0])-'a';
			// std::cout << "\niNewCol: " << iNewCol;
			iNewRow = 7-(iNewPos[1]-'1');
			// std::cout << "\niNewRow: " << iNewRow;
			
			// check bounds
			// 		current row 			current column				  new row 					new column
			if(iCurRow<0 || iCurRow>7 || iCurCol<0 || iCurCol>7 || iNewRow<0 || iNewRow>7 || iNewCol<0 || iNewCol>7)
			{
				std::cout<<"Move out of bounds!\nMust follow format: A1 -- G8.\n";
				continue;
			}
			
			// check selected piece is valid
			if(mainBoard.get_piece_at(iCurRow,iCurCol)==NULL || mainBoard.get_piece_at(iCurRow,iCurCol)->get_colour()!=turnColour)
			{
				std::cout<<"This position does not contain one of your pieces.\n";
				continue;
			}
			
			// get legal moves
			chosenPiece = mainBoard.get_piece_at(iCurRow,iCurCol);
			chosenPiece->scan_legal_moves();
			// check if any valid moves
			if(mainBoard.get_piece_at(iCurRow,iCurCol)->get_legal_moves().size()==0)
			{
				std::cout<<"The piece you selected has no possible moves at this time.\n";
				continue;
			}
			// check if input move is legal
			if(chosenPiece->is_legal_move(iNewRow,iNewCol) == false)
			{
				std::cout << "Wait. Thats illegal.\n";
				continue;
			}
			valid_move = true;
		} // end valid move loop
		// move piece
		mainBoard.move_piece(iCurRow,iCurCol,iNewRow,iNewCol);

		// pawn promotion
		if ( mainBoard.get_piece_at(iNewRow, iNewCol)->get_type() == "pawn" && iNewRow == ((turnColour)*7))
			// if color is white (0), row = 0 / if color is black (1) row = 7) (opposite to starting side)
		{
			mainBoard.print_board();
			std::cout << "Pawn promotinon!\n";
			std::string iPromotionType;

			// get valid pawn promotion input
			bool valid_promotion = false;
			while (valid_promotion == false)
			{
				std::cout << "Enter \"queen\", \"bishop\", \"knight\" or \"rook\".\n";
				std::cout << "Promote "<< playerLabels[1] << " pawn to: ";
				std::cin >> iPromotionType;
				std::cout << std::endl;
				for (int i = 0; i<iPromotionType.size()/sizeof(std::string); i++)
				{
					iPromotionType[i] = tolower(iPromotionType[i]);
				}
				if (iPromotionType != "queen" && iPromotionType != "bishop" && iPromotionType != "knight" && iPromotionType != "rook")
				{
					std::cout << "Invalid promotion!\n";
					continue;
				}
				valid_promotion = true;
			}
			// promote pawn
			mainBoard.promote_piece(iNewRow,iNewCol,iPromotionType[0],turnColour);
		} // end pawn promotion if statement
		loopCount++;
	} // end turns loop
	mainBoard.print_board(); // prints game-ending move
	exitGameLoop:
	// std::cout << "Exited loop\n";

	if(mainBoard.check_if_winner()==0)
	{ 
		std::cout<<"\nGAME OVER!\nWhite Wins!\n\n";
	}
	else if(mainBoard.check_if_winner()==1)
	{
		std::cout<<"\nGAME OVER!\nBlack Wins!\n\n";
	}
	else
	{
		std::cout << "\nGame ended\n\n";
	}

	return 0;
}