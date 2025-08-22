#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int decimalNum) {
    if (decimalNum == 0) return "0";
    string binary = "";
    while (decimalNum > 0) {
        binary = to_string(decimalNum % 2) + binary;
        decimalNum /= 2;
    }
    return binary;
}

// Function 2: Binary to Decimal
int binaryToDecimal(string binaryStr) {
    int decimalValue = 0;
    for (char bit : binaryStr) {
        decimalValue = decimalValue * 2 + (bit - '0');
    }
    return decimalValue;
}

// Function 3: Decimal to Hexadecimal
string decimalToHex(int decimalNum) {
    if (decimalNum == 0) return "0";
    string hexChars = "0123456789ABCDEF";
    string hexStr = "";
    while (decimalNum > 0) {
        hexStr = hexChars[decimalNum % 16] + hexStr;
        decimalNum /= 16;
    }
    return hexStr;
}

// Function 4: Hexadecimal to Decimal
int hexToDecimal(string hexStr) {
    int decimalValue = 0;
    for (char c : hexStr) {
        c = toupper(c);
        if (c >= '0' && c <= '9')
            decimalValue = decimalValue * 16 + (c - '0');
        else if (c >= 'A' && c <= 'F')
            decimalValue = decimalValue * 16 + (c - 'A' + 10);
    }
    return decimalValue;
}

// Demo: Random number between 0 and 99 -> Binary
void demoRandomConversion() {
    int number = rand() % 100; // 0–99
    cout << "\nGenerated random integer: " << number << endl;
    cout << "Binary representation: " << decimalToBinary(number) << "\n" << endl;
}

// Menu system
void mainMenu() {
    int choice;
    srand(time(0)); // Seed random generator

    while (true) {
        cout << "Conversion Menu:\n";
        cout << "1. Convert Decimal to Binary\n";
        cout << "2. Convert Binary to Decimal\n";
        cout << "3. Convert Hexadecimal to Decimal\n";
        cout << "4. Convert Decimal to Hexadecimal\n";
        cout << "5. Demo (Generate and convert random integer to binary)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (choice == 1) {
            int dec;
            cout << "Enter a decimal number: ";
            cin >> dec;
            cout << "Binary representation: " << decimalToBinary(dec) << "\n\n";
        } 
        else if (choice == 2) {
            string binary;
            cout << "Enter a binary number: ";
            cin >> binary;
            cout << "Decimal representation: " << binaryToDecimal(binary) << "\n\n";
        } 
        else if (choice == 3) {
            string hex;
            cout << "Enter a hexadecimal number: ";
            cin >> hex;
            cout << "Decimal representation: " << hexToDecimal(hex) << "\n\n";
        } 
        else if (choice == 4) {
            int dec;
            cout << "Enter a decimal number: ";
            cin >> dec;
            cout << "Hexadecimal representation: " << decimalToHex(dec) << "\n\n";
        } 
        else if (choice == 5) {
            demoRandomConversion();
        } 
        else if (choice == 6) {
            cout << "Exiting the program." << endl;
            break;
        } 
        else {
            cout << "Invalid choice. Please enter 1–6.\n\n";
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
