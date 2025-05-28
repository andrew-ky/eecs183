/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
     
test_Point();
test_Color();
test_Line();
test_Triangle();
test_Circle();
test_Rectangle();
      
    return;
}

void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
/*
   Point pt1;
    pt1.setX(15);
    cout << "Expected: (15,0), actual :" << pt1 << endl;
  
    
    ifstream input_file("Project4/data1.txt");
    if (!input_file.is_open())
      cout << "File not opened\n";
    pt1.read(input_file);
    cout << "Expected: (42,7), actual :" << pt1 << endl;
  */
    return;
}

void test_Color() {
    Color col1;
    col1.setRed(15);
    cout << "Expected: (15, 0, 0), Actual: " << col1 << endl;
    col1.setGreen(23);
    cout << "Expected: (15, 23, 0), Actual: " << col1 << endl;
    col1.setBlue(9);
    cout << "Expected: (15, 23, 9), Actual: " << col1 << endl;
    Color col2;
    col2.setRed(-19);
    cout << "Expected: (0, 0, 0), Actual: " << col2 << endl;
    col2.setGreen(256);
    cout << "Expected: (0, 255, 0), Actual: " << col2 << endl;
    col2.setBlue(999);
    cout << "Expected: (0, 255, 255), Actual: " << col2 << endl;
    cout << "Expected: 255, Actual: " << col2.getBlue() << endl;
    cout << "Expected: 23, Actual: " << col1.getGreen() << endl;
    Color();
    cout << "Expected: (0,0,0), Actual: " << Color() << endl;
    
 
}

void test_Line(){
  Line line1;
  ifstream input_file("Project4/lines.txt");
    line1.read(input_file);
    cout << "Expected: (5,5) (95,5) 255 0 0, actual :" << line1 << endl;
    line1.read(input_file);
    cout << "Expected: (10,10) (95,10) 0 255 0, actual :" << line1 << endl;

  Line line2;
    Point pt3(5,200);
  line2.setEnd(pt3);
  cout << "Expected:" << line2 << endl;
    Point pt4(-10,50);
  line2.setEnd(pt4);
  cout << "Expected" << line2 << endl;
    Point pt5(30,83);
  line2.setEnd(pt5);
  cout << "Expected" << line2 << endl;
    cout << line2.getStart() << endl;

    Line();
    cout << "Expected" << Line() << endl;
    Point point1(19,75);
    Point point2(-13,21);
    Color color1(89,42,177);
    Line line3(point1,point2,color1);
    cout << "Expected" << line3 << endl;
    
  
}

void test_Triangle(){
    Triangle();
    cout << "Expected: (0,0,0), Actual: " << Triangle() << endl;
    Triangle triangle1;
    ifstream input_file("Project4/triangles.txt");
    triangle1.read(input_file);
    cout << "Expected: (80,5) 0 200 5 (50,20) 200 0 5 (85,90) 50 0 5  actual :"
    << triangle1 << endl;

    triangle1.read(input_file);
    cout << "Expected: (10,10) (50,20) (20,40) 200 0 5 , actual :" << triangle1 << endl;
    Point pt1(10,20);
    Point pt2(5,10);
    Point pt3(15,5);
    Point pt4(-1,100);
    Color col1(26,32,80);
    Triangle triangle2(pt1,pt2,pt3,col1);
    cout << triangle2;
    triangle2.getVertexOne();
    triangle2.getVertexTwo();
    triangle2.getVertexThree();
    triangle2.getVertexOneColor();
    triangle2.getVertexTwoColor();
    triangle2.getVertexThreeColor();
    triangle2.setVertexOne(pt4);
    triangle2.setVertexTwo(pt2);
    triangle2.setVertexThree(pt1);
    cout << "Expected: (0,99) , actual :" << triangle2.getVertexOne() << endl;
    cout << "Expected: (5,10) , actual :" << triangle2.getVertexTwo() << endl;
    cout << "Expected: (15, 5), actual :" << triangle2.getVertexThree() << endl;
    cout << "Expected: 26,32,80, actual :" << triangle2.getVertexOneColor() << endl;
    cout << "Expected: 26,32,80, actual :" << triangle2.getVertexTwoColor() << endl;
    cout << "Expected: 26,32,80, actual :" << triangle2.getVertexThreeColor() << endl;
}
void test_Rectangle(){
  Rectangle rectangle1;
  ifstream input_file("Project4/rectangles.txt");
  
    rectangle1.read(input_file);
    cout << "Expected: (0,0) (100,100) 255 255 255  actual :" << rectangle1 << endl;

    rectangle1.read(input_file);
    cout << "Expected: (50,10) (90,90) 255 0 0  0 255 0  0 0 255  255 255 255  actual :" << rectangle1 << endl;

  Rectangle rectangle2;

  cout << "Expected:    " << rectangle2 << endl;

  Point pt1(-99,30);
  Point pt2(90,100);
  Color col1(0,256,190);
  
  Rectangle rectangle3(pt1, pt2, col1);
  cout << "testing get:";
  rectangle3.getEnd();
  cout << rectangle3.getEnd() << endl;

  Color col2(170, 29, 69);
  rectangle3.setColor(col2);

    Point pt3(10,70);
    rectangle3.setStart(pt1);
    rectangle3.setStart(pt2);
    rectangle3.setStart(pt3);
    
    Rectangle();
    cout << Rectangle() << endl;
  
}

void test_Circle(){
    Circle();
    cout << "Expected: , Actual: " << Circle() << endl;
  Circle circle1;
  ifstream input_file("Project4/circles.txt");
  
    circle1.read(input_file);
    cout << "Expected: (20,20) 30 255 0 0  actual :" << circle1 << endl;
    
    Point pt1(69,69);
    Point pt2(42,69);
    Point pt3(69,42);
    Point pt4(42,42);
    Color col89(69,59,420);
    Circle circle5(pt4,20,col89);
    Circle circle2;
    circle2.setCenter(pt1);
    circle2.setRadius(4);
    Circle circle3;
    circle3.setCenter(pt2);
    circle3.setRadius(-10);
    Circle circle4;
    circle4.setCenter(pt3);
    circle4.setRadius(200);
    
    cout << "Expected:  actual :" << circle2 << endl;
    cout << "Expected:  actual :" << circle3 << endl;
    cout << "Expected:  actual :" << circle4 << endl;
  
}



