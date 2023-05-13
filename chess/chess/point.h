/***********************************************************************
 * Heaader File:
 *    Definition of the Point class
 * Author:
 *    Efrain Gomez
 * Summary:
 *    A coordinate in "a1" to represent the squares that are present
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
   Point();
   Point(char location);
   Point(const Point& p);
   int getLocation();
   int getRow() const;
   int getColumn() const;
   int getX() const;
   int getY() const;
   bool isValid();
   void setRow(int row);
   void setColumn(int column);
   bool operator== (const Point& rhs) { return rhs.location == location; };
   // void operator= (const Point& rhs) { location = rhs.location; }
};