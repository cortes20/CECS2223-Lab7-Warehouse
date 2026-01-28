/*
* CECS 2223, Computer Programming II Laboratory
* Winter 2025, Sec. CECS2223-OL
* Date: 1/31/2026
* Topic: Lab 7 - Description
* File name: Circle.h
* This file defines a class named Circle.
*
* Name:  Ian Carrasco Rivera, Krizia Cortes Rubio
*
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Circle {
private:
    double radius;
    string id;

    static int count;
    static const double PI;

    void generateID();   // creates a unique identifier for the circle

public:
    Circle();                    // Create a new circle with initial value
    Circle(const Circle& other); // Create a new circle by copying data from another circle
    ~Circle();                   // Executes when the circle is removed and frees memory

    Circle& operator=(const Circle& other);

    void setRadius(double r);
    double getRadius() const;

    string getID() const;

    double area() const;
    void print() const;
};

#endif
