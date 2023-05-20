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

   // Black pieces
   board[1][0] = new Pawn("g1", false);
   board[1][1] = new Pawn("g2", false);
   board[1][2] = new Pawn("g3", false);
   board[1][3] = new Pawn("g4", false);
   board[1][4] = new Pawn("g5", false);
   board[1][5] = new Pawn("g6", false);
   board[1][6] = new Pawn("g7", false);
   board[1][7] = new Pawn("g8", false);

   // White pieces
   board[6][0] = new Pawn("b1", true);
   board[6][1] = new Pawn("b2", true);
   board[6][2] = new Pawn("b3", true);
   board[6][3] = new Pawn("b4", true);
   board[6][4] = new Pawn("b5", true);
   board[6][5] = new Pawn("b6", true);
   board[6][6] = new Pawn("b7", true);
   board[6][7] = new Pawn("b8", true);

}

Piece& Board::operator[](const Position& point)
{
   return *board[point.getY()][point.getX()];
}

Piece& Board::operator[](const Position& point) const
{
   return *board[point.getY()][point.getX()];
}

// Placing a piece to the board using the = operator
void Board::operator=(const Piece& piece) 
{
   *board[piece.getPosition().getRow()][piece.getPosition().getCol()] = piece;
}
