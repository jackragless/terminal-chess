#include <string>
#include <iostream>
#include <cctype>
#include <limits> // for clearing input stream

#include "piece.h"
#include "board.h"

// for pawn promotion
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"

// bool in_board_bounds(int iRow, int iCol)
// {
// 	if(iRow<0 || iRow>7 || iCol<0 || iCol>7)
// 	{
// 		return false;
// 	}
// 	return true;
// }

int main()
{
	// int loopCount = 0;
	// int turnColour;

	Board mainBoard = Board();
	mainBoard.fill_board();

	// TEST queen - custom board
	// mainBoard.move_piece(7,3,4,4); // move white queen out
	// Piece* testQueen = mainBoard.get_piece_at(4,4); // save queen ptr to print moves
	// // test rook
	// mainBoard.move_piece(7,0,5,2);
	// Piece* testRook = mainBoard.get_piece_at(5,2);
	// TEST PAWN PROMOTION
	

	// std::cout << "\nEnter the coordinates of the piece you want to move and the position to move it to.\neg. A1 A3\n";

	// // main game loop
	// while(mainBoard.check_if_winner()==-1)
	// {
		
		mainBoard.print_board();


		//TEST - Print queen moves
		// testQueen->scan_legal_moves();
		// std::cout << "Queen legal moves:\n";
		// testQueen->print_legal_moves();
		// std::cout << "Rook legal moves:\n";
		// testRook->scan_legal_moves();
		// testRook->print_legal_moves();


		// turnColour = loopCount%2; // 0 for white, 1 for black

		// std::string playerLabels[2] = {"White","white"};
		// if (turnColour == 1)
		// { playerLabels[0] = "Black"; playerLabels[1] = "black";}

		// std::string iCurPos;
		// int iCurRow;
		// int iCurCol;
		// std::string iNewPos;
		// int iNewRow;
		// int iNewCol;

		// Piece* chosenPiece;
		

		// bool valid_move = false;
		// while(valid_move == false)
		// {
		// 	std::cout << std::endl;
		// 	// get inputs
		// 	std::cout << playerLabels[0] << " move: ";
		// 	std::cin >> iCurPos >> iNewPos;
		// 	// clear input stream (ignore until end of line character)
		// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		// 	std::cout << std::endl;

		// 	// check input size
		// 	if (iCurPos.length()!=2 || iNewPos.length()!=2) 
		// 	{
		// 		std::cout << "Invalid input!\nCurrent position coordinates must contain exactly 2 elements! eg A2\n";
		// 		continue;
		// 	}
			
		// 	// coordinate conversion
		// 	iCurCol = tolower(iCurPos[0])-'a';
		// 	// std::cout << "\niCurCol: " << iCurCol;
		// 	iCurRow = 7-(iCurPos[1]-'1');
		// 	// std::cout << "\niCurRow: " << iCurRow;
		// 	iNewCol = tolower(iNewPos[0])-'a';
		// 	// std::cout << "\niNewCol: " << iNewCol;
		// 	iNewRow = 7-(iNewPos[1]-'1');
		// 	// std::cout << "\niNewRow: " << iNewRow;
			
		// 	// check bounds
		// 	if(in_board_bounds(iCurRow,iCurCol) == false || in_board_bounds(iNewRow,iNewCol) == false)
		// 	{
		// 		std::cout<<"Invalid input!\nMust follow format: A1 -- G8.\n";
		// 		continue;
		// 	}
			
		// 	// check selected piece is valid
		// 	if(mainBoard.get_piece_at(iCurRow,iCurCol)==NULL || mainBoard.get_piece_at(iCurRow,iCurCol)->get_colour()!=turnColour)
		// 	{
		// 		std::cout<<"Invalid input!\nThis position does not contain one of your pieces.\n";
		// 		continue;
		// 	}
			
			// get legal moves
			mainBoard.get_piece_at(0,0)->scan_legal_moves();
			mainBoard.get_piece_at(0,0)->print_legal_moves();
			// check if any valid moves
	
	// 		if(mainBoard.get_piece_at(iCurRow,iCurCol)->get_legal_moves().size()==0)
	// 		{
	// 			std::cout<<"Invalid input!\nThe piece you selected has no possible moves at this time.\n";
	// 			continue;
	// 		}
	// 		// check if input move is legal
	// 		if(chosenPiece->is_legal_move(iNewRow,iNewCol) == false)
	// 		{
	// 			std::cout << "Move is illegal!\n";
	// 			continue;
	// 		}
	// 		// move piece
	// 		mainBoard.move_piece(iCurRow,iCurCol,iNewRow,iNewCol);
	// 		valid_move = true;
	// 	}

	// 	// pawn promotion
	// 	if ( mainBoard.get_piece_at(iNewRow, iNewCol)->get_type() == "pawn" && iNewRow == ((turnColour)*7))
	// 		// if color is white (0), row = 0 / if color is black (1) row = 7) (opposite to starting side)
	// 	{
	// 		mainBoard.print_board();
	// 		std::cout << "Pawn promotinon!\n";
	// 		std::string iPromotionType;

	// 		// get valid input
	// 		bool valid_promotion = false;
	// 		while (valid_promotion == false)
	// 		{
	// 			std::cout << "Enter \"queen\", \"bishop\", \"knight\" or \"rook\".\n";
	// 			std::cout << "Promote "<< playerLabels[1] << " pawn to: ";
	// 			std::cin >> iPromotionType;
	// 			std::cout << std::endl;
	// 			for (int i = 0; i<iPromotionType.size()/sizeof(std::string); i++)
	// 			{
	// 				iPromotionType[i] = tolower(iPromotionType[i]);
	// 			}
	// 			if (iPromotionType != "queen" && iPromotionType != "bishop" && iPromotionType != "knight" && iPromotionType != "rook")
	// 			{
	// 				std::cout << "Invalid promotion!\n";
	// 				continue;
	// 			}
	// 			valid_promotion = true;
	// 		}
	// 		// delete old piece
	// 		mainBoard.delete_piece_at(iNewRow,iNewCol);
	// 		// add new piece
	// 		switch (iPromotionType[0])
	// 		{
	// 			case 'q': // queen
	// 			mainBoard.add_piece(new Queen(turnColour,iNewRow,iNewCol,mainBoard.get_pieceArray()), iNewRow, iNewCol); break;
	// 			case 'b': // bishop
	// 			mainBoard.add_piece(new Bishop(turnColour,iNewRow,iNewCol,mainBoard.get_pieceArray()), iNewRow, iNewCol); break;
	// 			case 'k': // knight
	// 			mainBoard.add_piece(new Knight(turnColour,iNewRow,iNewCol,mainBoard.get_pieceArray()), iNewRow, iNewCol); break;
	// 			case 'r': // rook
	// 			mainBoard.add_piece(new Rook(turnColour,iNewRow,iNewCol,mainBoard.get_pieceArray()), iNewRow, iNewCol); break;
	// 			default: 
	// 			std::cout << "promotion type input error\n"; break;
	// 		}
	// 	}
	// 	loopCount++;
	// }

	// if(mainBoard.check_if_winner()==0)
	// { 
	// 	std::cout<<"GAME OVER! Player 1 Wins!";
	// }
	// else if(mainBoard.check_if_winner()==1)
	// {
	// 	std::cout<<"GAME OVER! Player 2 Wins!";
	// }

	return 0;
}