/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Andrew
 * andrewky
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************
int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

//************************************************************************
// Testing function declarations. Function definition is below main.
// Tests not run by these functions will not be run by the autograder.
//************************************************************************
void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

void startTests()
{
    // Write calls to your test functions here, e. g.,
    test_getMenuChoice();
    test_isGregorianDate();
    test_isLeapYear();
    test_isValidDate();
    test_determineDay();
    test_printDayOfBirth();
    test_determineDayOfBirth();
    test_print10LeapYears();
    
    // Add more calls as you implement more functions.
    // While you're working on a function, it can be useful to comment
    //  out the calls to other functions' tests.

    // Make sure the only function you test in a test function
    //  like test_isGregorianDate is that function (isGregorianDate),
    //  or it may cause issues with the autograder.
}

void test_getMenuChoice()
{
    // getMenuChoice reads from cin, so you will need to
    // provide directions to the user for each test case
    cout << "Now testing funtion getMenuChoice()\n";
    cout << "Please enter 3:" << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice1 << endl;

    cout << "Please enter 5 then 1:";
    int choice2 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice2 << endl;

    // Write additional tests here
}

void test_isGregorianDate()
{
    cout << "Now testing function isGregorianDate()\n";
    cout << "Expected: 1, actual: "
             << isGregorianDate(8, 19, 2016) << endl;
    cout << "Expected: 0, actual: "
             << isGregorianDate(3, 12, 1234) << endl;
    cout << "Expected: 1, actual: "
             << isGregorianDate(7,2, 2003) << endl;
    cout << "Expected: 0, actual: "
             << isGregorianDate(9, 13, 1752) << endl;
    cout << "Expected: 1, actual: "
             << isGregorianDate(9, 14, 1752) << endl;
    cout << "Expected: 0, actual: "
             << isGregorianDate(20, 1, 2003) << endl;
}

void test_isLeapYear()
{
    cout << "Now testing function isLeapYear()\n";
    cout << "1996: Expected: 1, Actual: "
         << isLeapYear(1996) << endl;
    cout << "1997: Expected: 0, Actual: "
         << isLeapYear(1997) << endl;
    cout << "1998: Expected: 0, Actual: "
         << isLeapYear(1998) << endl;
    cout << "1999: Expected: 0, Actual: "
         << isLeapYear(1999) << endl;
    cout << "2000: Expected: 1, Actual: "
         << isLeapYear(2000) << endl;
    cout << "1800: Expected: 0, Actual: "
         << isLeapYear(1800) << endl;
}

void test_isValidDate()
{
    cout << "Now testing function isValidDate()\n";
    cout << "13 / 20 / 1980: Expected: 0, Actual: "
         << isValidDate(13,20,1980) << endl;
    cout << "2/28/2000: Expected: 1, Actual: "
         << isValidDate(2,28,2000) << endl;
    cout << "2/29/2000: Expected: 1, Actual: "
         << isValidDate(2,29,2000) << endl;
    cout << "2/29/2003: Expected: 0, Actual: "
         << isValidDate(2,29,2003) << endl;
    cout << "2/28/2003: Expected: 1, Actual: "
         << isValidDate(2,28,2003) << endl;
    cout << "9/14/1752: Expected: 1, Actual: "
         << isValidDate(9,14,1752) << endl;
    cout << "9/13/1752: Expected: 0, Actual: "
         << isValidDate(9,13,1752) << endl;
}

void test_determineDay()
{
    cout << "1/29/2064: Expected: 3, Actual: "
         << determineDay(1,29,2064) << endl;
    cout << "7/2/2003: Expected: 4, Actual: "
         << determineDay(7,2,2003) << endl;
    cout << "9/13/1750: Expected: 4, Actual: "
         << determineDay(9,13,1750) << endl;
    cout << "9/13/1750: Expected: 2, Actual: "
         << determineDay(9,26,2022) << endl;
}

void test_printDayOfBirth()
{
    // printDayOfBirth prints to cout rather than
    // returning a value.
    cout << "Now testing function printDayOfBirth()\n";
    cout << "1: Expected: Sunday, Actual: ";
    printDayOfBirth(1);
    cout << endl;
    cout << "1: Expected: Monday, Actual: ";
    printDayOfBirth(2);
    cout << endl;
    cout << "1: Expected: Tuesday, Actual: ";
    printDayOfBirth(3);
    cout << endl;
    cout << "1: Expected: Wednesday, Actual: ";
    printDayOfBirth(4);
    cout << endl;

    // Write your tests here
}

void test_determineDayOfBirth()
{
    cout << "Now testing function determineDayofBirth()\n";
    cout << "1: Expected: You were born on a : , Actual: ";
    determineDayOfBirth();
    cout << endl;
}

void test_print10LeapYears()
{
    cout << "Now testing function print10LeapYears()\n";
    cout << "1: Expected: Leap year is 2016, Actual: ";
    print10LeapYears();
    cout << endl;
}
