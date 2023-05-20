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


   // Spaces

   board[2][0] = new Space("c1");
   board[2][1] = new Space("c2");
   board[2][2] = new Space("c3");
   board[2][3] = new Space("c4");
   board[2][4] = new Space("c5");
   board[2][5] = new Space("c6");
   board[2][6] = new Space("c7");
   board[2][7] = new Space("c8");


   board[3][0] = new Space("e1");
   board[3][1] = new Space("e2");
   board[3][2] = new Space("e3");
   board[3][3] = new Space("e4");
   board[3][4] = new Space("e5");
   board[3][5] = new Space("e6");
   board[3][6] = new Space("e7");
   board[3][7] = new Space("e8");


   board[4][0] = new Space("d1");
   board[4][1] = new Space("d2");
   board[4][2] = new Space("d3");
   board[4][3] = new Space("d4");
   board[4][4] = new Space("d5");
   board[4][5] = new Space("d6");
   board[4][6] = new Space("d7");
   board[4][7] = new Space("d8");


   board[5][0] = new Space("c1");
   board[5][1] = new Space("c2");
   board[5][2] = new Space("c3");
   board[5][3] = new Space("c4");
   board[5][4] = new Space("c5");
   board[5][5] = new Space("c6");
   board[5][6] = new Space("c7");
   board[5][7] = new Space("c8");




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
   return *board[point.getRow()][point.getCol()];
}

Piece& Board::operator[](const Position& point) const
{
   return *board[point.getRow()][point.getCol()];
}

// Placing a piece to the board using the = operator
void Board::operator=(const Piece& piece) 
{
   *board[piece.getPosition().getRow()][piece.getPosition().getCol()] = piece;
}