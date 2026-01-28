/*
* CECS 2223, Computer Programming II Laboratory
* Winter 2025, Sec. CECS2223-OL
* Date: 1/31/2026
* Topic: Lab 7 - Description
* File name: Warehouse.cpp
* This file implements the Warehouse class methods.
*
* Name: Ian Carrasco Rivera, Krizia Cortes Rubio
*
*/

#include "Warehouse.h"

// Function that is executed when creating an object
Warehouse::Warehouse(string warehouseName) {
    name = warehouseName;
    cylinders = nullptr;
    spheres = nullptr;
    cylinderCount = 0;
    sphereCount = 0;
}

// Function that is executed when the object is deleted.
Warehouse::~Warehouse() {
    // Delete all the cylinders
    for (int i = 0; i < cylinderCount; i++) {
        delete cylinders[i];
    }
    delete[] cylinders;

    // Delete all the spheres
    for (int i = 0; i < sphereCount; i++) {
        delete spheres[i];
    }
    delete[] spheres;
}

// Add a new cylinder
void Warehouse::addCylinder(Cylinder* c) {
    Cylinder** temp = new Cylinder*[cylinderCount + 1];

    for (int i = 0; i < cylinderCount; i++) {
        temp[i] = cylinders[i];
    }

    temp[cylinderCount] = c;

    delete[] cylinders;
    cylinders = temp;
    cylinderCount++;
}

// Add a new sphere
void Warehouse::addSphere(Sphere* s) {
    Sphere** temp = new Sphere*[sphereCount + 1];

    for (int i = 0; i < sphereCount; i++) {
        temp[i] = spheres[i];
    }

    temp[sphereCount] = s;

    delete[] spheres;
    spheres = temp;
    sphereCount++;
}

// Delete a cylinder by index and then print a message saying "removed succesfully"
void Warehouse::deleteCylinder(int index) {
    if (index < 0 || index >= cylinderCount) {
        cout << "Invalid cylinder index." << endl;
        return;
    }
    string removedID = cylinders[index]->getID();


    delete cylinders[index];

    Cylinder** temp = new Cylinder*[cylinderCount - 1];

    int j = 0;
    for (int i = 0; i < cylinderCount; i++) {
        if (i != index) {
            temp[j++] = cylinders[i];
        }
    }

    delete[] cylinders;
    cylinders = temp;
    cylinderCount--;
    cout << "Cylinder " << removedID << " removed successfully." << endl;

}

// Delete a sphere by index and then print a message saying "removed succesfully"
void Warehouse::deleteSphere(int index) {
    if (index < 0 || index >= sphereCount) {
        cout << "Invalid sphere index." << endl;
        return;
    }
    
    string removedID = spheres[index]->getID();
    delete spheres[index];

    Sphere** temp = new Sphere*[sphereCount - 1];

    int j = 0;
    for (int i = 0; i < sphereCount; i++) {
        if (i != index) {
            temp[j++] = spheres[i];
        }
    }

    delete[] spheres;
    spheres = temp;
    sphereCount--;
    
    cout << "Sphere " << removedID << " removed successfully." << endl;

}

// Display all the cylinders stored
void Warehouse::displayCylinders() const {
    cout << "\n--- Cylinders in Warehouse: " << name << " ---\n";
    if (cylinderCount == 0) {
        cout << "No cylinders available.\n";
        return;
    }

    for (int i = 0; i < cylinderCount; i++) {
        cylinders[i]->print();
    }
}

// Display all the spheres stored
void Warehouse::displaySpheres() const {
    cout << "\n--- Spheres in Warehouse: " << name << " ---\n";
    if (sphereCount == 0) {
        cout << "No spheres available.\n";
        return;
    }

    for (int i = 0; i < sphereCount; i++) {
        spheres[i]->print();
    }
}

// Display all the objects that are stored
void Warehouse::displayAll() const {
    displayCylinders();
    displaySpheres();
}
