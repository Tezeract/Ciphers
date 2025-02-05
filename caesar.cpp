/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Joel Iacoban
 * joeliaco
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * Encryption or decryption of a string using the Caesar cipher
 */

#include "caesar.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************
const int NUM_LETTERS_IN_ALPHABET = 26;

// Shifts a character right or left by a value, wrapping along the alphabet
char shiftAlphaCharacter(char c, int n) {
    string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowerAlphabet = "abcdefghijklmnopqrstuvwxyz";
    
    // Allows shifts beyond the alphabets size
    // Corresponds to the uppercase characters
    if (isupper(c)) {
        for (int i = 0; i < upperAlphabet.size(); i++) {
            if (c == upperAlphabet.at(i)) {
               
                // The ASCII value of Z (90) is the upper limit
                while ((c + n) > 'Z') {
                    
                    // Subtracts by 26 until shift is below/= the ASCII of 'Z'
                    n -= NUM_LETTERS_IN_ALPHABET;
                }
                
                // The ASCII value of A (65) is the lower limit
                while ((c + n) < 'A') {
                    
                    // Adds 26 to shift until it is above/= ASCII of 'A'
                    n += NUM_LETTERS_IN_ALPHABET;
                }
                c = c + n;
                
                return c;
            }
        }
    }
    
    // Corresponds to the lowercase characters
    if (islower(c)) {
        for (int i = 0; i < lowerAlphabet.size(); i++) {
            if (c == lowerAlphabet.at(i)) {
                
                
                // The ASCII value of z (122) is the upper limit
                while ((c + n) > 'z') {
                    
                    // Subtracts by 26 until shift is below/= the ASCII of 'z'
                    n -= NUM_LETTERS_IN_ALPHABET;
                }
                
                // The ASCII value of a (97) is the lower limit
                while ((c + n) < 'a') {
                    
                    // Adds 26 to shift until it is above/= ASCII of 'a'
                    n += NUM_LETTERS_IN_ALPHABET;
                }
                c = c + n;
                
                return c;
            }
        }
    }
    // Should never reach
    return c;
}

string caesarCipher(string original, int key, bool encrypt) {
    
    // Reverses shift if decryption
    if (!encrypt) {
        key *= -1;
    }
    
    // Every alpha in the original string is shifted
    for (int i = 0; i < original.size(); i++) {
        original.at(i) = shiftAlphaCharacter(original.at(i), key);
    }

    return original;

}
