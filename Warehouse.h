/*
* CECS 2223, Computer Programming II Laboratory
* Winter 2025, Sec. CECS2223-OL
* Date: 1/31/2026
* Topic: Lab 7 - Description
* File name: Warehouse.h
* This file defines a class named Warehouse.
*
* Name: Ian Carrasco Rivera, Krizia Cortes Rubio
*
*/

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Cylinder.h"
#include "Sphere.h"

using namespace std;

class Warehouse {
private:
    string name;

    Cylinder** cylinders;
    Sphere** spheres;

    int cylinderCount;
    int sphereCount;

public:
    Warehouse(string warehouseName = "Default Warehouse");
    ~Warehouse();

    // Add a method
    void addCylinder(Cylinder* c);
    void addSphere(Sphere* s);

    // Delete a methods
    void deleteCylinder(int index);
    void deleteSphere(int index);

    // Display the methods
    void displayCylinders() const;
    void displaySpheres() const;
    void displayAll() const;
};

#endif
