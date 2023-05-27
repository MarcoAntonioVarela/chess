/***********************************************************************
 * Source File:
 *    Definition of the Board class
 * Author:
 *    Efrain Gomez & Marco Varela
 * Summary:
 *    The Board has all the pieces, and helps each piece know where to move
 ************************************************************************/
#include "board.h"

Board::Board()
{
   reset();
}

void Board::reset()
{

   //board[row][column] = new Piece(Position("chees coodrinate"));

   // Black pieces
   board[0][0] = new Rook(Position("a8"), false);
   board[0][1] = new Knight(Position("b8"), false);
   board[0][2] = new Bishop(Position("c8"), false);
   board[0][3] = new Queen(Position("d8"), false);
   board[0][4] = new King(Position("e8"), false);
   board[0][5] = new Bishop(Position("f8"), false);
   board[0][6] = new Knight(Position("g8"), false);
   board[0][7] = new Rook(Position("h8"), false);

   board[1][0] = new Pawn(Position("a7"), false);
   board[1][1] = new Pawn(Position("b7"), false);
   board[1][2] = new Pawn(Position("c7"), false);
   board[1][3] = new Pawn(Position("d7"), false);
   board[1][4] = new Pawn(Position("e7"), false);
   board[1][5] = new Pawn(Position("f7"), false);
   board[1][6] = new Pawn(Position("g7"), false);
   board[1][7] = new Pawn(Position("h7"), false);

   //Spaces
   board[2][0] = new Space(Position("a6"));
   board[2][1] = new Space(Position("b6"));
   board[2][2] = new Space(Position("c6"));
   board[2][3] = new Space(Position("d6"));
   board[2][4] = new Space(Position("e6"));
   board[2][5] = new Space(Position("f6"));
   board[2][6] = new Space(Position("g6"));
   board[2][7] = new Space(Position("h6"));

   board[3][0] = new Space(Position("a5"));
   board[3][1] = new Space(Position("b5"));
   board[3][2] = new Space(Position("c5"));
   board[3][3] = new Space(Position("d5"));
   board[3][4] = new Space(Position("e5"));
   board[3][5] = new Space(Position("f5"));
   board[3][6] = new Space(Position("g5"));
   board[3][7] = new Space(Position("h5"));

   board[4][0] = new Space(Position("a4"));
   board[4][1] = new Space(Position("b4"));
   board[4][2] = new Space(Position("c4"));
   board[4][3] = new Space(Position("d4"));
   board[4][4] = new Space(Position("e4"));
   board[4][5] = new Space(Position("f4"));
   board[4][6] = new Space(Position("g4"));
   board[4][7] = new Space(Position("h4"));

   board[5][0] = new Space(Position("a3"));
   board[5][1] = new Space(Position("b3"));
   board[5][2] = new Space(Position("c3"));
   board[5][3] = new Space(Position("d3"));
   board[5][4] = new Space(Position("e3"));
   board[5][5] = new Space(Position("f3"));
   board[5][6] = new Space(Position("g3"));
   board[5][7] = new Space(Position("h3"));

   // White pieces
   board[6][0] = new Pawn(Position("a1"), true);
   board[6][1] = new Pawn(Position("b1"), true);
   board[6][2] = new Pawn(Position("c1"), true);
   board[6][3] = new Pawn(Position("d1"), true);
   board[6][4] = new Pawn(Position("e1"), true);
   board[6][5] = new Pawn(Position("f1"), true);
   board[6][6] = new Pawn(Position("g1"), true);
   board[6][7] = new Pawn(Position("h1"), true);

   board[7][0] = new Rook(Position("a2"), true);
   board[7][1] = new Knight(Position("b2"), true);
   board[7][2] = new Bishop(Position("c2"), true);
   board[7][3] = new Queen(Position("d2"), true);
   board[7][4] = new King(Position("e2"), true);
   board[7][5] = new Bishop(Position("f"), true);
   board[7][6] = new Knight(Position("g2"), true);
   board[7][7] = new Rook(Position("h2"), true);
}

void Board::swap(Position& point1, Position& point2)
{
   Piece* temp = board[point1.getRow()][point1.getCol()];
   board[point1.getRow()][point1.getCol()] = board[point2.getRow()][point2.getCol()];
   board[point2.getRow()][point2.getCol()] = temp;
}

Piece& Board::operator[](const Position& point)
{
   return *board[point.getRow()][point.getCol()];
}

Piece& Board::operator[](const Position& point) const
{
   return *board[point.getRow()][point.getCol()];
}

// Placing a piece to the board using the = operator
void Board::operator=(Piece& piece)
{
   board[piece.getPosition().getRow()][piece.getPosition().getCol()] = &piece;
}

void Board::operator-=(const Position& position)
{
   board[position.getRow()][position.getCol()] = new Space(position);
}
