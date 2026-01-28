/*
* CECS 2223, Computer Programming II Laboratory
* Winter 2025, Sec. CECS2223-OL
* Date: 1/31/2026
* Topic: Lab 7 - Description
* File name: lab07.cpp
* This file contains the main function and menu logic.
*
* Name: Ian Carrasco Rivera, Krizia Cortes Rubio
*
*/

#include <iostream>
#include <iomanip>
#include <limits>


#include "Warehouse.h"

using namespace std;

// Function declarations
int menu();
void execute(Warehouse& w, int choice);
double getNumber(bool isRadius);
void teamInfo();

int main() {
    Warehouse warehouse("Main Warehouse");
    int choice;

    teamInfo();

    do {
        choice = menu();
        execute(warehouse, choice);
    } while (choice != 8);

    return 0;
}

// Displays all the menu options and returns the choice of the user
int menu() {
    int option;

    cout << "\n===== Warehouse Menu =====\n";
    cout << "1. Add Cylinder\n";
    cout << "2. Add Sphere\n";
    cout << "3. Remove Cylinder\n";
    cout << "4. Remove Sphere\n";
    cout << "5. Display All Cylinders\n";
    cout << "6. Display All Spheres\n";
    cout << "7. Display All Objects\n";
    cout << "8. Exit\n";
    cout << "Select an option: ";
    cin >> option;

    return option;
}

// Executes what the user choose to
void execute(Warehouse& w, int choice) {
    int index;
    double radius, height;

    switch (choice) {
    case 1: { // Add a new Cylinder
        Cylinder* c = new Cylinder();
        radius = getNumber(true);
        height = getNumber(false);

        c->setRadius(radius);
        c->setHeight(height);

        w.addCylinder(c);
        cout << "Cylinder added successfully.\n";
        break;
    }
    case 2: { // Add a new Sphere
        Sphere* s = new Sphere();
        radius = getNumber(true);

        s->setRadius(radius);
        w.addSphere(s);
        cout << "Sphere added successfully.\n";
        break;
    }
    case 3:
    cout << "Enter cylinder index to remove (starting at 0): ";
    cin >> index;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        break;
    }

    w.deleteCylinder(index);
    break;

    case 4: // Remove a Sphere
        cout << "Enter sphere index to remove (starting at 0): ";
        cin >> index;
        w.deleteSphere(index);
        break;

    case 5:
        w.displayCylinders();
        break;

    case 6:
        w.displaySpheres();
        break;

    case 7:
        w.displayAll();
        break;

    case 8:
        cout << "Exiting program...\n";
        break;

    default:
        cout << "Invalid option.\n";
    }
}

// Obtain the radius or height easily
double getNumber(bool isRadius) {
    double value;
    cout << (isRadius ? "Enter radius: " : "Enter height: ");
    cin >> value;
    return value;
}

// Prints the group/team information
void teamInfo() {
    cout << "Solution for CECS 2223, Sec. CECS2223-OL, Lab 7 developed by Team #1 composed of:\n";
    cout << "\tIan Carrasco Rivera, ID #150700\n";
    cout << "\tKrizia Cortes Rubio, ID #155599\n";
}
