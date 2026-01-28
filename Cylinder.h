/*
* CECS 2223, Computer Programming II Laboratory
* Winter 2025, Sec. CECS2223-OL
* Date: 1/31/2026
* Topic: Lab 7 - Description
* File name: Cylinder.h
* This file defines a class named Cylinder.
*
* Name: Ian Carrasco Rivera, Krizia Cortes Rubio
*
*/

#ifndef CYLINDER_H
#define CYLINDER_H

#include "Circle.h"
#include <string>

class Cylinder : public Circle {
private:
    double height;
    string id;

    static int count;

    void generateID();   // The ID is not copied, it must be unique

public:
    Cylinder();
    Cylinder(const Cylinder& other);
    ~Cylinder();

    Cylinder& operator=(const Cylinder& other);

    void setHeight(double h);
    double getHeight() const;

    string getID() const;

    double volume() const;
    void print() const;
};

#endif
