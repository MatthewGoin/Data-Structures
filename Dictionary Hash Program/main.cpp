//Matthew Lynn-Goin
//10776584
//HW 9
//Dr. Augsutine
#include <iostream>
#include "Spellchecker.h"
#include "Node.h"
#include <list>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    Spellchecker Spellchecker1; //declare a spellchecker object

    char choice; //create a char fr the choice
    cout << "================SPELL CHECKER PROGRAM============" << endl;
    cout << "=================================================" << endl;
    Spellchecker1.loadDictionary(); //call the load dictionary function
    cout << "We have loaded the program dictionary " << endl;
    cout << "Now we will load check.txt to see a demonstration: " << endl;
    cout << endl;
    Spellchecker1.checkFunction(); //call the first check function
    cout << "=================================================" << endl;
    cout << "Now we will load Potter.txt and see the results: " << endl;
    cout << endl;
    Spellchecker1.checkFunction2(); //call the second check function
    cout << "=================================================" << endl;
    jump1:
    cout << "please enter an input file to check with our dictionary: " << endl;
    string filename = ""; //create a string for the filename
    getline(cin, filename); //use a getline to read in the file the user selects
    Spellchecker1.checkFunction3(filename); //call the thrid chek function; apssing in the filename
    cout << "Would you like to check another file? (y/n) " << endl; //ask the user if they wish to select another file
    cin >> choice; //read in the choice
    cin.ignore(); //ignore the next character so getline can be properly used in the loop again
    if(choice == 'y'){ //if they choose yes
        goto jump1;
    }
    else{ // else end the program
        cout << "============END OF PROGRAM===================" << endl;
        cout << "=============================================" << endl;
    }

    return 0;
}
