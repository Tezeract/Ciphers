/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Joel Iacoban
 * joeliaco
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * Encryption or decryption using the Polybius ciper
 */


#include "polybius.h"
#include <string>
using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string mixKey(string key) {
    
    // Copies into empty string, then adds ALNUM into it
    string result = key;
    result += ALNUM;
   
    // Clears the new mixed string of any duplicates
    result = removeDuplicate(result);
    
    return result;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    
    // Seperate iterator for the string
    int x = 0;
    int row = SIZE;
    int col = SIZE;
    for (int i = 0; i < row ; i++) {
        for (int j = 0; j < col; j++, x++) {
            grid[i][j] = content[x];
        }
    }
    return;
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    
    // Iterates through the grid for the value
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == c) {
            
            // Converts the coordinates to string and adds them together
            return to_string(row) + to_string(col);
            }
        }
    }
    
    // If nothing found
    return "";
}
  


string polybiusSquare(char grid[SIZE][SIZE], string key, 
                      string original, bool encrypt) {
   
    string result = "";
    string coordinate = "";
    
    // Copies mixed string with key into mixedString and fills grid with it
    string mixedString = mixKey(key);
    fillGrid(grid, mixedString);
   
    if (encrypt) {
        for (int i = 0; i < original.size(); i++) {
            
            // Adds non digits/alphas to keep them in the string
            // EX: Adds space where there is a space in original for accuracy
            if (!isalpha(original[i]) && !isdigit(original[i])) {
                result += original[i];
            }
            
            // Copies coordinates into resultant string
            else {
                coordinate = findInGrid(original[i], grid);
                result += coordinate;
            }
        }
    }
    // Decryption
    else {
        for (int i = 0; i < original.length(); i += 2) {
            
            // Skips any non-alphanumeric characters and adds them to result
            while (i < original.length() && !isalpha(original[i])
                   && !isdigit(original[i])) {
                result += original[i];
                i++;
            }
            
            // Converts the coordinates found in original to ints
            int row = charToInt(original[i]);
            int col = charToInt(original[i + 1]);
                
            // Directly accesses grid and addss the character to result
            result += grid[row][col];
            }
        }
    return result;
}
