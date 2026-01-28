/*
* CECS 2223, Computer Programming II Laboratory
* Winter 2025, Sec. CECS2223-OL
* Date: 1/31/2026
* Topic: Lab 7 - Description
* File name: Sphere.h
* This file defines a class named Sphere.
*
* Name: Ian Carrasco Rivera, Krizia Cortes Rubio
*
*/

#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Sphere {
private:
    double radius;
    string id;

    static int count;
    static const double PI;

    void generateID();

public:
    Sphere();
    Sphere(const Sphere& other);
    ~Sphere();

    Sphere& operator=(const Sphere& other);

    void setRadius(double r);
    double getRadius() const;

    string getID() const;

    double volume() const;
    void print() const;
};

#endif
