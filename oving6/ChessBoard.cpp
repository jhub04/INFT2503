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

/// Move a chess piece if it is a valid move
bool ChessBoard::move_piece(const std::string &from, const std::string &to) {
  int from_x = from[0] - 'a';
  int from_y = std::stoi(std::string() + from[1]) - 1;
  int to_x = to[0] - 'a';
  int to_y = std::stoi(std::string() + to[1]) - 1;

  auto &piece_from = squares[from_x][from_y];
  if (piece_from) {
    if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
      if (on_piece_move)
        on_piece_move(*piece_from, from, to);
      auto &piece_to = squares[to_x][to_y];
      if (piece_to) {
        if (piece_from->color != piece_to->color) {
          if (on_piece_removed)
            on_piece_removed(*piece_to, to);
          if (auto king = dynamic_cast<King *>(piece_to.get())) {
            if (on_lost_game)
              on_lost_game(king->color);
          }
        } else {
          if (on_piece_move_invalid)
            on_piece_move_invalid(*piece_from, from, to);
          return false;
        }
      }
      piece_to = std::move(piece_from);
      return true;
    } else {
      if (on_piece_move_invalid)
        on_piece_move_invalid(*piece_from, from, to);
      return false;
    }
  } else {
    if (on_piece_move_missing)
      on_piece_move_missing(from);
    return false;
  }
};













