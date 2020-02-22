tests: test-king-main.cpp test-knight-main.cpp test-pawnPromotion-main.cpp piece.cpp board.cpp test-king-board.cpp test-knight-board.cpp rook.cpp pawn.cpp bishop.cpp king.cpp knight.cpp queen.cpp
	clang++ test-king-main.cpp piece.cpp test-king-board.cpp rook.cpp pawn.cpp bishop.cpp king.cpp knight.cpp queen.cpp -o test-king
	clang++ test-knight-main.cpp piece.cpp test-knight-board.cpp rook.cpp pawn.cpp bishop.cpp king.cpp knight.cpp queen.cpp -o test-knight
	clang++ test-pawnPromotion-main.cpp piece.cpp board.cpp rook.cpp pawn.cpp bishop.cpp king.cpp knight.cpp queen.cpp -o test-pawnPromotion