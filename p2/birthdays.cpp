/**
 * birthdays.cpp
 * Project UID: 59fc568b7f83f8c109ae360f448f7f821ba0a71
 * 
 * Andrew Ky
 * andrewky
 *
 * EECS 183: Project 2
 *
 * The birthdays program will display a menu option for the user to (a) determine what day of the week the user's birthday is or (b) print out the next 10 leap years after an inputted year.
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();

/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 *
 *           This function must call isLeapYear().
 */
void print10LeapYears();

/* 
 * EFFECTS: Main driver for the Birthdays program. See the
 *          "Putting it Together" section of the spec for what
 *          this function needs to accomplish.
 */
void birthdays() {    
    printHeading();
    int choice = getMenuChoice();
    while (choice != 3){
    if (choice == 1){
        determineDayOfBirth();
        choice = getMenuChoice();
    }
    else if (choice == 2){
        print10LeapYears();
        choice = getMenuChoice();
    }
    }
    printCloser();
    }


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    printMenu();
    int userChoice;
    cin >> userChoice;
    while ((userChoice != 1) && (userChoice != 2) && (userChoice != 3)){
        cout << endl << "Invalid menu choice" << endl;
        printMenu();
        cin >> userChoice;
    }
    return userChoice;
}

bool isGregorianDate(int month, int day, int year) {
    bool gregorianValid = false;
    // 1752 is used because it is the first Gregorian year
    if (year > 1752){
        gregorianValid = true;
    }
    else if (year == 1752){
        // September is the 9th month, and the month the Gregorian calendar started
        if (month > 9){
            gregorianValid = true;
        }
        // The 14th day of September (9) is the first day of the Gregorian calendar
        else if ((month == 9) && (day >= 14)){
            gregorianValid = true;
        }
    }
    else{
        gregorianValid = false;
        
    }
    return gregorianValid;
}

bool isLeapYear(int year) {
    bool leapValid = false;
    // 4 is used because a leap year occurs every 4 years
    // if year is evenly divisble by 100, it is not a leap year, unless
    // the year is evenly divisble by 400, then it is a leap year
    if ((year % 4 == 0) & (year % 100 != 0)){
        leapValid = true;
    }
    else if ((year % 4 == 0) & (year % 100 == 0) & (year % 400 == 0)) {
        leapValid = true;
    }
    else{
        leapValid = false;
        }
    return leapValid;
}


bool isValidDate(int month, int day, int year) {
    bool dateValid = false;
    if (isGregorianDate(month, day, year) == true){
        // 1-12 are used for the months and 1-31 are used for the number of days
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8
             || month == 10 || month == 12) && (day > 0) && (day <= 31) ){
            dateValid = true;
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day <= 30)
                 && (day > 0) && (isGregorianDate(month, day, year) == true)){
            dateValid = true;
        }
        else if (month == 2){
            if (isLeapYear(year) == true && (day <= 29) && (day > 0)){
                dateValid = true;
            }
            else if (isLeapYear(year) == false && (day <=28) && (day > 0)){
                dateValid = true;
            }
        }
    else{
        dateValid = false;
    }
    }
    return dateValid;
}


int determineDay(int month, int day, int year) {
    // Zeller's Formula will be used (including constants 1, 4, 5, 13, and mod 7)
    //to calculate a value f, to determine the day of the week
    int zellerValue;
    // 13 and 14 are used for January and Feburary as months of the previous year
    // minus 1 to get the previous year
    if (month == 1){
        month = 13;
        year = year - 1;
    }
    else if (month == 2){
        month = 14;
        year = year - 1;
    }
    else{
        month = month;
    }
    // Using integer and mod divison by 100 in order to get first and last 2 digits
    int century = year / 100;
    int yearFinal = year % 100;
    zellerValue = (day + (floor((13 * (month + 1))) / 5) + yearFinal
                   + (floor(yearFinal / 4)) + (floor(century / 4)) + 5 * century);
    zellerValue = zellerValue % 7;
        // returning 0 to avoid compile error
    return zellerValue;
}


void printDayOfBirth(int day) {
    // 0-6 are the values f of Zeller's rule that correlate with the days
    if (day == 0){
        cout << "Saturday";
    }
    else if (day == 1){
        cout << "Sunday";
    }
    else if (day == 2){
        cout << "Monday";
    }
    else if (day == 3){
        cout << "Tuesday";
    }
    else if (day == 4){
        cout << "Wednesday";
    }
    else if (day == 5){
        cout << "Thursday";
    }
    else if (day == 6){
        cout << "Friday";
    }
    return;
}


void determineDayOfBirth() {
    cout << endl << "Enter your date of birth" << endl;
    cout << "format: month / day / year --> ";
    int month;
    cin >> month;
    char discard;
    cin >> discard;
    int day;
    cin >> day;
    cin >> discard;
    int year;
    cin >> year;
    cout << endl;
    if (isValidDate(month, day, year) == true){
        cout << "You were born on a: ";
        printDayOfBirth(determineDay(month,day,year));
        cout << endl << endl << "Have a great birthday!!!" << endl;
        
    }
    else{
        cout << endl << "Invalid date" << endl;
    }
    
    return;
}

void print10LeapYears() {
    cout << endl << "Enter year --> ";
    int year;
    cin >> year;
    cout << endl;
    int counter = 0;
    if (year >= 1752){
        year = year + 1;
        // loop will only update counter if "Leap year is" is printed
        while (counter != 10){
            if (isLeapYear(year) == true){
                cout << "Leap year is " << year << endl;
                year = year + 1;
                counter++;
                }
            else{
                year = year + 1;
            }
            }
    }
    return;
}
