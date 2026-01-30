/*
* CECS 2223, Computer Programming II Laboratory
* Winter 2025, Sec. CECS2223-OL
* Date: 1/31/2026
* Topic: Lab 7 - Description
* File name: Circle.cpp
* This file implements the Circle class methods.
*
* Name: Ian Carrasco Rivera, Krizia Cortes Rubio
*
*/

#include "Circle.h"

// Assign initial value to static variables
int Circle::count = 0;
const double Circle::PI = 3.141592653589793;

Circle::Circle() {
    radius = 0.0;
    count++;
    generateID();
}

Circle::Circle(const Circle& other) {
    radius = other.radius;
    count++;
    generateID();
}

Circle::~Circle() {
    // There is no memory to release
}

Circle& Circle::operator=(const Circle& other) {
    if (this != &other) {
        radius = other.radius;
        // The ID is not copied; it must be unique
    }
    return *this;
}

void Circle::setRadius(double r) {
    radius = r;
}

double Circle::getRadius() const {
    return radius;
}

string Circle::getID() const {
    return id;
}

double Circle::area() const {
    return PI * radius * radius;
}

void Circle::print() const {
    cout << fixed << setprecision(2);
    cout << "Circle ID: " << id
         << " | Radius: " << radius
         << " | Area: " << area() << endl;
}

void Circle::generateID() {
    int num = count % 100;
    id = "CIR" + (num < 10 ? "0" : "") + to_string(num);
}

}

