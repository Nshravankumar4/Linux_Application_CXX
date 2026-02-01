#include "InheritanceVehicleCar.h"

// Vehicle constructor
Vehicle::Vehicle() {
    speed = 0;
}

// Parent function
void Vehicle::setSpeed(int s) {
    speed = s;
}

// Child function
void Car::showSpeed() {
    cout << "Car speed is: " << speed << endl;
}

//child function

string Bike::speedLevel() {
    return AlertFunction();
}

string Bike::AlertFunction() {

    if (speed == 0) {
        return "NA";
    }
    else if (speed > 0 && speed <= 60) {
        return "Normal";
    }
    else if (speed > 60 && speed <= 100) {
        return "Orange";
    }
    else if (speed > 100 && speed <= 120) {
        return "OverspeedReached";
    }
    else if (speed > 120 && speed <= 180) {
        return "Red";
    }
    else {
        return "OutOffRange"; 
    }
}

