/***********************************************************************
 * Header File:
 *   Test King : Test the King class
 * Author:
 *   Efrain Gomez
 * Summary:
 *   All the unit tests for the King class
 ************************************************************************/

#pragma once
#include <iostream>
#include <cassert>
using namespace std;



/*****************************************************
* TEST KING CLASS
 * A class that contains the King class unit tests
 *****************************************************/
class TestKing
{
public:
   void run()
   {
      test_1();
      cout << "\nAll the test cases for testKing.h have been successfull!\n";
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