/***********************************************************************
 * Heaader File:
 *    Definition of the Piece class
 * Author:
 *    Marco Varela
 * Summary:
 *    All the attributes and methods regarding the generic chess piece
 ************************************************************************/
#pragma once

using namespace std;
#include "point.h"
#include <set>
#include "string"
// #include "board.h"
#include "move.h"

class Board;
class TestKing;
class TestPawn;

class Piece 
{
protected:
   Point position;
   bool fWhite;
   int nMoves;
   int lastMove;

public:
   void assign(Point p);
   Point getPosition();
   bool isWhite();
   bool isMove();
   int getNMoves();
   Point getPosition(); 
   bool justMoved();
   /*char getLetter();*/
   virtual set<Move> getPossible(Board board) = 0;
};

/************************
 * PAWN
 ***********************/
class Pawn : public Piece
{
   friend TestPawn;
public:
   Pawn(string point, bool white);
   set<Move> getPossible(Board board);
private:
      bool isFirstMove;
};

/************************
 * ROOK
 ***********************/
class Rook : public Piece
{
   friend TestKing;
public:
   Rook(string point, bool white);
   set<Move> getPossible(Board board);
   private:
      bool isFirstMove;
};

/************************
 * KNIGHT
 ***********************/
class Knight : public Piece
{
public:
   Knight(string point, bool white);
   set<Move> getPossible(Board board);
};

/************************
 * BISHOP
 ***********************/
class Bishop : public Piece
{
public:
   Bishop(string point, bool white);
   set<Move> getPossible(Board board);
};

/************************
 * QUEEN
 ***********************/
class Queen : public Piece
{
public:
   Queen(string point, bool white);
   set<Move> getPossible(Board board);
};

/************************
 * KING
 ***********************/
class King : public Piece
{
   friend TestKing;
public:
   King(string point, bool white);
   set<Move> getPossible(Board board);
   private:
      bool isFirstMove;
};

/************************
 * SPACE
 ***********************/
class Space : public Piece
{
public:
   Space(string point);
   set<Move> getPossible(Board board);
};