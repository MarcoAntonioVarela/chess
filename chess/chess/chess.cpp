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
