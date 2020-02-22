#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

class Board
{
public:
	Board();
	int winner; // -1 if no winner, 0 if white, 1 if black
	Piece*** pieceArray;
	Piece*** get_pieceArray();
	void fill_board();
	void move_piece(int oldRow, int oldCol, int newRow, int newCol);
	void add_piece(Piece* inpPiece, int inpRow, int inpCol);
	void delete_piece_at(int inpRow, int inpCol);
	Piece* get_piece_at(int inpRow, int inpCol);
	void print_board();
	int castling_condition(int player); // returns 0 if none, 
	int check_if_winner();
	void promote_piece(int iRow, int iCol, char typeChar, int iColour);
	~Board();
};
#endif