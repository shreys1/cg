// develop a CPP program to create database of student information system containing the following information:
// name, roll number, class, division, date of birth, blood group, contact address, telephone number, driving licence and other.
// construct the database with suitable member functions make use of constructor, default constructor, copy constructor, static Member function, friend class, this pointer, inline code and dynamic memory allocation, operators, new and delete as well as exception handling

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
        // Dynamic memory allocation using new operator
        Student *student1 = new Student("John Doe", 1, "10th", 'A', "12/12/2005", "O+", "123 Street, NY", "D1234567");
        Student *student2 = new Student(*student1); // Using copy constructor

        // Displaying student information
        cout << "Student 1 Information:" << endl;
        student1->display();

        cout << "Student 2 (Copy) Information:" << endl;
        student2->display();

        // Inline function and this pointer demonstration
        cout << "Using this pointer to display Student 1 information again:" << endl;
        student1->display();

        // Updating student1's address and phone using a friend function
        updateAddressAndPhone(*student1, "456 Avenue, NY", "555-1234");

        // Display the count of students created
        cout << "Total students: " << Student::getStudentCount() << endl;

        // Free allocated memory
        delete student1;
        delete student2;

    } catch (const bad_alloc &e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
    } catch (const exception &e) {
        cerr << "An error occurred: " << e.what() << endl;
    }

    // Display the count after deletion
    cout << "Total students after deletion: " << Student::getStudentCount() << endl;

    return 0;
}
