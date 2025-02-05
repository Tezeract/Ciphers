/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Joel Iacoban
 * joeliaco
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * Runs main program and does cipher based on chosen pathways
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************




/*
 * Requires: Nothing.
 * Modifies: cin, cout, message, caesarKey
 * Effects: Encrypts a string using the Caesar cipher,
 * and outputs the result.
 */
void caesarEncrypt();

/*
 * Requires: Nothing.
 * Modifies: cin, cout, message, caesarKey
 * Effects: Decrypts a string using the Caesar cipher,
 * and outputs the result.
 */
void caesarDecrypt();

/*
 * Requires: Nothing.
 * Modifies: cin, cout, message, vigenereKey,
 * Effects: Encrypts a string using the Vigenere cipher,
 * and outputs the result.
 */
void vigenereEncrypt();

/*
 * Requires: Nothing.
 * Modifies: cin, cout, message, vigenereKey
 * Effects: Decrypts a string using the Vigenere cipher,
 * and outputs the result.
 */
void vigenereDecrypt();

/*
 * Requires: Nothing.
 * Modifies: cin, cout, message, polybiusKey
 * Effects: Encrypts a string using the Polybius cipher,
 * and then outputs the result.
 */
void polybiusEncrypt();

/*
 * Requires: Nothing.
 * Modifies: cin, cout, message, polybiusKey
 * Effects: Decrypts a string using the Polybius cipher,
 * and then output
 */
void polybiusDecrypt();

void ciphers() {
    
    // Helper declarations for use in the cipher pathways
    string choice = "";
    string encryptOrDecrypt = "";

    
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    cin >> choice;
    
    // Converts cipher choice to uppercase for ease of checking
    choice = toUpperCase(choice);
    
    // Caesar path
    if (choice == "CAESAR" || choice == "C") {
        cout << "Encrypt or decrypt: ";
        cin >> encryptOrDecrypt;
        
        // Converts encryption choice to uppercase for ease of checking
        encryptOrDecrypt = toUpperCase(encryptOrDecrypt);
        
        // Encrypts a message using Caesar cipher
        if (encryptOrDecrypt == "ENCRYPT" || encryptOrDecrypt == "E") {
            caesarEncrypt();
            return;
        }
        
        // Decrypts a message using Caesar cipher
        if (encryptOrDecrypt == "DECRYPT" || encryptOrDecrypt == "D") {
            caesarDecrypt();
            return;
        }
        
        // Ends program if invaid encryption mode is inputted
        if(encryptOrDecrypt != "ENCRYPT" || encryptOrDecrypt !="E") {
            if (encryptOrDecrypt != "DECRYPT" || "D") {
                cout << "Invalid mode!";
                return;
            }
        }
    }

// -----------------------------------------------------------------------
    
    // Vigenere path
    else if (choice == "VIGENERE" || choice == "V") {
        cout << "Encrypt or decrypt: ";
        cin >> encryptOrDecrypt;
        
        // Converts encryption choice to uppercase for ease of checking
        encryptOrDecrypt = toUpperCase(encryptOrDecrypt);
        
        if (encryptOrDecrypt == "ENCRYPT" || encryptOrDecrypt == "E") {
            vigenereEncrypt();
            return;
           
        }
       
        // Decryption
        if (encryptOrDecrypt == "DECRYPT" || encryptOrDecrypt == "D") {
            vigenereDecrypt();
            return;
        }
        
        // Ends program if invaid encryption mode is inputted
        if(encryptOrDecrypt != "ENCRYPT" || encryptOrDecrypt !="E") {
            if (encryptOrDecrypt != "DECRYPT" || "D") {
                cout << "Invalid mode!";
                return;
            }
        }
    }
    
// -----------------------------------------------------------------------
    
    // Polybius path
    
    else if (choice == "POLYBIUS" || choice == "P") {
        cout << "Encrypt or decrypt: ";
        cin >> encryptOrDecrypt;
        
        // Converts encryption choice to uppercase for ease of checking
        encryptOrDecrypt = toUpperCase(encryptOrDecrypt);
        
        // Encryption
        if (encryptOrDecrypt == "ENCRYPT" || encryptOrDecrypt == "E") {
            polybiusEncrypt();
            return;
            }
        
        // Decryption
        if (encryptOrDecrypt == "DECRYPT" || encryptOrDecrypt == "D") {
            polybiusDecrypt()  ;
            return;
        }
        
        // Ends program if invaid encryption mode is inputted
        if(encryptOrDecrypt != "ENCRYPT" || encryptOrDecrypt !="E") {
            if (encryptOrDecrypt != "DECRYPT" || "D") {
                cout << "Invalid mode!";
                return;
            }
        }
    }
    else {
        cout << "Invalid cipher!" << endl;
        return;
    }
}

// For all functions below
// cin.ignore(); is used to clear the cin buffer from the encryption choice

void caesarEncrypt() {
    string message = "";
    int caesarKey = 0;
    
    cin.ignore();
    
    cout << "Enter a message: ";
    getline(cin, message);
    
    cout << "What is your key: ";
    cin >> caesarKey;
    
    cout << "The encrypted message is: ";
    cout << caesarCipher(message, caesarKey, true) << endl;
}

void caesarDecrypt() {
    string message = "";
    int caesarKey = 0;
    
    cin.ignore();
    
    cout << "Enter a message: ";
    getline(cin, message);
    
    cout << "What is your key: ";
    cin >> caesarKey;
    
    cout << "The decrypted message is: ";
    cout << caesarCipher(message, caesarKey, false) << endl;
}

void vigenereEncrypt() {
    string vigenereKey = "";
    string message = "";
    
    cin.ignore();
    
    cout << "Enter a message: ";
    getline(cin, message);
    
    cout << "What is your key: ";
    getline(cin, vigenereKey);
    
    // Makes sure at least one alpha is in the key based on RME
    int alphacount = 0;
    for (int i = 0; i < vigenereKey.size(); i++) {
        if (isalpha(vigenereKey[i])) {
            alphacount++;
        }
    }
    if (alphacount == 0) {
        cout << "Invalid key!" << endl;
        
        return;
    }
   
    cout << "The encrypted message is: ";
    cout << vigenereCipher(message, vigenereKey, true) << endl;
   
    return;
}

void vigenereDecrypt() {
    string vigenereKey = "";
    string message = "";
    
    cin.ignore();
    
    cout << "Enter a message: ";
    getline(cin, message);
    
    cout << "What is your key: ";
    getline(cin, vigenereKey);
    
    // Makes sure at least one alpha is in the key
    int alphacount = 0;
    for (int i = 0; i < vigenereKey.size(); i++) {
        if (isalpha(vigenereKey[i])) {
            alphacount++;
        }
    }
    if (alphacount == 0) {
        cout << "Invalid key!" << endl;
        
        return;
    }
   
    cout << "The decrypted message is: ";
    cout << vigenereCipher(message, vigenereKey, false) << endl;
   
    return;
    
}

void polybiusEncrypt() {
    string message = "";
    string polybiusKey = "";
    char grid[SIZE][SIZE];
    
    cin.ignore();
    
    cout << "Enter a message: ";
    getline(cin, message);
    message = toUpperCase(message);
    
    // Makes sure message has only alphanumerics or spaces
    int nonAlnumOrSpaceCount = 0;
    for (int i = 0; i < message.size(); i++) {
        if (message[i] != ' ' && !isalnum(message[i]))
            nonAlnumOrSpaceCount++;
    }
    if (nonAlnumOrSpaceCount > 0) {
        cout << "Invalid message!" << endl;
        return;
    }
    
    cout << "What is your key: ";
    getline(cin, polybiusKey);
    
    // Makes sure the key is only alphanumeric, if not ends program
    for (int i = 0; i < polybiusKey.size(); i++) {
        if (!isalnum(polybiusKey[i])) {
            cout << "Invalid key!" << endl;
            return;
        }
    }
    
    // Capitalizes the key and removes duplicates to work in cipher
    polybiusKey = toUpperCase(polybiusKey);
    polybiusKey = removeDuplicate(polybiusKey);
    
    cout << "The encrypted message is: ";
    cout << polybiusSquare(grid, polybiusKey, message, true) << endl;
    return;
}

void polybiusDecrypt() {
    string message = "";
    string polybiusKey = "";
    char grid[SIZE][SIZE];
    
    cin.ignore();
    
    // Gets and capitalizes message for ease and use in PolybiusSquare
    cout << "Enter a message: ";
    getline(cin, message);
    message = toUpperCase(message);
    
    // Makes sure message has only alphanumerics or spaces
    int nonAlnumOrSpaceCount = 0;
    for (int i = 0; i < message.size(); i++) {
        if (message[i] != ' ' && !isalnum(message[i]))
            nonAlnumOrSpaceCount++;
    }
    if (nonAlnumOrSpaceCount > 0) {
        cout << "Invalid message!" << endl;
        return;
    }
    
    cout << "What is your key: ";
    getline(cin, polybiusKey);
    
    // Makes sure the key is only alphanumeric, if not ends program
    for (int i = 0; i < polybiusKey.size(); i++) {
        if (!isalnum(polybiusKey[i])) {
            cout << "Invalid key!" << endl;
            return;
        }
    }
    
    // Capitalizes the key and removes duplicates to work in cipher
    polybiusKey = toUpperCase(polybiusKey);
    polybiusKey = removeDuplicate(polybiusKey);
    
    cout << "The decrypted message is: ";
    cout << polybiusSquare(grid, polybiusKey, message, false) << endl;
    return;
    
}


