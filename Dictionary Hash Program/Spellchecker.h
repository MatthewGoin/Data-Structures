//Matthew Lynn-Goin
//10776584
//HW 9
//Dr. Augsutine
#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
#include "Node.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class Spellchecker{ //declare spellchecker class

private:
    int dictionaryWords; //create an int
    static const int CAPACITY = 1373; //declare the size of the array of Linked lists


public:
    list<Node> hashTable[CAPACITY]; //create an array of linked lists
    Spellchecker(); //constructor
    ~Spellchecker(); //destructor
    void loadDictionary(); //load dictionary function to create the program dictionary; returns nothing;accepts nothing
    int hashmathFunction(string _word); //hash function to create an int value to tell the program where to put the node in the array; accepts a string;returns an int
    void checkFunction();// initial check function to check against the program dictionary; accepts nothing; returns nothing;
    void checkFunction2(); //second check function to check potter.txt against the program dictionary; accepts nothing; returns nothing;
    void checkFunction3(string filename); // third check function to check whatever file the user wishes against the program dictionary; accepts a string for filename; returns nothing

};




























#endif // SPELLCHECKER_H
