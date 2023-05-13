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
#include "board.h"
#include "move.h"

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
      test_CantMove();
      test_FreeMove();
      test_CastlingKingSide();
      test_CastlingQueenSide();
      test_KingCantCastle();
      test_RookCantCastle();
      test_KingCapture();
      cout << "\nAll the test cases for testKing.h have been successfull!\n";
   }
private:

   /*****************************************************
    * TESTING ...
    *****************************************************/

   void test_CantMove()
    /*****************************************************
    * Can't move
    *
    * +---a-b-c-d-e-f-g-h---+
    * |                     |
    * 8   R N B Q K B N R   8
    * 7   P P P P P P P P   7
    * 6                     6
    * 5                     5
    * 4                     4
    * 3                     3
    * 2   p p p p p p p p   2
    * 1   r n b q(k)b n r   1
    * |                     |
    * +---a-b-c-d-e-f-g-h---+
    *
    *****************************************************/
   {
      // SETUP
      King k("e1", true);
      Board b;
      b = k;

      // EXERCISE
      set<Move> possible = k.getPossible(b);

      // VERIFY
      assert(possible.size() == 0);
      assert(possible.find(move) == possible.end());

      // TEARDOWN
   }

   void test_FreeMove()
      /*****************************************************
      * Free Move
      *
      * +---a-b-c-d-e-f-g-h---+
      * |                     |
      * 8   R N B Q K B N R   8
      * 7   P P P P P P P P   7
      * 6                     6
      * 5          (k)        5
      * 4                     4
      * 3                     3
      * 2   p p p p p p p p   2
      * 1   r n b q   b n r   1
      * |                     |
      * +---a-b-c-d-e-f-g-h---+
      *
      *****************************************************/
   {
      // SETUP
      King k("e5", true);
      Board b;
      b = k;

      // EXERCISE
      set<Move> possible = k.getPossible(b);

      // VERIFY
      assert(possible.size() == 8);

      // TEARDOWN
   }

   void test_CastlingKingSide()
      /*****************************************************
      * Castling King Side
      *
      * +---a-b-c-d-e-f-g-h---+
      * |                     |
      * 8   R N B Q K B N R   8
      * 7   P P P P P P P P   7
      * 6                     6
      * 5                     5
      * 4                     4
      * 3                     3
      * 2   p p p p p p p p   2
      * 1   r n b q(k)    r   1
      * |                     |
      * +---a-b-c-d-e-f-g-h---+
      *
      *****************************************************/
   {
      // SETUP
      King k("e5", true);
      Rook r("h1", true);
      k.isFirstMove = true;
      r.isFirstMove = true;
      Board b;
      b = k;
      b = r;

      // EXERCISE
      set<Move> possible = k.getPossible(b);

      // VERIFY
      assert(possible.size() == 2);
      Move move("e1g1C");
      assert(possible.find(move) != possible.end());

      // TEARDOWN
   }

   void test_CastlingQueenSide()
      /*****************************************************
      * Castling Queen Side
      *
      * +---a-b-c-d-e-f-g-h---+
      * |                     |
      * 8   R N B Q K B N R   8
      * 7   P P P P P P P P   7
      * 6                     6
      * 5                     5
      * 4                     4
      * 3                     3
      * 2   p p p p p p p p   2
      * 1   r      (k)b n r   1
      * |                     |
      * +---a-b-c-d-e-f-g-h---+
      *
      *****************************************************/
   {
      // SETUP
      King k("e5", true);
      Rook r("a1", true);
      k.isFirstMove = true;
      r.isFirstMove = true;
      Board b;
      b = k;
      b = r;

      // EXERCISE
      set<Move> possible = k.getPossible(b);

      // VERIFY
      assert(possible.size() == 2);
      Move move("e1c1c");
      assert(possible.find(move) != possible.end());

      // TEARDOWN
   }

   void test_KingCantCastle()
      /*****************************************************
      * The king already moved, so it can't castle
      *
      * +---a-b-c-d-e-f-g-h---+
      * |                     |
      * 8   R N B Q K B N R   8
      * 7   P P P P P P P P   7
      * 6                     6
      * 5                     5
      * 4                     4
      * 3                     3
      * 2   p p p p p p p p   2
      * 1   r      (k)b n r   1
      * |                     |
      * +---a-b-c-d-e-f-g-h---+
      *
      *****************************************************/
   {
      // SETUP
      King k("e5", false);
      Rook r("a1", true);
      k.isFirstMove = true;
      r.isFirstMove = true;
      Board b;
      b = k;
      b = r;

      // EXERCISE
      set<Move> possible = k.getPossible(b);

      // VERIFY
      assert(possible.size() == 1);
      Move move("e1d1");
      assert(possible.find(move) != possible.end());

      // TEARDOWN
   }

   void test_RookCantCastle()
      /*****************************************************
      * The rook already move, so it can't caslte
      *
      * +---a-b-c-d-e-f-g-h---+
      * |                     |
      * 8   R N B Q K B N R   8
      * 7   P P P P P P P P   7
      * 6                     6
      * 5                     5
      * 4                     4
      * 3                     3
      * 2   p p p p p p p p   2
      * 1   r      (k)b n r   1
      * |                     |
      * +---a-b-c-d-e-f-g-h---+
      *
      *****************************************************/
   {
      // SETUP
      King k("e5", true);
      Rook r("a1", false);
      k.isFirstMove = true;
      r.isFirstMove = true;
      Board b;
      b = k;
      b = r;

      // EXERCISE
      set<Move> possible = k.getPossible(b);

      // VERIFY
      assert(possible.size() == 1);
      Move move("e1d1");
      assert(possible.find(move) != possible.end());

      // TEARDOWN
   }

   void test_KingCapture()
      /*****************************************************
      * Free Move
      *
      * +---a-b-c-d-e-f-g-h---+
      * |                     |
      * 8   R N B Q K B N R   8
      * 7   P P P P   P P P   7
      * 6           P         6
      * 5          (k)        5
      * 4                     4
      * 3                     3
      * 2   p p p p p p p p   2
      * 1   r n b q   b n r   1
      * |                     |
      * +---a-b-c-d-e-f-g-h---+
      *
      *****************************************************/
   {
      // SETUP
      King k("e5", true);
      Pawn p("e6", false);
      Board b;
      b = k;
      b = p;

      // EXERCISE
      set<Move> possible = k.getPossible(b);

      // VERIFY
      assert(possible.size() == 8);
      Move move("e5e6");
      assert(possible.find(move) != possible.end());

      // TEARDOWN
   }


};