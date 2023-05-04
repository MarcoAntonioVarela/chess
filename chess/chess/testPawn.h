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
      pawn_test_first_move_two_squares();
      pawn_test_first_move_can_move();
      pawn_test_not_first_move_can_move();
      pawn_test_not_first_move_cannot_move();
      pawn_test_en_passant();
      pawn_test_promotion_without_capture();
      pawn_test_promotion_with_capture();
      pawn_test_capturing();
      test_9();
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
    * TESTING: First move, can move two squares 
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6    (p)              6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void pawn_test_first_move_two_squares()
   {
      //SETUP

      //EXERCISE
      

      //VERYFY
      //assert();

      //TEARDOWN
      
   }

      /*****************************************************
    * TESTING: First move, can't move 
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6    (p)              6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void pawn_test_first_move_can_move()
   {
      //SETUP

      //EXERCISE
      

      //VERYFY
      //assert();

      //TEARDOWN
      
   }

      /*****************************************************
    * TESTING: Not first move, can move
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6    (p)              6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void pawn_test_not_first_move_can_move()
   {
      //SETUP

      //EXERCISE
      

      //VERYFY
      //assert();

      //TEARDOWN
      
   }
      /*****************************************************
    * TESTING: Not first move, can't move
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6    (p)              6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void pawn_test_not_first_move_cannot_move()
   {
      //SETUP

      //EXERCISE
      

      //VERYFY
      //assert();

      //TEARDOWN
      
   }
      /*****************************************************
    * TESTING: En passant
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6    (p)              6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void pawn_test_en_passant()
   {
      //SETUP

      //EXERCISE
      

      //VERYFY
      //assert();

      //TEARDOWN
      
   }
      /*****************************************************
    * TESTING: Pawn promotion without capture
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6    (p)              6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void pawn_test_promotion_without_capture()
   {
      //SETUP

      //EXERCISE
      

      //VERYFY
      //assert();

      //TEARDOWN
      
   }
      /*****************************************************
    * TESTING: Pawn promotion with capture
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6    (p)              6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void pawn_test_promotion_with_capture()
   {
      //SETUP

      //EXERCISE
      

      //VERYFY
      //assert();

      //TEARDOWN
      
   }
      /*****************************************************
    * TESTING: Pawn Capturing
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6    (p)              6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void pawn_test_capturing()
   {
      //SETUP

      //EXERCISE
      

      //VERYFY
      //assert();

      //TEARDOWN
      
   }
      /*****************************************************
    * TESTING ...
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6    (p)              6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void test_9()
   {
      //SETUP

      //EXERCISE


      //VERYFY
      //assert();

      //TEARDOWN



   }

};