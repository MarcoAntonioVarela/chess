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
using namespace std;
/************
* PIECE
************/
Piece::Piece() : nMoves(0) {}

//bool Piece::isWhite() {
//   return fWhite;
//}

//bool Piece::isMove() {
//   return nMoves > 0;
//}

//int Piece::getNMoves() {
//   return nMoves;
//}
//
//Point Piece::getPosition() {
//   return position;
//}
//
//bool Piece::justMoved() {
//   return lastMove == nMoves - 1;
//}

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
   if (!isMoved())
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

   return possible;
}

/************************
* SPACE
***********************/
Space::Space(const Position& position) 
{
   white = true; 
}



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
    return {};
}

/************************
* KNIGHT Marco
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

   //cambiar el return por el set de possibles
    set<Move> possible = {};
    return possible;
}


/************************
* BISHOP Marco
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
    return {};
}

/************************
* KING Marco
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
   set<Move>possible = {};

   const Delta delta[] =

   {
      {-1,1},   {0,1},  {1,1},
      {-1,0},           {1,0},
      {-1,- 1},{0,-1},  {1,-1}
   };
   
   for (int i = 0; i < 9; i++)
   {
      Position posMove(position.getRow() + delta[i][0],
         position.getCol() + delta[i][1]);
      
      //To capture enemy piece
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

      //Empty space move
      if (posMove.isValid() &&
         board[posMove] == ' ' )

      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         possible.insert(move);
      }

      //Agregar castling

     
   }



   return possible;
}





/************************
* QUEEN Marco
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

   return {};
}

//
///************************
//* QUEEN Marco
//***********************/
//Queen::Queen(const Position& point, bool isWhite)
//{
//   this->white = isWhite;
//   position = Position(point);
//}
//
///************
//* QUEEN::getPossible
//************/
//set<Move> Queen::getPossible(const Board& board)
//{
//   return {};
//}