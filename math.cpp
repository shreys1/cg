#include <iostream>
#include <math.h>
using namespace std;

int factorial(int x)
{
    int fact = 1;
    for (int i = x; i >= 1; i--)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    int a, b, c, choice;
    char proceed;

    do
    {
        cout << "\n\n**MENU**";
        cout << "\n1. Square";
        cout << "\n2. Cube";
        cout << "\n3. Square Root";
        cout << "\n4. Factorial";
        cout << "\n5. Sum";
        cout << "\n6. Product";
        cout << "\n7. Subtraction";
        cout << "\n8. Division";
        cout << "\n9. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 8)
        {
            cout << "\nEnter Number a: ";
            cin >> a;
            cout << "Enter Number b: ";
            cin >> b;
        }

        switch (choice)
        {
        case 1:
            cout << "\nSquare of a is " << a * a;
            cout << "\nSquare of b is " << b * b;
            break;

        case 2:
            cout << "\nCube of a is " << a * a * a;
            cout << "\nCube of b is " << b * b * b;
            break;

        case 3:
            cout << "\nSquare Root of a is " << sqrt(a);
            cout << "\nSquare Root of b is " << sqrt(b);
            break;

        case 4:
            cout << "\nFactorial of " << a << " is " << factorial(a);
            cout << "\nFactorial of " << b << " is " << factorial(b);
            break;

        case 5:
            cout << "\nSum is " << a + b;
            break;

        case 6:
            cout << "\nProduct is " << a * b;
            break;

        case 7:
            cout << "\nSubtraction is " << a - b;
            break;

        case 8:
            if (b != 0)
            {
                cout << "\nDivision is " << static_cast<double>(a) / b;
            }
            else
            {
                cout << "\nError: Division by zero is not allowed.";
            }
            break;

        case 9:
            cout << "\nExiting the program.";
            break;

        default:
            cout << "\nInvalid Choice.";
        }

        if (choice != 9)
        {
            cout << "\n\nDo you want to perform another task? (y/n): ";
            cin >> proceed;
        }

    } while (choice != 9 && (proceed == 'y' || proceed == 'Y'));

    cout << "\nProgram Exited Successfully!";
    return 0;
}

