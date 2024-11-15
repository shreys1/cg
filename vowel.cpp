// Write a C ++ program to find the number of vowels, 
// consonants, digits and white spaces characters in a string

#include <iostream>
#include <string>

using namespace std;

void countCharacters(const string &str) {
    int vowels = 0, consonants = 0, digits = 0, whitespaces = 0;

    for (char ch : str) {
        if (isalpha(ch)) {
            // Check if the character is a vowel
            char lowerCh = tolower(ch);
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(ch)) {
            digits++;
        } else if (isspace(ch)) {
            whitespaces++;
        }
    }

    cout << "Number of vowels: " << vowels << endl;
    cout << "Number of consonants: " << consonants << endl;
    cout << "Number of digits: " << digits << endl;
    cout << "Number of white spaces: " << whitespaces << endl;
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    countCharacters(input);

    return 0;
}