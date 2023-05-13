/***********************************************************************
 * Heaader File:
 *    Definition of the Board class
 * Author:
 *    Efrain Gomez
 * Summary:
 *    The Board has all the pieces, and helps each piece know where to move
 ************************************************************************/
#pragma once
#include <set>
#include "point.h"
#include "piece.h"

class Board
{
private:

   // multidimentional array. We use this so it is easier to implement
   // the operator[]
   Piece* pieces[8][8];
   int currentMove;
   // ogstream gout;
   void swap(Point& point1, Point& point2);
   bool assertBoard();

public:
   Board();
   // Board(ogstream gout, bool reset=false);
   int getCurrentMove() { return currentMove; }
   bool isWhiteTurn() { return currentMove % 2 == 0; }
   void reset();
   void free();
   void draw();

   // operator overloads
   // Piece& operator[] (const Point& point) { return *pieces[point.getY()][point.getX()]; }
   void operator= (Piece& piece);
};