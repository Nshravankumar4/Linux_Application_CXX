#ifndef VEHICLECAR_H
#define VEHICLECAR_H

#include <iostream>
#include <string>
using namespace std;

// Parent class
class Vehicle {
protected:
    int speed;

public:
    Vehicle();          // constructor
    void setSpeed(int s);
};

// Child class
class Car : public Vehicle {
public:
    void showSpeed();
};

//child class
class Bike : public Vehicle {
public:
     string speedLevel();
     string AlertFunction();
};
#endif
