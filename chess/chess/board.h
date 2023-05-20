/***********************************************************************
 * Heaader File:
 *    Definition of the Board class
 * Author:
 *    Efrain Gomez
 * Summary:
 *    The Board has all the pieces, and helps each piece know where to move
 ************************************************************************/
#pragma once
#include "piece.h"

class Board
{
   private:

      Piece* board[8][8];
//   int currentMove;
//   // ogstream gout;
//   void swap(Point& point1, Point& point2);
//   bool assertBoard();

   public:
      Board();
//   // Board(ogstream gout, bool reset=false);
//   int getCurrentMove() { return currentMove; }
//   bool isWhiteTurn() { return currentMove % 2 == 0; }
      void reset(); // Pieces back to the original position.
//   void free();
//   void draw();

   // operator overloads
      Piece& operator[] (const Position& point);
      Piece& operator[] (const Position& point) const;
      void operator= (const Piece& piece);
//   void operator -= (const Point& point); // Kill
};