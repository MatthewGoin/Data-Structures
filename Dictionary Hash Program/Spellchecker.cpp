//Matthew Lynn-Goin
//10776584
//HW 9
//Dr. Augsutine
#include "Spellchecker.h"
#include <iostream>
#include "Node.h"
#include <list>
#include <cctype>
#include <string>

using namespace std;

Spellchecker::Spellchecker(){ //constructor; left empty

}
Spellchecker::~Spellchecker(){ //destructor; left empty

}



//load dictionary function
//returns and accepts nothing
//retrieves all words from file dict.txt and creates nodes, loads them into a hash function and then stores the nodes in
//an array of linked lists based on the return value of the hash function; essentially creating a dictionary
void Spellchecker::loadDictionary(){

    //the initial stage of this function (the removal of punctuation) was derived from the professors example in class
    string targetWord; //create a string
    int targetLocation; //create an int to hold the target location
    ifstream inputFile ("dict.txt"); //open dict.txt
    //This while loop was derived from an in class example porvided by Dr. Augustine
    while(!inputFile.eof()){ //while not end of file
            Node tempNode; //create a temp node
            inputFile >> targetWord; //read in a word from the file
            for (unsigned int i =0; i < targetWord.size(); i++){ //loop through the word that was just read in
                if(!isalnum (targetWord[i]) && (targetWord[i] != '\'')){ //if not alphanumeric then erase the character at position i
                    targetWord.erase(i--,1); //erase the character; and decrement the word size to make sure for loop is up to date
                }
            }
            for(unsigned int i =0; i < targetWord.size(); i++){
                targetWord[i] =  tolower(targetWord[i]);
            }
             dictionaryWords ++; //increment the variable to count how many dictionary words there are
            targetLocation = hashmathFunction(targetWord); //pass the rea in word into the hash function and set the return vale to a variable
            tempNode.setWord(targetWord); //set the string data member of the node equal to the read in string
            hashTable[targetLocation].push_back(tempNode); //push the node into the linked list at the array location, designated by the return value f the hash function

            //cout << dictionaryWords << endl;

    }
    inputFile.close(); //close the input file

}


//hash function
//accepts a string and returns an integer
int Spellchecker::hashmathFunction(string _Word){

    /*int sum =0;
    int hashNumber;
    for (unsigned int i = 0; i < _Word.size(); i++){
        int placer = _Word[i] * (10 * (_Word.size()-i));
        sum += placer;
    }
    hashNumber = sum % CAPACITY;
    return hashNumber;*/ //this was a prototype hash function; unused


    // The basis for this function was given in the homework details
    unsigned int dataType; //declare an unsigned int variable
    int hashNumber; //declare an int
    hash<string>hashStr; //declare hash variable
    dataType = hashStr(_Word); //pass that word into the funciton and set equal to variable
    hashNumber = dataType % CAPACITY; //take that variable and mod to fit into the array of linked lists and set that equal to hash number variable
    return hashNumber; //return the number that indicates where the node will be stored in the array




}


//The next two functions are essentially the same, just  used with different .txt files
//returns nothing and accepts nothing
//displays the results to the screen
void Spellchecker::checkFunction(){

        ifstream inputFile("check.txt"); //open check.txt
        string wordCheck; //create a string

        //create several variables to hold result nformation and to display at the end of the function

        int wordsinFile = 0;
        int hashLocation =0;
        int misspelled = 0;
        int foundWord =0;
        int notinDict =0;

        //This while loop was derived from an in class example provided by Dr. Augustine
        while(inputFile.good()){ //while input file is good
            Node tempNode; //create a temp node
            inputFile >> wordCheck; //read in a word
            for(unsigned int i =0; i < wordCheck.size(); i++){ //loop through the word and erase all punctuation
                if(!isalnum(wordCheck[i]) && (wordCheck[i] != '\'')){
                    wordCheck.erase(i--,1);

                }
            }
            for(unsigned int i =0; i < wordCheck.size(); i++){ //loop through the word and convert all characters to lowercase
                wordCheck[i] =  tolower(wordCheck[i]);
            }
            wordsinFile ++; //increment variable

            hashLocation = hashmathFunction(wordCheck); //pass word into the hash math function and set the return value equal to variable
            tempNode.setWord(wordCheck); //set the temp nodes data member with the word
            if(hashTable[hashLocation].empty()){ //if there is nothing in the array location
                notinDict ++; //indicate not in dictionary, because nothing matches any target in the original dictionary
            }
            if(!hashTable[hashLocation].empty()){ //if the location is not empty

                bool found = false; // set found equal to false
                for(list<Node>::iterator it = hashTable[hashLocation].begin(); it != hashTable[hashLocation].end(); ++it){ //declare an iterator to traverse the linked list at the array location
                    if(it->getWord() == tempNode.getWord()){ //if the word the the iterator is pointing to is equal to the word read in from the file
                        foundWord ++; //increment variable
                        found = true; //set found equal to true and break from the loop
                        break;
                    }
                }
                if(found == false){ //if nothing was found in the LL that matched, it indicates a misspelled word
                misspelled ++; //increment variable
                }
            }
        }
        //display the results
        cout << dictionaryWords << " dictionary words. " << endl;
        cout << wordsinFile << " words in file. " << endl;
        cout << foundWord << " words of the file found in the dictionary. " << endl;
        cout << misspelled << " misspelled words. " << endl;
        cout << notinDict << " words not in the dictionary. " << endl;

        inputFile.close(); //close the input file





}


//This function is essentially the exact same as the one above, except Potter.txt is the file we are examining
void Spellchecker::checkFunction2(){

    ifstream inputFile("Potter.txt"); //open potter.txt
        string wordCheck;
        int wordsinFile = 0;
        int hashLocation =0;
        int misspelled = 0;
        int foundWord =0;
        int notinDict =0;
        while(inputFile.good()){
            Node tempNode;
            inputFile >> wordCheck;
            for(unsigned int i =0; i < wordCheck.size(); i++){
                if(!isalnum(wordCheck[i]) && (wordCheck[i] != '\'')){
                    wordCheck.erase(i--,1);
                }
            }
            for(unsigned int i =0; i < wordCheck.size(); i++){
                wordCheck[i] =  tolower(wordCheck[i]);
            }
            wordsinFile ++;

            hashLocation = hashmathFunction(wordCheck);
            tempNode.setWord(wordCheck);
            if(hashTable[hashLocation].empty()){
                notinDict ++;
            }
            if(!hashTable[hashLocation].empty()){
                bool found = false;
                for(list<Node>::iterator it = hashTable[hashLocation].begin(); it != hashTable[hashLocation].end(); ++it){
                    if(it->getWord() == tempNode.getWord()){
                        foundWord ++;
                        found = true;
                        break;
                    }
                }
                if(found == false){
                misspelled ++;
                }
            }
        }
        cout << dictionaryWords << " dictionary words. " << endl;
        cout << wordsinFile << " words in file. " << endl;
        cout << foundWord << " words of the file found in the dictionary. " << endl;
        cout << misspelled << " misspelled words. " << endl;
        cout << notinDict << " words not in the dictionary. " << endl;

        inputFile.close();


}


//This function is the same as the two above excepts its accepts a getline and opens the file the user prompts for
void Spellchecker::checkFunction3(string filename){

    ifstream inputFile(filename);
        string wordCheck;
        int wordsinFile = 0;
        int hashLocation =0;
        int misspelled = 0;
        int foundWord =0;
        int notinDict =0;
        while(inputFile.good()){
            Node tempNode;
            inputFile >> wordCheck;
            for(unsigned int i =0; i < wordCheck.size(); i++){
                if(!isalnum(wordCheck[i]) && (wordCheck[i] != '\'')){
                    wordCheck.erase(i--,1);
                }
            }
            for(unsigned int i =0; i < wordCheck.size(); i++){
                wordCheck[i] =  tolower(wordCheck[i]);
            }
            wordsinFile ++;

            hashLocation = hashmathFunction(wordCheck);
            tempNode.setWord(wordCheck);

            if(hashTable[hashLocation].empty()){
                notinDict ++;
            }
            if(!hashTable[hashLocation].empty()){

                bool found = false;
                for(list<Node>::iterator it = hashTable[hashLocation].begin(); it != hashTable[hashLocation].end(); ++it){
                    if(it->getWord() == tempNode.getWord()){
                        foundWord ++;
                        found = true;
                        break;
                    }
                }
                if(found == false){
                misspelled ++;
                }
            }
        }
        cout << dictionaryWords << " dictionary words. " << endl;
        cout << wordsinFile << " words in file. " << endl;
        cout << foundWord << " words of the file found in the dictionary. " << endl;
        cout << misspelled << " misspelled words. " << endl;
        cout << notinDict << " words not in the dictionary. " << endl;

        inputFile.close();

}
