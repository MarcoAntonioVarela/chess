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

void callBack(Interface* pUI, void* p)
{
   ogstream gout;

   // Casting the pointer to the board
   Board* board = (Board*)p;

   board->drawBoard();

   // draw any selections
   gout.drawHover(pUI->getHoverPosition());
   gout.drawSelected(pUI->getSelectPosition());

   board->drawPieces();
}

int main()
{
   Interface ui("Chess");

   Board* pBoard = new Board;
   
   // set everything into action
   ui.run(callBack, pBoard);

   return 0;
}
