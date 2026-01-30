/*
* CECS 2223, Computer Programming II Laboratory
* Winter 2025, Sec. CECS2223-OL
* Date: 1/31/2026
* Topic: Lab 7 - Description
* File name: Cylinder.cpp
* This file implements the Cylinder class methods.
*
* Name: Ian Carrasco Rivera, Krizia Cortes Rubio
*
*/

#include "Cylinder.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Assign an initial value to the static member
int Cylinder::count = 0;

Cylinder::Cylinder() : Circle() {
    height = 0.0;
    count++;
    generateID();
}

Cylinder::Cylinder(const Cylinder& other) : Circle(other) {
    height = other.height;
    count++;
    generateID();
}

Cylinder::~Cylinder() {
    // No dynamic memory to release
}

Cylinder& Cylinder::operator=(const Cylinder& other) {
    if (this != &other) {
        Circle::operator=(other);
        height = other.height;
        // The ID is not copied; it must be unique
    }
    return *this;
}

void Cylinder::setHeight(double h) {
    height = h;
}

double Cylinder::getHeight() const {
    return height;
}

string Cylinder::getID() const {
    return id;
}

double Cylinder::volume() const {
    return area() * height; // Circle's area() method
}

void Cylinder::print() const {
    cout << fixed << setprecision(2);
    cout << "Cylinder ID: " << id
         << " | Radius: " << getRadius()
         << " | Height: " << height
         << " | Volume: " << volume() << endl;
}

void Cylinder::generateID() {
    int num = count % 100;
    id = "CYL" + to_string(100 + num);
}

}

