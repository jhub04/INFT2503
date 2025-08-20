#include "ChessBoardPrint.hpp"
#include <iostream>

ChessBoardPrint::ChessBoardPrint(ChessBoard &board) {
  board.on_piece_move = [](const ChessBoard::Piece &piece, const std::string &from, const std::string &to) {
    std::cout << piece.type() << " is moving from " << from << " to " << to << std::endl;
  };
  board.on_piece_removed = [](const ChessBoard::Piece &piece, const std::string &square) {
    std::cout << piece.type() << " is being removed from " << square << std::endl;
  };
  board.on_lost_game = [](ChessBoard::Color color) {
    if (color == ChessBoard::Color::WHITE)
      std::cout << "Black";
    else
      std::cout << "White";
    std::cout << " won the game" << std::endl;
  };
  board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const std::string &from, const std::string &to) {
    std::cout << "can not move " << piece.type() << " from " << from << " to " << to << std::endl;
  };
  board.on_piece_move_missing = [](const std::string &square) {
    std::cout << "no piece at " << square << std::endl;
  };
}
