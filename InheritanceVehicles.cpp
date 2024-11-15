// We want to store the information of different vehicles. 
// Create a class named Vehicle with two data member named mileage and price. 
// Create its two subclasses *Car with data members to store ownership cost, warranty (by years). 
// seating capacity and fuel type (diesel or petrol). 
// *Bike with data members to store the number of cylinders, number of gears, cooling type(air, liquid or oil), wheel type(alloys or spokes) and fuel tank size(in inches) Make another two subclasses Audi and Ford of Car, each having a data member to store the model type. Next, make two subclasses Bajaj and TVS, each having a data member to store the make-type. Now, store and print the information of an Audi and a Ford car (i.e. model type, ownership cost, warranty, seating capacity, fuel type, mileage and price.) 
// Do the same for a Bajaj and a TVS bike.

#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    double mileage;
    double price;

public:
    Vehicle(double mileage, double price) : mileage(mileage), price(price) {}
};

class Car : public Vehicle {
protected:
    double ownershipCost;
    int warranty; // in years
    int seatingCapacity;
    string fuelType; // diesel or petrol

public:
    Car(double mileage, double price, double ownershipCost, int warranty, int seatingCapacity, string fuelType)
        : Vehicle(mileage, price), ownershipCost(ownershipCost), warranty(warranty),
          seatingCapacity(seatingCapacity), fuelType(fuelType) {}
};

class Bike : public Vehicle {
protected:
    int cylinders;
    int gears;
    string coolingType; // air, liquid, or oil
    string wheelType; // alloys or spokes
    double fuelTankSize; // in inches

public:
    Bike(double mileage, double price, int cylinders, int gears, string coolingType, string wheelType, double fuelTankSize)
        : Vehicle(mileage, price), cylinders(cylinders), gears(gears), coolingType(coolingType),
          wheelType(wheelType), fuelTankSize(fuelTankSize) {}
};

class Audi : public Car {
private:
    string modelType;

public:
    Audi(double mileage, double price, double ownershipCost, int warranty, int seatingCapacity, string fuelType, string modelType)
        : Car(mileage, price, ownershipCost, warranty, seatingCapacity, fuelType), modelType(modelType) {}

    void displayInfo() {
        cout << "Audi Car Information:" << endl;
        cout << "Model Type: " << modelType << endl;
        cout << "Ownership Cost: " << ownershipCost << endl;
        cout << "Warranty: " << warranty << " years" << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileage << " km/l" << endl;
        cout << "Price: $" << price << endl;
    }
};

class Ford : public Car {
private:
    string modelType;

public:
    Ford(double mileage, double price, double ownershipCost, int warranty, int seatingCapacity, string fuelType, string modelType)
        : Car(mileage, price, ownershipCost, warranty, seatingCapacity, fuelType), modelType(modelType) {}

    void displayInfo() {
        cout << "Ford Car Information:" << endl;
        cout << "Model Type: " << modelType << endl;
        cout << "Ownership Cost: " << ownershipCost << endl;
        cout << "Warranty: " << warranty << " years" << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileage << " km/l" << endl;
        cout << "Price: $" << price << endl;
    }
};

class Bajaj : public Bike {
private:
    string makeType;

public:
    Bajaj(double mileage, double price, int cylinders, int gears, string coolingType, string wheelType, double fuelTankSize, string makeType)
        : Bike(mileage, price, cylinders, gears, coolingType, wheelType, fuelTankSize), makeType(makeType) {}

    void displayInfo() {
        cout << "Bajaj Bike Information:" << endl;
        cout << "Make Type: " << makeType << endl;
        cout << "Cylinders: " << cylinders << endl;
        cout << "Gears: " << gears << endl;
        cout << "Cooling Type: " << coolingType << endl;
        cout << "Wheel Type: " << wheelType << endl;
        cout << "Fuel Tank Size: " << fuelTankSize << " inches" << endl;
        cout << "Mileage: " << mileage << " km/l" << endl;
        cout << "Price: $" << price << endl;
    }
};

class TVS : public Bike {
private:
    string makeType;

public:
    TVS(double mileage, double price, int cylinders, int gears, string coolingType, string wheelType, double fuelTankSize, string makeType)
        : Bike(mileage, price, cylinders, gears, coolingType, wheelType, fuelTankSize), makeType(makeType) {}

    void displayInfo() {
        cout << "TVS Bike Information:" << endl;
        cout << "Make Type: " << makeType << endl;
        cout << "Cylinders: " << cylinders << endl;
        cout << "Gears: " << gears << endl;
        cout << "Cooling Type: " << coolingType << endl;
        cout << "Wheel Type: " << wheelType << endl;
        cout << "Fuel Tank Size: " << fuelTankSize << " inches" << endl;
        cout << "Mileage: " << mileage << " km/l" << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    Audi audiCar(15.5, 50000, 5000, 3, 5, "Petrol", "Q7");
    Ford fordCar(12.0, 40000, 4500, 2, 5, "Diesel", "Mustang");
    Bajaj bajajBike(40.0, 1500, 2, 5, "Air", "Alloys", 15, "Pulsar");
    TVS tvsBike(45.0, 1300, 1, 4, "Oil", "Spokes", 10, "Apache");

    audiCar.displayInfo();
    cout << endl;
    fordCar.displayInfo();
    cout << endl;
    bajajBike.displayInfo();
    cout << endl;
    tvsBike.displayInfo();

    return 0;
}
