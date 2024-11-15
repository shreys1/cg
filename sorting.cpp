// Write a function template for selection sort that input,sort and output 
// integer, float, character and string array
#include <iostream>
#include <string>
using namespace std;

// Function template for Selection Sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function template to print the array
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test with an integer array
    int intArr[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Integer array before sorting: ";
    printArray(intArr, intSize);
    selectionSort(intArr, intSize);
    cout << "Integer array after sorting: ";
    printArray(intArr, intSize);

    // Test with a float array
    float floatArr[] = {64.5, 25.2, 12.1, 22.8, 11.0};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    cout << "\nFloat array before sorting: ";
    printArray(floatArr, floatSize);
    selectionSort(floatArr, floatSize);
    cout << "Float array after sorting: ";
    printArray(floatArr, floatSize);

    // Test with a character array
    char charArr[] = {'d', 'b', 'a', 'c', 'e'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    cout << "\nCharacter array before sorting: ";
    printArray(charArr, charSize);
    selectionSort(charArr, charSize);
    cout << "Character array after sorting: ";
    printArray(charArr, charSize);

    // Test with a string array
    string strArr[] = {"apple", "orange", "banana", "kiwi", "mango"};
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    cout << "\nString array before sorting: ";
    printArray(strArr, strSize);
    selectionSort(strArr, strSize);
    cout << "String array after sorting: ";
    printArray(strArr, strSize);

    return 0;
}
