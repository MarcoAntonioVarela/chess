/***********************************************************************
 * Header File:
 *   Test Pawn : Test the Pawn class
 * Author:
 *   Marco Varela
 * Summary:
 *   All the unit tests for the Pawn class
 ************************************************************************/

#pragma once
#include <iostream>
#include <cassert>
using namespace std;



/*****************************************************
* TEST PAWN CLASS
 * A class that contains the Pawn class unit tests
 *****************************************************/
class TestPawn
{
public:
   void run()
   {
      test_1();
      cout << "\nAll the test cases for testPawn.h have been successfull!\n";
   }
private:
   //Utility funciton because floating point numbers are approximations (just in case)
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }


   /*****************************************************
    * TESTING ...
    *****************************************************/

   void test_1()
   {
      
      cout << "Replace this! :) ";
   }

};