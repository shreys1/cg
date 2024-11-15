#include <iostream>
#include <string>
#include <memory> // For smart pointers
#include <exception> // For exception handling

using namespace std;

class Address {
public:
    string address;
    string telephone;

    Address(const string &addr = "", const string &tel = "") : address(addr), telephone(tel) {}
};

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string drivingLicence;

    static int studentCount; // Static member to keep count of students

public:
    // Default constructor
    Student() : name("N/A"), rollNumber(0), studentClass("N/A"), division('A'), 
                dateOfBirth("01/01/2000"), bloodGroup("N/A"), contactAddress("N/A"), 
                drivingLicence("N/A") {
        studentCount++;
    }

    // Parameterized constructor
    Student(const string &name, int rollNumber, const string &studentClass, char division, 
            const string &dateOfBirth, const string &bloodGroup, const string &contactAddress, 
            const string &drivingLicence) 
            : name(name), rollNumber(rollNumber), studentClass(studentClass), division(division), 
              dateOfBirth(dateOfBirth), bloodGroup(bloodGroup), contactAddress(contactAddress), 
              drivingLicence(drivingLicence) {
        studentCount++;
    }

    // Copy constructor
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        studentClass = s.studentClass;
        division = s.division;
        dateOfBirth = s.dateOfBirth;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        drivingLicence = s.drivingLicence;
        studentCount++;
    }

    // Static member function to get student count
    static int getStudentCount() {
        return studentCount;
    }

    // Function to display student information
    inline void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Driving Licence: " << drivingLicence << endl;
        cout << "---------------------------" << endl;
    }

    // Friend function to update student address and phone number
    friend void updateAddressAndPhone(Student &student, const string &address, const string &phone);

    // Destructor
    ~Student() {
        studentCount--;
    }
};

// Definition of static member
int Student::studentCount = 0;

// Friend function definition
void updateAddressAndPhone(Student &student, const string &address, const string &phone) {
    student.contactAddress = address;
    cout << "Updated address: " << student.contactAddress << endl;
    cout << "Updated phone: " << phone << endl;
}

int main() {
    try {
        // Dynamic memory allocation and user input for student information
        string name, studentClass, dateOfBirth, bloodGroup, contactAddress, drivingLicence;
        int rollNumber;
        char division;

        cout << "Enter Student's Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // To ignore the newline character left by cin
        cout << "Enter Class: ";
        getline(cin, studentClass);
        cout << "Enter Division (A/B/C...): ";
        cin >> division;
        cin.ignore();
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        getline(cin, dateOfBirth);
        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);
        cout << "Enter Contact Address: ";
        getline(cin, contactAddress);
        cout << "Enter Driving Licence Number: ";
        getline(cin, drivingLicence);

        // Using dynamic memory allocation to create a new student object
        unique_ptr<Student> student1(new Student(name, rollNumber, studentClass, division, dateOfBirth, bloodGroup, contactAddress, drivingLicence));

        // Displaying student information
        cout << "\nStudent Information:\n";
        student1->display();

        // Update address and phone number using friend function
        string newAddress, newPhone;
        cout << "\nEnter New Address to Update: ";
        getline(cin, newAddress);
        cout << "Enter New Phone Number to Update: ";
        getline(cin, newPhone);
        updateAddressAndPhone(*student1, newAddress, newPhone);

        // Display the count of students created
        cout << "Total students: " << Student::getStudentCount() << endl;

        // Memory management using unique_ptr (no need to manually delete)
        
    } catch (const bad_alloc &e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
    } catch (const exception &e) {
        cerr << "An error occurred: " << e.what() << endl;
    }

    // Display the count after the program ends
    cout << "Total students after deletion: " << Student::getStudentCount() << endl;

    return 0;
}

