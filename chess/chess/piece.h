/***********************************************************************
 * Heaader File:
 *    Definition of the Piece class
 * Author:
 *    Marco Varela
 * Summary:
 *    All the attributes and methods regarding the generic chess piece
 ************************************************************************/
#pragma once

#include "position.h"
#include <set>
#include "move.h"

class Board;
class Move;
//class TestKing;
class TestPawn;

/************************
 * PIECE
 * Abstract parent class
 ***********************/
class Piece 
{
protected:
   Position position;
   bool white;
   int nMoves;
   int lastMove;

public:
   Piece();
//   void assign(Point p);
//   Point getPosition();
     bool isWhite() { return white; };
//   bool isMove();
//   int getNMoves();
   const Position& getPosition() const { return position; };
//   bool justMoved();
   virtual char getLetter() const = 0;
   virtual std::set<Move> getPossible(const Board &board) = 0;
   bool operator== (char letter) const { return getLetter() == letter; }
};

/************************
 * PAWN
 ***********************/
class Pawn : public Piece
{
   friend TestPawn;
public:
   Pawn(const Position& coordinate, bool isWhite);
   std::set<Move> getPossible(const Board& board);
   char getLetter() const { return 'p'; }
   bool isMoved() { return !isFirstMove; }
private:
   bool isFirstMove;
};

/************************
* ROOK
***********************/
//class Rook : public Piece
//{
//   friend TestKing;
//public:
//   Rook(string point, bool white);
//   set<Move> getPossible(Board board);
//   private:
//      bool isFirstMove;
//};
//
/************************
* KNIGHT
***********************/
//class Knight : public Piece
//{
//public:
//   Knight(string point, bool white);
//   set<Move> getPossible(Board board);
//};
//
/************************
* BISHOP
***********************/
//class Bishop : public Piece
//{
//public:
//   Bishop(string point, bool white);
//   set<Move> getPossible(Board board);
//};
//
/************************
* QUEEN
***********************/
//class Queen : public Piece
//{
//public:
//   Queen(string point, bool white);
//   set<Move> getPossible(Board board);
//};
//
/************************
* KING
***********************/
//class King : public Piece
//{
//   friend TestKing;
//public:
//   King(string point, bool white);
//   set<Move> getPossible(Board board);
//   private:
//      bool isFirstMove;
//};
//
/**********************
* SPACE
***********************/
class Space : public Piece
{
public:
   Space(const Position& position);
   std::set<Move> getPossible(const Board& board) { return {}; }
   char getLetter() const { return ' '; }
 };