#include "ChessBoard.hpp"
#include <iostream>

ChessBoard::Piece::~Piece() = default;

// Implementations for ChessBoard::King
ChessBoard::King::King(Color color) : Piece(color) {};

std::string ChessBoard::King::type() const {
  return Piece::color_string() + " king";
}

bool ChessBoard::King::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  int dX = abs(to_x - from_x);
  int dY = abs(to_y - from_y);

  return dX <= 1 && dY <= 1 && (dX != 0 || dY != 0) ;
}

char ChessBoard::King::symbol() const {
  return 'K';
}

// Implementations of ChessBoard::Knight
ChessBoard::Knight::Knight(Color color) : Piece(color) {};

std::string ChessBoard::Knight::type() const {
  return Piece::color_string() + " knight";
}

bool ChessBoard::Knight::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  int dX = abs(to_x - from_x);
  int dY = abs(to_y - from_y);

  return dX * dX + dY*dY == 5;
}

char ChessBoard::Knight::symbol() const {
  return 'N';
}

// Implementations of ChessBoard
ChessBoard::ChessBoard() {
  squares.resize(8);
  for (auto &square_column : squares)
    square_column.resize(8);
}

void ChessBoard::print() {
  for (int y = 7; y >= 0; --y) {
    std::cout << (y + 1) << " ";
    for (int x = 0; x < 8; ++x) {
      if (squares[x][y]) {
        std::cout << squares[x][y]->symbol() << " ";
      } else {
        std::cout << ". ";
      }
    }
    std::cout << std::endl;
  }

  std::cout << "  a b c d e f g h" << std::endl << std::endl;
}

bool ChessBoard::move_piece(const std::string &from, const std::string &to) {
  int from_x = from[0] - 'a';
  int from_y = std::stoi(std::string() + from[1]) - 1;
  int to_x = to[0] - 'a';
  int to_y = std::stoi(std::string() + to[1]) - 1;

  auto &piece_from = squares[from_x][from_y];
  if (piece_from) {
    if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
      std::cout << piece_from->type() << " is moving from " << from << " to " << to << std::endl;
      auto &piece_to = squares[to_x][to_y];
      if (piece_to) {
        if (piece_from->color != piece_to->color) {
          std::cout << piece_to->type() << " is being removed from " << to << std::endl;
          if (auto king = dynamic_cast<King *>(piece_to.get()))
            std::cout << king->color_string() << " lost the game" << std::endl;
        } else {
          // piece in the from square has the same color as the piece in the to square
          std::cout << "can not move " << piece_from->type() << " from " << from << " to " << to << std::endl;
          return false;
        }
      }
      piece_to = std::move(piece_from);
      print();
      return true;
    } else {
      std::cout << "can not move " << piece_from->type() << " from " << from << " to " << to << std::endl;
      return false;
    }
  } else {
    std::cout << "no piece at " << from << std::endl;
    return false;
  }

}













