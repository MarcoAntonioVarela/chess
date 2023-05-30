/***********************************************************************
This file contains the 'main' function. Our chess program execution begins and ends there.

 * Authors:
 *   Marco Varela & Efrain Gomez
 * Summary:
 *   This is a C++ program of a chess game.
 **********************************************************************/

#include <iostream>
#include "board.h"
#include "uiInteract.h"


std::set<Move> getPossibleMoves(const Board& board, int location)
{
   std::set<Move> possible;

   // return the empty set if there simply are no possible moves
   if (location < 0 || location >= 64 || board[location] == ' ')
      return possible;
   int row = board[location].getPosition().getRow();  // current location row
   int col = board[location].getPosition().getCol();  // current location column
   //bool amBlack = isBlack(board, row, col);
   Position position(location);
   
   possible = board[location].getPossible(board);

   return possible;
}


void draw(const Board& board, const Interface& ui, const std::set<Move>& possible)
{
   ogstream gout;
   board.drawBoard();

   // draw any selections
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());

   // Drawing pieces
   board.drawPieces();

   // Drawing the possible moves
   std::set<Move> ::iterator it;
   for (it = possible.begin(); it != possible.end(); ++it)
      gout.drawPossible(*it);

}

void callBack(Interface* pUI, void* p)
{
   std::set<Move> possible;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Board* board = (Board*)p;

   // TODO: Populte the possible moves depending on the piece
   // that was selected by the user.
   possible = getPossibleMoves(*board, pUI->getSelectPosition());

   // draw the board
   draw(*board, *pUI, possible);

}

int main() 
{
   Interface ui("Chess");

   Board* pBoard = new Board;
   
   // set everything into action
   ui.run(callBack, pBoard);

   return 0;
}
