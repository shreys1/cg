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
        cout << "\nAudi Car Information:" << endl;
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
        cout << "\nFord Car Information:" << endl;
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
        cout << "\nBajaj Bike Information:" << endl;
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
        cout << "\nTVS Bike Information:" << endl;
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

    char proceed;
    int choice;

    do {
        cout << "\n\nSelect the vehicle you want information about:";
        cout << "\n1. Audi Car";
        cout << "\n2. Ford Car";
        cout << "\n3. Bajaj Bike";
        cout << "\n4. TVS Bike";
        cout << "\nEnter choice (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            audiCar.displayInfo();
            break;
        case 2:
            fordCar.displayInfo();
            break;
        case 3:
            bajajBike.displayInfo();
            break;
        case 4:
            tvsBike.displayInfo();
            break;
        default:
            cout << "Invalid choice. Please select a valid vehicle." << endl;
        }

        cout << "\nDo you want information on another vehicle? (y/n): ";
        cin >> proceed;

    } while (proceed == 'y' || proceed == 'Y');

    cout << "\nProgram Exited Successfully!";
    return 0;
}

