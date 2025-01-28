/**
 * focaccia.cpp
 *
 * Andrew Ky
 * andrewky
 *
 * EECS 183: Project 1
 * Fall 2022
 *
 * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;


double bagsFlour(double loaves) {
    const double FLOUR_CUPS_PER_LOAF = 5.00;
    const double FLOUR_CUPS_PER_BAG = 20.00;
    double flourBags = 1.00;
    // calculate the number of flour bags needed for x number of loaves
    flourBags = (loaves * FLOUR_CUPS_PER_LOAF) / FLOUR_CUPS_PER_BAG;
    return ceil(flourBags);
}

double packagesYeast(double loaves){
    const double YEAST_TEASPOON_PER_LOAF = 1.75;
    const double YEAST_TEASPOON_PER_PACKAGE = 2.25;
    double yeastPackages = 1.00;
    // calculate number of yeast packets needed for x number of loaves
    yeastPackages = (loaves * YEAST_TEASPOON_PER_LOAF) / YEAST_TEASPOON_PER_PACKAGE;
    return ceil(yeastPackages);
}

double canisterSalt(double loaves) {
    const double SALT_TEASPOONS_PER_LOAF = 1.875;
    const double SALT_GRAMS_PER_CANISTER = 30.00;
    const double GRAMS_PER_TEASPOON = 5.00;
    double saltCanister = 1.0;
    // convert grams of salt to teaspoon and calculate how many needed for x loaves
    saltCanister = ((SALT_TEASPOONS_PER_LOAF * GRAMS_PER_TEASPOON) * loaves);
    // calculate how many canisters needed for x loaves
    saltCanister = saltCanister / SALT_GRAMS_PER_CANISTER;
    return ceil(saltCanister);
}

double bottleOil(double loaves) {
    const double OIL_TBS_PER_LOAF = 2.00;
    const double OIL_MLITER_PER_BOTTLE = 500.00;
    const double MLITER_PER_TBS = 14.80;
    double oilBottle = 1;
    // convert tablespoons of oil to milliliters, calculate how much for x loaves
    oilBottle = ((OIL_TBS_PER_LOAF * MLITER_PER_TBS) * loaves);
    // calculate number of oil bottles needed
    oilBottle = oilBottle / OIL_MLITER_PER_BOTTLE;
    return ceil(oilBottle);
}

double totalCost(double flour, double yeast, double salt, double oil) {
    const double FLOUR_COST_PER_BAG = 2.69;
    const double YEAST_COST_PER_PACKAGE = 0.40;
    const double SALT_COST_PER_CANISTER = 0.49;
    const double OIL_COST_PER_BOTTLE = 6.39;
    double cost = 0.00;
    cost = (flour * FLOUR_COST_PER_BAG) + (yeast * YEAST_COST_PER_PACKAGE);
    cost = cost + (salt * SALT_COST_PER_CANISTER) + (oil * OIL_COST_PER_BOTTLE);
    return cost;
}

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}

int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;
    
    // NUMBER OF PEOPLE TO LOAVES
    double loaves = 4.0;
    loaves = ceil(people / loaves);
    cout << "You need to make: " << loaves << " "
         << pluralize("loaf", "loaves", loaves) << " of focaccia" << endl << endl;
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;

    cout << bagsFlour(loaves) << pluralize(" bag", " bags", bagsFlour(loaves))
         << " of flour" << endl;
    
    cout << packagesYeast(loaves)
         << pluralize(" package", " packages", packagesYeast(loaves))
         << " of yeast" << endl;
    
    cout << canisterSalt(loaves)
         << pluralize(" canister", " canisters", canisterSalt(loaves))
         << " of salt" << endl;
    
    cout << bottleOil(loaves) << pluralize(" bottle", " bottles", bottleOil(loaves))
         << " of olive oil" << endl << endl;
    
    
    cout << "Total expected cost of ingredients: $"
         << totalCost(bagsFlour(loaves), packagesYeast(loaves)
            , canisterSalt(loaves), bottleOil(loaves));
    cout << endl << endl;
    cout << "Have a great party!" << endl;

    return 0;
}

