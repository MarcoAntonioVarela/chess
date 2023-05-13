/***********************************************************************
 * Source File:
 *    Implementation of the Move class
 * Author:
 *    Efrain Gomez & Marco Varela
 * Summary:
 *    The code implementation for move
 ************************************************************************/
using namespace std;
#include "move.h"
#include "point.h"

// Move("a1 a2")
 Move::Move(const string& coordinate)
 {
    string::const_iterator it = coordinate.cbegin();

    // get the source
    int col = *it - 'a';
    it++;
    int row = *it - '1';
    it++;
    source = Point(col + row);

    // get the destination
    col = *it - 'a';
    it++;
    row = *it - '1';
    it++;
    destination = Point(col + row);
 }