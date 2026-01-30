/*
* CECS 2223, Computer Programming II Laboratory
* Winter 2025, Sec. CECS2223-OL
* Date: 1/31/2026
* Topic: Lab 7 - Description
* File name: Sphere.cpp
* This file implements the Sphere class methods.
*
* Name: Ian Carrasco Rivera, Krizia Cortes Rubio
*
*/

#include "Sphere.h"

int Sphere::count = 0;
const double Sphere::PI = 3.141592653589793;

Sphere::Sphere() {
    radius = 0.0;
    count++;
    generateID();
}

Sphere::Sphere(const Sphere& other) {
    radius = other.radius;
    count++;
    generateID();
}

Sphere::~Sphere() {
    // There is no memory to release
}

Sphere& Sphere::operator=(const Sphere& other) {
    if (this != &other) {
        radius = other.radius;
        // ID is unique
    }
    return *this;
}

void Sphere::setRadius(double r) {
    radius = r;
}

double Sphere::getRadius() const {
    return radius;
}

string Sphere::getID() const {
    return id;
}

double Sphere::volume() const {
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

void Sphere::print() const {
    cout << fixed << setprecision(2);
    cout << "Sphere ID: " << id
         << " | Radius: " << radius
         << " | Volume: " << volume() << endl;
}

void Cylinder::generateID() {
    int num = count % 100;
    std::string numStr = std::to_string(num);
    id = "CYL" + std::string(3 - numStr.length(), '0') + std::to_string(100 + num);
    // Result: CYL100, CYL101, ..., CYL199
}


