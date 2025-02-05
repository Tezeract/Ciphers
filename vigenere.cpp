/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Joel Iacoban
 * joeliaco
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * Encryption and decryption using the Vigenere cipher
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string vigenereCipher(string original, string keyword, bool encrypt) {
    keyword = toUpperCase(keyword);
    keyword = removeNonAlphas(keyword);
    
    string originalKeyword = keyword;
    int originalAlphaCount = 0;

    // Count the number of alphabetic characters in the original string
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original[i])) {
            originalAlphaCount++;
        }
    }

    // Repeat keyword enough times to match the number of letters in original
    while (originalKeyword.length() < originalAlphaCount) {
        originalKeyword += keyword;
    }
    
    // Trims repeated keyword string to match number of letters in original
    originalKeyword = originalKeyword.substr(0, originalAlphaCount); // Trim to match

    // Start with the original string
    string result = original;
    
    // For iterating along the keyword
    int keywordCount = 0;
    
    // Encrypts or decrypts, shifting each character one by one
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original[i])) {
            int shift = originalKeyword[keywordCount] - 'A';
            
            // Negates the shift if decryption, meaning it shifts backwards
            if (!encrypt) {
                shift *= -1;
            }
            result[i] = shiftAlphaCharacter(original[i], shift);
            
            // Iterates keyword if and only if original was a letter
            // Allows each letter of keyword to sequentially shift original
            keywordCount++;
        }
    }

    return result;
}


    
