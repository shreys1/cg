// Write a C++ program using STL for sorting and searching user defined records such as 
// item records item (code, name, cost, quantity) using vector container

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Class to hold information about an item
class Item {
private:
    int code;
    string name;
    double cost;
    int quantity;

public:
    // Constructor to initialize an item
    Item(int code, string name, double cost, int quantity)
        : code(code), name(name), cost(cost), quantity(quantity) {}

    // Accessor methods
    int getCode() const { return code; }
    string getName() const { return name; }
    double getCost() const { return cost; }
    int getQuantity() const { return quantity; }

    // Method to display item details
    void display() const {
        cout << "Code: " << code << ", Name: " << name
             << ", Cost: $" << cost << ", Quantity: " << quantity << endl;
    }

    // Comparison functions for sorting
    static bool compareByCode(const Item &a, const Item &b) {
        return a.getCode() < b.getCode();
    }

    static bool compareByName(const Item &a, const Item &b) {
        return a.getName() < b.getName();
    }

    static bool compareByCost(const Item &a, const Item &b) {
        return a.getCost() < b.getCost();
    }

    static bool compareByQuantity(const Item &a, const Item &b) {
        return a.getQuantity() < b.getQuantity();
    }
};

// Function to add an item to the list
void addItem(vector<Item> &items) {
    int code, quantity;
    double cost;
    string name;

    cout << "Enter item code: ";
    cin >> code;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter item cost: ";
    cin >> cost;
    cout << "Enter item quantity: ";
    cin >> quantity;

    items.emplace_back(code, name, cost, quantity);
}

// Function to sort items based on a given attribute
void sortItems(vector<Item> &items, const string &attribute) {
    if (attribute == "code") {
        sort(items.begin(), items.end(), Item::compareByCode);
    } else if (attribute == "name") {
        sort(items.begin(), items.end(), Item::compareByName);
    } else if (attribute == "cost") {
        sort(items.begin(), items.end(), Item::compareByCost);
    } else if (attribute == "quantity") {
        sort(items.begin(), items.end(), Item::compareByQuantity);
    } else {
        cout << "Invalid attribute for sorting.\n";
        return;
    }
    cout << "Items sorted by " << attribute << ":\n";
    for (const auto &item : items) {
        item.display();
    }
}

// Function to search items by a given code
void searchItemByCode(const vector<Item> &items, int code) {
    auto it = find_if(items.begin(), items.end(), [code](const Item &item) {
        return item.getCode() == code;
    });

    if (it != items.end()) {
        cout << "Item found:\n";
        it->display();
    } else {
        cout << "Item with code " << code << " not found.\n";
    }
}

// Function to search items by a given name
void searchItemByName(const vector<Item> &items, const string &name) {
    auto it = find_if(items.begin(), items.end(), [&name](const Item &item) {
        return item.getName() == name;
    });

    if (it != items.end()) {
        cout << "Item found:\n";
        it->display();
    } else {
        cout << "Item with name " << name << " not found.\n";
    }
}

int main() {
    vector<Item> items;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Item\n";
        cout << "2. Sort Items\n";
        cout << "3. Search Item by Code\n";
        cout << "4. Search Item by Name\n";
        cout << "5. Display All Items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(items);
                break;
            case 2: {
                string attribute;
                cout << "Enter attribute to sort by (code, name, cost, quantity): ";
                cin >> attribute;
                sortItems(items, attribute);
                break;
            }
            case 3: {
                int code;
                cout << "Enter item code to search: ";
                cin >> code;
                searchItemByCode(items, code);
                break;
            }
            case 4: {
                string name;
                cout << "Enter item name to search: ";
                cin.ignore();
                getline(cin, name);
                searchItemByName(items, name);
                break;
            }
            case 5:
                cout << "All items:\n";
                for (const auto &item : items) {
                    item.display();
                }
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
