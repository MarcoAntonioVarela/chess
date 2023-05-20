/***********************************************************************
 * Heaader File:
 *    Implementation of the Piece class
 * Author:
 *    Marco Varela
 * Summary:
 *    All the attributes and methods regarding the generic chess piece
 ************************************************************************/

#include "piece.h"
using namespace std;
/************
* PIECE
************/
Piece::Piece() : nMoves(0) {}

//void Piece::assign(Point p) {
//   position = p;
//}

//void Piece::assign(Piece p) {
//   position = p.position;
//   fWhite = p.fWhite;
//   nMoves = p.nMoves;
//   lastMove = p.lastMove;
//}

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
   this->isWhite = isWhite;
   position = Position(coordinate);
   isFirstMove = true;
}

set<Move> Pawn::getPossible(const Board& board)
{
   return set<Move>();
}
