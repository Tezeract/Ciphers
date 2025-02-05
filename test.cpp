/*
 * test.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Joel Iacoban
 * joeliaco
 *
 * EECS 183: Project 3
 * Fall 2024
 *
 * Tests function implementations for all ciphers
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

// Declaring all test functions for use below
void test_toUpperCase();
void test_removeNonAlphas();
void test_removeDuplicate();
void test_charToInt();
void test_shiftAlphaCharacter();
void test_caesarCipher();
void test_vigenereCipher();
void test_fillGrid();
void test_mixKey();
void test_findInGrid();
void test_polybiusSquare();

// Tests necessary functions using various cases
void startTests() {
    cout << "Starting test cases!" << endl << endl;
    
    test_toUpperCase();
    test_removeNonAlphas();
    test_charToInt();
    test_removeDuplicate();
    test_shiftAlphaCharacter();
    test_caesarCipher();
    test_vigenereCipher();
    test_mixKey();
    test_fillGrid();
    test_findInGrid();
    test_polybiusSquare();
}

void test_toUpperCase() {
    cout << "Testing toUpperCase()" << endl;
    cout << toUpperCase("orororRRRwwwWn34") << endl << endl;
    cout << toUpperCase("hey, my name is Joel!") << endl << endl;
}

void test_removeNonAlphas() {
    cout << "Testing removeNonAlphas()" << endl;
    cout << removeNonAlphas("44 Heyyy 56! 00 bro") << endl << endl;
    cout << removeNonAlphas("") << endl << endl;
    cout << removeNonAlphas("1") << endl << endl;
}

void test_charToInt() {
    cout << "Testing charToInt()" << endl;
    cout << charToInt('4') << endl << endl;
    cout << charToInt('1') << endl << endl;
    cout << charToInt('0') << endl << endl; 
}

void test_removeDuplicate() {
    cout << "Testing removeDuplicate()" << endl;
    cout << removeDuplicate("AAAABBBCCC444342424RRRRDDDDBBB") << endl << endl;
}

void test_shiftAlphaCharacter() {
    cout << "Testing shiftAlphaCharacter()" << endl;
    cout << shiftAlphaCharacter('d', 3) << endl;
    cout << shiftAlphaCharacter('D', -29) << endl;
    cout << shiftAlphaCharacter('r', 3) << endl;
    cout << shiftAlphaCharacter('d', 26) << endl;
    cout << shiftAlphaCharacter('D', 0) << endl;
    cout << shiftAlphaCharacter('D', 1000001) << endl;
    cout << shiftAlphaCharacter('a', 0) << endl;
    cout << shiftAlphaCharacter('b', 2) << endl;
    cout << shiftAlphaCharacter('X', 5) << endl;
    cout << shiftAlphaCharacter('Z', -4) << endl << endl;
}

void test_caesarCipher() {
    cout << "Testing caesarCipher()" << endl;
    cout << caesarCipher("Visss sio hin wiif", 20, false) << endl;
    cout << caesarCipher("Boyyy you not cool", 20, true) << endl;
    cout << caesarCipher("What up? How are you? At 11, we fricken ball", 10, true) << endl;
}

void test_vigenereCipher(){
    cout << "Testing vigenereCipher()" << endl;
    cout << vigenereCipher("Hey guy!", "joel", true) << endl;
    cout << vigenereCipher("yooo ooo....", "joel", true) << endl;
    cout << vigenereCipher("a", "joel", true) << endl;
    cout << vigenereCipher("Hey, my name is Joel! Big fan, great to meet you!", " Boooo!!!!!", true) << endl;
    cout << vigenereCipher("Hey, my name is Joel! Big fan, great to meet you!", " Boooo!!!!!", true) << endl;
    cout << vigenereCipher("WelcometoNothingville", "Squirelllllll!", true) << endl;
}
    
void test_mixKey() {
    cout << "Testing mixKey()" << endl;
    cout << mixKey("HEYBRO") << endl;
    cout << mixKey("MONDAY4TH") << endl << endl;
}

void test_fillGrid() {
    cout << "Testing fillGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    printGrid(grid);
    cout << endl << endl;
    string gridValues = "MONDAY4THBCEFGIJKLPQRSUVWXZ012356789";
    fillGrid(grid, gridValues);
    printGrid(grid);
    cout << endl << endl;
}
    
void test_findInGrid() {
    cout << "Testing findInGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << findInGrid('A', grid) << endl;
    cout << findInGrid('0', grid) << endl << endl;
}

void test_polybiusSquare() {
    cout << "Testing polybiusSquare()" << endl;
    char grid[SIZE][SIZE];
    cout << polybiusSquare(grid, "MONDAY4TH", "HEY MY NAME IS JOEL", true) << endl;
    cout << polybiusSquare(grid, "MONDAY4TH", "121505 0005 02040015 2233 23011525", false) << endl;
}


    
    
