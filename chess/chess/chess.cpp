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

void runner()
{
   TestPawn().run();
}


int main()
{
   std::cout << "All test pass!" << std::endl;
}
