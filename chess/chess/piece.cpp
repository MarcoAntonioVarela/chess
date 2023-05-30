/***********************************************************************
 * Heaader File:
 *    Implementation of the Piece class
 * Author:
 *    Marco Varela
 * Summary:
 *    All the attributes and methods regarding the generic chess piece
 ************************************************************************/

#include "piece.h"
#include "move.h"
#include "board.h"
#include "pieceType.h"
#include <iostream>
#include <set>

using namespace std;
/************
* PIECE
************/
Piece::Piece() : nMoves(0), lastMove(0) {}

void Piece::drawPossible(std::set<Move> possible, ogstream& gout)
{
   set <Move> ::iterator it;
   for (it = possible.begin(); it != possible.end(); ++it)
      gout.drawPossible(*it);
}

/************
* PAWN
************/
Pawn::Pawn(const Position& coordinate, bool isWhite)
{
   this->white = isWhite;
   position = Position(coordinate);
   isFirstMove = true;
}

/************
* PAWN::getPossible
************/
set<Move> Pawn::getPossible(const Board& board)
{
   set<Move> possible = {};
   Position posMove(getPosition(), isWhite() ? ADD_R : SUB_R);

   // Regular movement
   if (posMove.isValid() && board[posMove] == ' ')
   {
      Move move;
      move.setSrc(getPosition());
      move.setDes(posMove);
      move.setWhiteMove(isWhite());
      possible.insert(move);
   }

   // Double space for first move
   if (!isMoved() && posMove.isValid())
   {
      Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
      Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());

      if (board[posMove] == ' ' && board[posCheck] == ' ')
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         possible.insert(move);
      }
   }

   // Promotion
   if (posMove.getRow() == (isWhite() ? 7 : 0))
   {
      Move move;
      move.setSrc(getPosition());
      move.setDes(posMove);
      move.setWhiteMove(isWhite());
      move.setPromote(QUEEN);
      possible.insert(move);
   }

   // capture
   const int cDelta[] = { 1, -1 };
   for (int i = 0; i < 2; i++)
   {
      Position posMove(position.getRow() + (isWhite() ? 1 : -1),
         position.getCol() + cDelta[i]);

      if (posMove.isValid() &&
         board[posMove] != ' ' &&
         board[posMove].isWhite() != isWhite())
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(move.pieceTypeFromLetter(board[posMove].getLetter()));
         possible.insert(move);
      }
   }

   // en-passant
   for (int i = 0; i < 2; i++)
   {
      Position posMove(position.getRow() + (isWhite() ? 1 : -1),
         position.getCol() + cDelta[i]);
      Position posKill(position.getRow(),
         position.getCol() + cDelta[i]);

      if (posMove.isValid() &&
         position.getRow() == (isWhite() ? 4 : 3) &&
         board[posMove] == ' ' &&
         board[posKill] == 'p' &&
         board[posKill].isWhite() != isWhite() &&
         board[posKill].getNMoves() == 1)
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(PAWN);
         move.setEnPassant();
         possible.insert(move);
      }
   }

   return possible;
}

void Pawn::draw(ogstream& gout)
{
   gout.drawPawn(position, isWhite());
}

/************************
* SPACE
***********************/
Space::Space(const Position& position) { white = true; }

// They need to be initialized because of the 
// pure virtual, but they will not do anything.
void Space::draw(ogstream& gout) {}

/************************
* ROOK
***********************/
Rook::Rook(const Position& point, bool isWhite)
{
    this->white = isWhite;
    position = Position(point);
    isFirstMove = true;
}


/************
* ROOK::getPossible
************/
set<Move> Rook::getPossible(const Board& board)
{
   set<Move> possible;

   struct Delta {
      int x;
      int y;
   };

   const Delta delta[] = 
   {
                  {0,1},
         {-1,0},           {1,0},
                  {0,-1}
   };
   for (int i = 0; i < 4; i++)
   {
      Position posMove(position.getRow() + delta[i].x
         / position.getCol() + delta[i].y);
      // capture?
      if (posMove.isValid() &&
         board[posMove] != ' ' &&
         board[posMove].isWhite() != isWhite())
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(move.pieceTypeFromLetter(board[posMove].getLetter()));
         possible.insert(move);
      }

      // empty space?
      else if (posMove.isValid() &&
         board[posMove] == ' ')
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         possible.insert(move);
      }
   }
   return possible;
};
void Rook::draw(ogstream& gout)
{
   gout.drawRook(position, isWhite());
}

/************************
* KNIGHT 
***********************/
Knight::Knight(const Position& point, bool isWhite)
{
    this->white = isWhite;
    position = Position(point);
}

/************
* KNIGHT::getPossible
************/
set<Move> Knight::getPossible(const Board& board)
{
   set<Move> possible;

   struct Delta {
      int x;
      int y;
   };

   const Delta delta[] = {
             {-1,2},     {1,2},
         {-2,1},           {2,1},

         {-2,-1},         {2 - 1},
            {-1,2},         {1 - 2}
   };

   for (int i = 0; i < 7; i++)
   {
      Position posMove(position.getRow() + delta[i].x
         / position.getCol() + delta[i].y);
      // capture?
      if (posMove.isValid() &&
         board[posMove] != ' ' &&
         board[posMove].isWhite() != isWhite())
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(move.pieceTypeFromLetter(board[posMove].getLetter()));
         possible.insert(move);
      }

      // empty space?
      else if (posMove.isValid() &&
         board[posMove] == ' ')
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         possible.insert(move);
      }
   }
   return possible;
};

void Knight::draw(ogstream& gout)
{
   gout.drawKnight(position, isWhite());
}

/************************
* BISHOP 
***********************/
Bishop::Bishop(const Position& point, bool isWhite)
{
    this->white = isWhite;
    position = Position(point);
}

/************
* BISHOP::getPossible
************/
set<Move> Bishop::getPossible(const Board& board)
{
   set<Move> possible;

   struct Delta {
      int x;
      int y;
   };

   const Delta delta[] = {
         {-1,1},       {1,1},

         {-1,-1},      {1,-1}
   };

   for (int i = 0; i < 3; i++)
   {
      Position posMove(position.getRow() + delta[i].x
         / position.getCol() + delta[i].y);
      // capture?
      if (posMove.isValid() &&
         board[posMove] != ' ' &&
         board[posMove].isWhite() != isWhite())
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(move.pieceTypeFromLetter(board[posMove].getLetter()));
         possible.insert(move);
      }

      // empty space?
      else if (posMove.isValid() &&
         board[posMove] == ' ')
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         possible.insert(move);
      }
   }
   return possible;
};

void Bishop::draw(ogstream& gout)
{
   gout.drawBishop(position, isWhite());
}

/************************
* QUEEN
***********************/
Queen::Queen(const Position& point, bool isWhite)
{
    this->white = isWhite;
    position = Position(point);
}

/************
* QUEEN::getPossible
************/
set<Move> Queen::getPossible(const Board& board)
{
   set<Move> possible;

   struct Delta {
      int x;
      int y;
   };

   const Delta delta[] = {
      {-1,1}, {0,1}, {1,1},
      {-1,0},        {1,0},
      {-1,-1},{0,-1},{1,-1}
   };;

   for (int i = 0; i < 7; i++)
   {
      Position posMove(position.getRow() + delta[i].x
         / position.getCol() + delta[i].y);

      // capture
      if (posMove.isValid() &&
         board[posMove] != ' ' &&
         board[posMove].isWhite() != isWhite())
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(move.pieceTypeFromLetter(board[posMove].getLetter()));
         possible.insert(move);
      }

      // empty space
      else if (posMove.isValid() &&
         board[posMove] == ' ')
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         possible.insert(move);
      }
   }
   return possible;
};

void Queen::draw(ogstream& gout)
{
   gout.drawQueen(position, isWhite());
}

/************************
* KING
***********************/
King::King(const Position& point, bool isWhite)
{
    this->white = isWhite;
    position = Position(point);
    isFirstMove = true;
}

/************
* KING::getPossible
************/
set<Move> King::getPossible(const Board& board)
 {
   std::set<Move> possible;

   struct Delta {
      int x;
      int y;
   };

   const Delta delta[] = {
       {-1, 1}, {0, 1}, {1, 1},
       {-1, 0},         {1, 0},
       {-1, -1}, {0, -1}, {1, -1}
   };

   for (int i = 0; i < 7; i++) 
   {
      Position posMove(position.getRow() + delta[i].x
         / position.getCol() + delta[i].y);
      // capture
      if (posMove.isValid()&&
               board[posMove] != ' ' &&
               board[posMove].isWhite() != isWhite())
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(move.pieceTypeFromLetter(board[posMove].getLetter()));
         possible.insert(move);
      }

      // empty space
      else if (posMove.isValid()&&
               board[posMove] == ' ' )
      {           
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         possible.insert(move);
       }
      // castling
   }
   return possible;
};

void King::draw(ogstream& gout)
{
   gout.drawKing(position, isWhite());
}
