/***********************************************************************
 * Heaader File:
 *    Definition of the Point class
 * Author:
 *    Efrain Gomez
 * Summary:
 *    A coordinate in (x, y) to represent the squares that are present
 *    in the chess board, and where each piece is located.
 ************************************************************************/

#pragma once


class Point
{
private:
   char location;
   static double squareWidth;
   static double squareHeight;

public:
   int getLocation();
   int getRow();
   int getColumn();
   int getX();
   bool isValid();
   void setRow(int row);
   void setColumn(int column);
   bool operator== (const Point& rhs) { return rhs.location == location; };
   void operator= (const Point& rhs) { location = rhs.location; }
};