/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Aaron Williams, Andrew Ky>
 * <ajwills, andrewky >
 *
 * Color will change the RGB values of a point by changing red value, green value, and blue value.
 */

#include "Color.h"
// Default Color (0,0,0) is black
    Color::Color(){
        red = 0;
        green = 0;
        blue = 0;
    }
//checkRange makes sure its greater than 0 and less than or equal to 255
    Color::Color(int redVal, int greenVal, int blueVal){
        red = checkRange(redVal);
        green = checkRange(greenVal);
        blue = checkRange(blueVal);
      
    }

    void Color::setRed(int redVal) {
        red = checkRange(redVal);
    }

    int Color::getRed() {
        return red;
    }

    void Color::setGreen(int greenVal) {
        green = checkRange(greenVal);
    }

    int Color::getGreen() {
        return green;
    }

    void Color::setBlue(int blueVal) {
        blue = checkRange(blueVal);
    }

    int Color::getBlue() {
        return blue;
    }
//Reads in Color
    void Color::read(istream& ins) {
        ins >> red >> green >> blue;
        red = checkRange(red);
        green = checkRange(green);
        blue = checkRange(blue);
    }
//Writes Out Color
    void Color::write(ostream& outs) {
        outs << red << " " << green << " " << blue << "  ";
    }

    int Color::checkRange(int val) {
      // 255 is the max value for RGB value
      if (val >= 0 && val < 255) {
        return val;
      } 
      else if (val < 0) {
        return 0;
      } 
      else {
        return 255;
      }
    }

/**
 * Overloading >> and << for reading and writing Color to and from streams.
 */
istream& operator >> (istream& ins, Color& color);
ostream& operator << (ostream& outs, Color color);

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
