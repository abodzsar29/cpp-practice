#include <iostream>
using namespace std;

/*
//Abstraction
//Displaying only essential information and hiding the details
//2 ways of Abstraction in C++:
//    Using Classes: Helps us to group data members and member functions using access specifiers (private, public, protected) and to only show certain members to the outside world
//    Using Header Files: Separating the interface and implementation of a class and only importing the Header file to the main.cpp file so user only interacts with the interface
//    The user doesn't need to understand the details within the source file to use the available classes and their methods & attributes


//Example Header File:

#ifndef CAR_H  // checks whether a unique identifier has already been defined
#define CAR_H  // Defining the identifier


class Car {
private:
    bool engineStatus;
    bool fuelSupplyStatus;
    bool ignitionStatus;

public:
    Car();
    void startCar();
    void stopCar();

private:
    void setEngineStatus(bool status);
    void setFuelSupplyStatus(bool status);
    void setIgnitionStatus(bool status);
};

#endif
*/

/*
Source File:
#include "Car.h"
Car::Car() : engineStatus(false), fuelSupplyStatus(false), ignitionStatus(false) {}

void Car::startCar() {  // Abstraction because startCar simplifies the process
    setEngineStatus(true);
    setFuelSupplyStatus(true);
    setIgnitionStatus(true);
    std::cout << "Car has started" << std::endl;
}

void Car::stopCar() {
    setEngineStatus(false);
    setFuelSupplyStatus(false);
    setIgnitionStatus(false);
    std::cout << "Car has stopped" << std::endl;
}

void Car::setEngineStatus(bool status) {
    engineStatus = status;
    std::cout << "Engine status: " << (engineStatus ? "On" : "Off") << std::endl;
}

void Car::setFuelSupplyStatus(bool status) {
    fuelSupplyStatus = status;
    std::cout << "Fuel supply status: " << (fuelSupplyStatus ? "Enabled" : "Disabled") << std::endl;
}

void Car::setIgnitionStatus(bool status) {
    ignitionStatus = status;
    std::cout << "Ignition status: " << (ignitionStatus ? "Engaged" : "Disengaged") << std::endl;
}
*/

//#include "Car.h"
int main() {
    Car myCar;
    myCar.startCar();
    myCar.stopCar();
    return 0;
}