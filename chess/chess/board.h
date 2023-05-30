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
#include "uiDraw.h"

class Board
{
   private:
      Piece* board[8][8];
     int currentMove;
     void swap(Position& point1, Position& point2);
//   bool assertBoard();

   public:
      Board();
      int getCurrentMove() { return currentMove; }
      bool isWhiteTurn() { return currentMove % 2 == 0; }
      void reset(); // Pieces back to the original position.
      void drawBoard() const;
      void drawPieces() const;

      // operator overloads
      Piece& operator[] (const Position& point);
      Piece& operator[] (const Position& point) const;
      void operator= (Piece& piece);
      void operator -= (const Position& position); // Kill
};