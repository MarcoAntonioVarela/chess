/***********************************************************************
 * Source File:
 *    Definition of the Board class
 * Author:
 *    Efrain Gomez & Marco Varela
 * Summary:
 *    The Board has all the pieces, and helps each piece know where to move
 ************************************************************************/
#include "board.h"
#include "point.h"
#include "piece.h"

Board::Board()
{
   Piece* piece[8][8] =
   {
      { new Rook("a8", false), new Knight("b8",false), new Bishop("c8",false), new Queen("d8", false), new King("e8", false), new Bishop("f8", false), new Knight("g8", false), new Rook("h8", false) },
      { new Pawn("a7",false), new Pawn("b7",false),   new Pawn("c7",false),   new Pawn("d7",false),  new Pawn("e7",false), new Pawn("f7",false),   new Pawn("g7",false),   new Pawn("h7",false) },
      { new Space("a6"),     new Space("b6"),       new Space("c6"),       new Space("d6"),      new Space("e6"),     new Space("f6"),       new Space("g6"),       new Space("h6") },
      { new Space("a5"),     new Space("b5"),       new Space("c5"),       new Space("d5"),      new Space("e5"),     new Space("f5"),       new Space("g5"),       new Space("h5") },
      { new Space("a4"),     new Space("b4"),       new Space("c4"),       new Space("d4"),      new Space("e4"),     new Space("f4"),       new Space("g4"),       new Space("h4") },
      { new Space("a3"),     new Space("b3"),       new Space("c3"),       new Space("d3"),      new Space("e3"),     new Space("f3"),       new Space("g3"),       new Space("h3") },
      { new Pawn("a2", true),  new Pawn("b2", true),    new Pawn("c2", true),    new Pawn("d2", true),   new Pawn("e2", true),  new Pawn("f2", true),    new Pawn("g2", true),    new Pawn("h2", true) },
      { new Rook("a1", true),  new Knight("b1", true),  new Bishop("c1", true),  new Queen("d1", true),  new King("e1", true),  new Bishop("f1", true),  new Knight("g1", true),  new Rook("h1", true) },
   };
}

Board::operator= (Piece& piece)
{
   pieces[piece.getPosition().getRow()][piece.getPosition().getColumn()] = &piece;
}