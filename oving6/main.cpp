#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ChessBoard.hpp"
#include "ChessBoardPrint.hpp"

int main() {
  ChessBoard board;
  ChessBoardPrint print(board);

  board.squares[4][0] = std::make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = std:: make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  std::cout << "Invalid moves:" << std::endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  std::cout << std::endl;

  std::cout << "A simulated game:" << std::endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
