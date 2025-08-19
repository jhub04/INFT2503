#pragma once
#include <string>
#include <vector>

class ChessBoard {
  public:
    enum class Color { WHITE, BLACK};

    class Piece {
      public:
        Piece(Color color) : color(color) {};
        virtual ~Piece();

        Color color;
        std::string color_string() const {
          if (color == Color::WHITE)
            return "white";
          else
            return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

        virtual char symbol() const = 0;
    };

    class King : public Piece {
      public:
        King(Color color);
        std::string type() const override;
        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
        char symbol() const override;
    };

    class Knight : public Piece {
      public:
        Knight(Color color);
        std::string type() const override;
        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
        char symbol() const override;
    };

    ChessBoard();

    void print();

    std::vector<std::vector<std::unique_ptr<Piece>>> squares;

    bool move_piece(const std::string &from, const std::string &to);


};

