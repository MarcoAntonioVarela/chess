/***********************************************************************
 * Heaader File:
 *    Definition of the Move class
 * Author:
 *    Efrain Gomez
 * Summary:
 *    Using Smith notation, this class can ensure all the movement that
 *    is possible throught the chess program
 ************************************************************************/
#pragma once
#include <string>

class Point;

class Move
{
private:
   Point source;
   Point destination;
   char piece;
   char capture;
   bool enPassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   std::string error;

public:
   Move();
   std::string getText();
   Point getSrc();
   Point getDes();
   char getPromotion();
   char getCapture();
   bool getEnPassant() { return enPassant; };
   bool getCastleK()   { return castleK; }
   bool getCastleQ()   { return castleQ; }
   bool getWhiteMove() { return isWhite; }
   void setEnPassant() { enPassant = true; }
   void setCastleK()   { castleK = true; }
   void setCastleQ()   { castleQ = true; }
   void setWhiteMove() { isWhite = true; }

   //operator overload
   Move operator= (const Move& move);
   Move operator= (const std::string& str);

};