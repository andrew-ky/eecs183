/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Andrew Ky and Aaron Williams
 * andrewky, ajwills
 *
 * Point will construct a point from a given X and Y coordinate and will represent a point in an image.
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}
void Point::setX(int xVal) {
    x = checkRange(xVal);
}

int Point::getX() {
    return x;
}

void Point::setY(int yVal) {
    y = checkRange(yVal);
}

int Point::getY() {
    return y;
}

void Point::read(istream& ins) {
    char skip;
  
    ins >> skip >> x >> skip >> y >> skip;
    x = checkRange(x);
    y = checkRange(y);
}

void Point::write(ostream& outs) {
    
    outs << "(" << x << "," << y << ")" << " ";
  
}

int Point::checkRange(int val) {
  if (val >= 0 && val < DIMENSION) {
        return val;
    }
  else if (val < 0) {
        return 0;
    }
  else {
        return (DIMENSION - 1);
    }
}

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
