//Siddhesh gite
/*
Write a program to create a directory that contains the following
information.
(a) Name of a person
(b) Address
(c) Telephone Number (if available with STD code)
(d) Mobile Number (if available)
(e) Head of the family
*/
#include <iostream>
#include <string>

using namespace std;

class employee {
private:
    float id;
    long tel;
    string n, f, s;

public:
    void info() {
        cin.ignore();  // To ignore the newline character left in the buffer
        cout << "Enter name: ";
        getline(cin, n);
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter tel: ";
        cin >> tel;
        cin.ignore();  // Ignore the newline character left in the buffer
        cout << "Enter address: ";
        getline(cin, s);
        cout << "Enter family head: ";
        getline(cin, f);
        cout<<"________________________"<<endl;
    }

    void display() const {
        cout << "Name: " << n << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Phone number: " << tel << endl;
        cout << "Address: " << s << endl;
        cout << "Family head: " << f << endl;
        cout<<"________________________"<<endl;
    }
};

int main() {
    int i;
    employee e[i];
    cout << "Enter number of employees : ";
    cin >> i;
for (int j = 0; j < i; j++) {
        cout << "Information of person " << (j + 1) << endl;
        e[j].info();
      
    }
for (int j = 0; j < i; j++) {
        cout << "Information of person " << (j + 1) << endl;
        e[j].display();
      
    }
    return 0;
}

