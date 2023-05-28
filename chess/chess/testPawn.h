/***********************************************************************
 * Header File:
 *   Test Pawn : Test the Pawn class
 * Author:
 *   Marco Varela
 * Summary:
 *   All the unit tests for the Pawn class
 ************************************************************************/

#pragma once
//#include <iostream>
#include <cassert>
#include "piece.h"
#include "board.h"
#include "move.h"
#include <set>
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
      testFirstMoveCanMoveTwoSquares();
      testFirstMoveCantMove();
      testNotFirstMoveCanMove();
      testNotFirstMoveCantMove();
      testPromotion();
      testCapture();
      testEnPassant();
//      testPromotionWithCapture();
//      cout << "\nAll the test cases for testPawn.h have been successfull!\n";
   }
private:

   /*****************************************************
    * TESTING: First move, can move two squares
    * 
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6                     6
    * 5                     5
    * 4           *         4
    * 3           *         3
    * 2   p p p p(p)p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/
   void testFirstMoveCanMoveTwoSquares() 
   {
      // SETUP
      Pawn p("e2", true);
      Board b;
      b = p;

      // EXERCISE
      set<Move> possible = p.getPossible(b);

      // VERIFY
      assert(possible.size() == 2);
      Move move("e2e4");
      assert(possible.find(move) != possible.end());

      // TEARDOWN
   }

   /*****************************************************
    * TESTING: First move, can't move
    *
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P   P P P   7
    * 6                     6
    * 5                     5
    * 4                     4
    * 3           P         3
    * 2   p p p p(p)p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/

   void testFirstMoveCantMove() 
   {
      // SETUP
      Pawn p("e2", true);
      Pawn p2("e3", false);
      Board b;
      b = p;
      b = p2;

      // EXERCISE
      set<Move> possible = p.getPossible(b);

      // VERIFY
      assert(possible.size() == 0);
      // assert(possible.find(move) == possible.end());

      // TEARDOWN
   }

   /*****************************************************
    * TESTING:Not first move, can move
    *
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P   P P P   7
    * 6                     6
    * 5                     5
    * 4           P         4
    * 3           *         3
    * 2   p p p p(p)p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/
   void testNotFirstMoveCanMove() 
   {
      // SETUP
      Pawn p("e2", true);
      Pawn p2("e4", false);
      Board b;
      b = p;
      b = p2;

      // EXERCISE
      set<Move> possible = p.getPossible(b);

      // VERIFY
      assert(possible.size() == 1);
      Move move("e2e3");
      assert(possible.find(move) != possible.end());

      // TEARDOWN

   }
   /*****************************************************
    * TESTING: Not first move, can't move
    *
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P   P P P   7
    * 6                     6
    * 5           P         5
    * 4          (p)        4
    * 3                     3
    * 2   p p p p   p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/
   void testNotFirstMoveCantMove() 
   {
      // SETUP
      Pawn p("e4", true);
      p.isFirstMove = false;
      Pawn p2("e5", false);
      Board b;
      b = p;
      b = p2;

      // EXERCISE
      set<Move> possible = p.getPossible(b);

      // VERIFY
      assert(possible.size()==0);
      //assert(possible.find(move) != possible.end());

      // TEARDOWN
   }

   /*****************************************************
    * TESTING: Promotion
    *
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q * B N R   8
    * 7   P P P P(p)P P P   7
    * 6                     6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p   p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/
   void testPromotion() 
   {
      // SETUP
      Pawn p("e7", true);
      p.isFirstMove = false;
      Space s("e8");
      Board b;
      b = p;
      b = s;

      // EXERCISE
      set<Move> possible = p.getPossible(b);

      // VERIFY
      assert(possible.size() == 1);
      Move move("e7e8Q");
      assert(possible.find(move) != possible.end());

      // TEARDOWN

   }

   /*****************************************************
    * TESTING: Capture
    *
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P   P P P   7
    * 6                     6
    * 5                     5
    * 4                     4
    * 3         P   P       3
    * 2   p p p p(p)p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/
   void testCapture()
   {
      // SETUP
      Pawn p("e2", true);
      p.isFirstMove = true;
      Pawn p2("f3", false);
      Pawn p3("d3", false);
      Board b;
      b = p;
      b = p2;
      b = p3;

      // EXERCISE
      set<Move> possible = p.getPossible(b);

      // VERIFY
      assert(possible.size() == 4);
      Move move("e2f3");
      assert(possible.find(move) != possible.end());

      // TEARDOWN
   }

   /*****************************************************
    * TESTING: En passant
    *
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P     P P P   7
    * 6         * *         6
    * 5         P(p)        5
    * 4                     4
    * 3                     3
    * 2   p   p p   p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/
   void testEnPassant()
   {
      // SETUP
      Pawn p("e5", true);
      p.isFirstMove = false;
      Pawn p2("d5", false);
      Board b;
      b = p;
      b = p2;

      // EXERCISE
      set<Move> possible = p.getPossible(b);

      // VERIFY
      assert(possible.size() == 2);
      Move move("e5d6p");
      assert(possible.find(move) != possible.end());

   //   // TEARDOWN
   }

   /*****************************************************
    * TESTING: Promotion with capture
    *
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q * B N R   8
    * 7   P P P P(p)P P P   7
    * 6                     6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p   p p p p p p   2
    * 1   r n b q k b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/
    //void testPromotionWithCapture() 
    //{
    //   // SETUP
    //   Pawn p("e7", true);
    //   Board b;
    //   b = p;

    //   // EXERCISE
    //   set<Move> possible = p.getPossible(b);

    //   // VERIFY
    //   assert(possible.size() == 3);
    //   Move move("e7f8bq");
    //   assert(possible.find(move) != possible.end());

    //   // TEARDOWN
    //}
};