#include <string>
#include <iostream>
#include <cstddef>

#include "board.h"
// #include "piece.h"
// #include "rook.h"
// #include "pawn.h"
// #include "bishop.h"
#include "queen.h"

int main()
{
	Board mainBoard = Board();
	Piece*** pieceBoard = mainBoard.get_pieceArray();
	mainBoard.fill_board();
	mainBoard.print_board();

	// // test - move pawn
	// pieceBoard[6][3]->print_piece();
	// pieceBoard[6][3]->scan_legal_moves();
	// // std::cout << "\ndone\n";
	// std::cout << "legal moves:\n";
	// pieceBoard[6][3]->print_legal_moves();
	// if (pieceBoard[6][3]->is_legal_move(4,3))
	// {
	// 	mainBoard.move_piece(6,3,4,3);
	// }
	// else
	// {
	// 	std::cout << "invalid move\n";
	// }
	// mainBoard.print_board();

	// // test - move bishop
	// pieceBoard[7][2]->print_piece();
	// pieceBoard[7][2]->scan_legal_moves();
	// // std::cout << "\ndone\n";
	// std::cout << "legal moves:\n";
	// pieceBoard[7][2]->print_legal_moves();
	// if (pieceBoard[7][2]->is_legal_move(3,6))
	// {
	// 	mainBoard.move_piece(7,2,3,6);
	// }
	// else
	// {
	// 	std::cout << "invalid move\n";
	// }
	// mainBoard.print_board();
	
	// // test - move king
	// pieceBoard[7][4]->print_piece();
	// pieceBoard[7][4]->scan_legal_moves();
	// // std::cout << "\ndone\n";
	// std::cout << "legal moves:\n";
	// pieceBoard[7][4]->print_legal_moves();
	// if (pieceBoard[7][4]->is_legal_move(6,3))
	// {
	// 	mainBoard.move_piece(7,4,6,3);
	// }
	// else
	// {
	// 	std::cout << "invalid move\n";
	// }
	// mainBoard.print_board();

	// test - move knight
	// pieceBoard[7][1]->print_piece();
	// pieceBoard[7][1]->scan_legal_moves();
	// // std::cout << "\ndone\n";
	// std::cout << "legal moves:\n";
	// pieceBoard[7][1]->print_legal_moves();
	// if (pieceBoard[7][1]->is_legal_move(5,2))
	// {
	// 	mainBoard.move_piece(7,1,5,2);
	// }
	// else
	// {
	// 	std::cout << "invalid move\n";
	// }
	// mainBoard.print_board();
	
	// test - Queen
	// mainBoard.get_piece_at(7,3)->print_piece();
	// Queen* queen1 = new Queen();
	// std::cout << "Default queen constructor (bishop base): \n";
	// queen1->print_piece();
	// delete queen1;
	Piece* curPiece;
	mainBoard.move_piece(1,2,2,2);
	mainBoard.delete_piece_at(1,3);
	mainBoard.print_board();
	curPiece = mainBoard.get_piece_at(0,3);
	curPiece->scan_legal_moves();
	curPiece->print_legal_moves();




	return 0;
}