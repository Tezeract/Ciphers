/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Joel Iacoban
 * joeliaco
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * Utility functions for ease of use in Project 3
 */

#include "utility.h"
#include <iostream>
#include <string>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

// Converts all alphabetic characters in string to uppercase
string toUpperCase(string original) {
    
    // Runs through and checks each string index if lowercase alpha
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original.at(i)) && !isupper(original.at(i))) {
            original.at(i) = toupper(original.at(i));
        }
    }
    return original;
}

// Removes non alphabetic characters and copies into new string
string removeNonAlphas(string original) {
    
    string newString = "";
    
    // Runs through original string and checks if alphabetic
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original.at(i))) {
            newString += original.at(i);
        }
    }
    
    return newString;
}

// Converts a char character from 0 to 9 to its int counterpart
int charToInt(char original) {
    
    // The ASCII value of '0' is 48
    // So any char number from '0' to '9' minus '0' gives its int
    int charNumber = original - '0';
    
    return charNumber;
}

// Returns only the first instances of characters in a string
string removeDuplicate(string original) {
    
    for (int i = 0; i < original.size(); i++) {
        int j = i + 1;
        
        // Iterates through original for the index of original for each char
        while (j < original.size()) {
            
            // for current index of i until same size
            if (original.at(i) == original.at(j)) {
                original.erase(j, 1);
            }
            else {
                j++;
            }
        }
    }
    
    return original;
}


////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
