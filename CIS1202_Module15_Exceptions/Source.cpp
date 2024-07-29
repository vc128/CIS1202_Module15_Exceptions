//Vivian Chang
//CIS 1202 Section 801
//07-26-24

#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception for invalid characters
class InvalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character (A-Z, a-z)!";
    }
};

// Custom exception for invalid range
class InvalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid range!";
    }
};

char character(char start, int offset) {
    if (!isalpha(start)) {
        throw InvalidCharacterException();
    }

    char target = start + offset;
    if (!isalpha(target)) {
        throw InvalidRangeException();
    }

    return target;
}

int main() {
    try {
        // Test cases
        cout << "character('a', 1): " << character('a', 1) << endl; // Should return 'b'
        //cout << "character('a', -1): " << character('a', -1) << endl; // Should throw an InvalidRangeException
        cout << "character('Z', -1): " << character('Z', -1) << endl; // Should return 'Y'
        cout << "character('?', 5): " << character('?', 5) << endl; // Should throw an InvalidCharacterException
        // Do not allow upper- and lower-case transitions
        cout << "character('A', 32): " << character('A', 32) << endl; // Should throw an exception, not return 'a'
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
