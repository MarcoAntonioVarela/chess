/***********************************************************************
This file contains the 'main' function. Our chess program execution begins and ends there.

 * Authors:
 *   Marco Varela & Efrain Gomez
 * Summary:
 *   This is a C++ program of a chess game.
 **********************************************************************/


#include <iostream>
#include "testKing.h"
#include "testPawn.h"
#include "board.h"
#include "uiInteract.h"

void runner()
{
   TestPawn().run();
}


void callBack(Interface* pUI, void* p)
{
   ogstream gout;
   Board* board = (Board*)p;

   // draw any selections
   gout.drawHover(pUI->getHoverPosition());
   gout.drawSelected(pUI->getSelectPosition());

   // draw both the board and the pieces
   board->draw();

}


int main()
{
   Interface ui("Chess");

   Board* pBoard = new Board;
   
   // set everything into action
   ui.run(callBack, pBoard);

   runner();
   std::cout << "All test pass!" << std::endl;

   return 0;
}
