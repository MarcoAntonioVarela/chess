/***********************************************************************
 * Heaader File:
 *    Definition of the Piece class
 * Author:
 *    Marco Varela
 * Summary:
 *    All the attributes and methods regarding the generic chess piece
 ************************************************************************/


#pragma once
#include "point.h"

class Piece {
protected:
   Point position;
   bool fWhite;
   int nMoves;
   int lastMove;

public:
   Piece(int r, int c, bool white);
   void assign(Point p);
   void assign(Piece p);
   bool isWhite();
   bool isMove();
   int getNMoves();
   Point getPosition();
   bool justMoved();
   /*char getLetter();*/
   virtual void getMoves(char** board) = 0;
};

