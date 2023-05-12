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

class TestBoard;
class Piece;
class Point;
class ogstream;

class Board
{
   friend TestBoard;
private:
   std::set<Piece*> pieces;
   int currentMove;
   ogstream gout;
   void swap(Point& point1, Point& point2);
   bool assertBoard();

public:
   Board(ogstream gout, bool reset=false);
   int getCurrentMove() { return currentMove; }
   bool isWhiteTurn() { return currentMove % 2 == 0; }
   void reset();
   void free();
   void draw();

   // operator overloads
   Piece& operator[] (const Point& pos) { return *Board[pos.getX()][pos.getY()]; }
   void operator= (const Piece& piece);

};