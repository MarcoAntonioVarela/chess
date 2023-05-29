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
class TestKing;
class TestPawn;
class ogstream;

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

      // constructor
      Piece();

      // getters
      bool isWhite() { return white; };
      bool isMove() { return nMoves > 0; };
      int getNMoves() { return nMoves; };
      const Position& getPosition() const { return position; }
      virtual char getLetter() const = 0;
      virtual std::set<Move> getPossible(const Board &board) = 0;

      // drawing
      virtual void draw(ogstream& gout) = 0;
      virtual void drawPossible(std::set<Move> possible, ogstream& gout) = 0;

      // operator overloads
      bool operator== (char letter) const { return getLetter() == letter; }
      bool operator!= (char letter) { return getLetter() != letter; }
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
   void draw(ogstream& gout);
   void drawPossible(std::set<Move> possible, ogstream& gout);
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
   Rook(const Position& point, bool white);
   std::set<Move> getPossible(const Board& board);
   char getLetter() const { return 'r'; }
   void draw(ogstream& gout);
   void drawPossible(std::set<Move> possible, ogstream& gout);
   private:
      bool isFirstMove;
};

/************************
* KNIGHT
***********************/
class Knight : public Piece
{
public:
   Knight(const Position& point, bool white);
   std::set<Move> getPossible(const Board& board);
   char getLetter() const { return 'n'; }
   void draw(ogstream& gout);
   void drawPossible(std::set<Move> possible, ogstream& gout);
};

/************************
* BISHOP
***********************/
class Bishop : public Piece
{
public:
   Bishop(const Position& point, bool white);
   std::set<Move> getPossible(const Board& board);
   char getLetter() const { return 'b'; }
   void draw(ogstream& gout);
   void drawPossible(std::set<Move> possible, ogstream& gout);
};

/************************
* QUEEN
***********************/
class Queen : public Piece
{
public:
   Queen(const Position& point, bool white);
   std::set<Move> getPossible(const Board& board);
   char getLetter() const { return 'q'; }
   void draw(ogstream& gout);
   void drawPossible(std::set<Move> possible, ogstream& gout);
};

/************************
* KING
***********************/
class King : public Piece
{
   friend TestKing;
public:
   King(const Position& point, bool white);
   std::set<Move> getPossible(const Board& board);
   char getLetter() const { return 'k'; }
   void draw(ogstream& gout);
   void drawPossible(std::set<Move> possible, ogstream& gout);
   private:
      bool isFirstMove;
};

/**********************
* SPACE
***********************/
class Space : public Piece
{
public:
   Space(const Position& position);
   std::set<Move> getPossible(const Board& board) { return {}; }
   char getLetter() const { return ' '; }
   void draw(ogstream& gout);
   void drawPossible(std::set<Move> possible, ogstream& gout);
 };