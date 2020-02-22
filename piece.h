#include <string>
#include <vector>

#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
	Piece();
	Piece(std::string inpType, std::string inpSprite, int inpColour, int inpRow, int inpCol, Piece*** inpBoard);

	int colour; // 0 = white; 1 = Black
	int get_colour();

	std::string type;
	// "king", "queen", "bishop", "knight", "rook", "pawn"
	std::string get_type();

	int curRow;
	int curCol;
	void change_position(int inpRow, int inpCol);

	std::string sprite;
	std::string get_sprite();

	bool in_board_bounds(int inpRow, int inpCol);

	Piece ***board;

	std::vector<int> legalMoves;
	virtual void scan_legal_moves() = 0;
	std::vector<int> get_legal_moves();
	void print_legal_moves();

	bool is_legal_move(int inpRow, int inpCol); 
	void print_piece();

	bool hasMoved;
	void set_hasMoved(bool iHasMoved);
	
	virtual ~Piece();
	
};
#endif