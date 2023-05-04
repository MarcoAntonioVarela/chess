/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Marco Varela and Efrain Gomez
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPawn.h"           // Unit tests created by Marco Varela
#include "testking.h"           // Unit tests created by Efrain Gomez


 /*****************************************************************
  * TEST RUNNER
  * Runs all the unit tests
  ****************************************************************/
void testRunner()
{
   TestPawn().run();
   TestKing().run();
   
}
