#include <iostream>
#include <string>

using namespace std;

int main()
{
    string firstName, middleName, lastName;

    // Ask the user to enter their first name, middle name, and last name
    cout << "Enter your first name: ";
    getline(cin, firstName);
    cout << "Enter your middle name: ";
    getline(cin, middleName);
    cout << "Enter your last name: ";
    getline(cin, lastName);

    // Generate abbreviated form
    string abbreviatedForm = firstName.substr(0, 1) + ". " + middleName.substr(0, 1) + ". " + lastName;

    // Output the result
    cout << "Abbreviated Name: " << abbreviatedForm << endl;

    return 0;
}