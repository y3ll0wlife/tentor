/*
 * Question 3
 * Define the classes in the diagram.
 * Notice that a minus symbol ('-') before the class member means it private and a plus symbol ('+') means that the
 * member is public.
 */

#include <string>
#include <vector>

class Engine {
public:
    int size;
    int numberOfCylinders;
};

class Wheel {
public:
    int size;
    std::string color;
};

class Door {
public:
    int size;
    std::string type;
};

class Vehicle {
private:
    int id;
    int weight;
    std::string fuel;
public:
    int getId() { return id; };
    int getWeight() { return weight; };
    std::string getFuel() { return fuel; };

};

class Car : public Vehicle {
public:
    bool manualGrearbox;
    std::string color;

    Engine engine;
    std::vector<Wheel> wheels;
    std::vector<Door> doors;

    Engine getEngine() { return engine; };
    int getNumberOfDoors() { return doors.size(); };
    int GetNumberOfWheels() { return wheels.size(); };

    ~Car() {
        wheels.clear();
        doors.clear();
    }
};