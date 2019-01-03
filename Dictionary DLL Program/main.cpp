//Matthew Lynn-Goin
//107 776 584
//compiled and ran successfully 10/5/17
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include "DictEntry.h"
#include "dictionary.h"
#include <iostream>

using namespace std;

int main()
{
    int numForward, numBackward; //declare two ints
    cout << "=====DICTIONARY PROGRAM=====" << endl;
    cout << "============================" << endl;

    list<DictEntry>list1; //create a list of DictEntries
    dictionary dictionary1; //create a dictionary object
    DictEntry DictEntry1; //create a DictEntry object
    ifstream inputfile ("dictionary.txt"); //open dictionary.txt
    while (!inputfile.eof()){ //while not end of file
        DictEntry newEntry; //create a new dictentry object to read data into
        string line;
        getline(inputfile, line); //get the first line
        //cout << line << endl;
        newEntry.setWord(line); //fill that dictentry object with the data you just pullled from the file (string from first line)
        list1.push_back(newEntry); //put that object into the list (list of those objects)


    }
    list1.sort(); //sort the list based on the words

    cout << "Using forward search to check dictionary for matches in findwords.txt " << endl;
    cout << endl;
    ifstream inputfile2 ("findwords.txt"); //open findwords.txt
    int tracker =0;
    while (!inputfile2.eof()){ //while not end of file

        string line2;
        getline(inputfile2, line2); //get the first word in findwords.txt
        cout << "searching dictionary for: " << line2 << endl;
        numForward = dictionary1.searchForward(list1, line2); //set numforward equal to the return value of function (passed in the list and the search word)
        tracker ++;
        if (numForward == -1){ //if return value equal to -1
            //cout << "the word in position " << tracker << " was not found " << endl;
            cout << line2 << " was not found in the dictionary " << endl;
            cout << endl;
        }
        else{
            cout << line2 << " was found in the dictionary! " << endl;
            //cout << "Word in position " << tracker << " was found! " << endl;
            cout << "It took: " << numForward << " forward searches to find it! " << endl;
            cout << endl;
        }

    }
    inputfile2.close(); //close input file

    cout << "============================================================" << endl;
    cout << "Using backwards search to check dictionary for matches in findwords.txt " << endl;
    cout << endl;
    ifstream inputfile3 ("findwords.txt"); //open find words.txt again
    int tracker2 =0;
    while (!inputfile3.eof()){ //while not end of file

        string line3;
        getline(inputfile3, line3); //grab the first word
        cout << "searching directory for " << line3 << endl;
        numBackward = dictionary1.searchBackward(list1, line3); //set numbackward equal to return value of searchbackward function(with the list and search word passed in)
        tracker2 ++;
        if (numBackward == -1){ //if return value = -1
            cout << line3 << " was not found int the dictionary " << endl;
            //cout << "the word in position " << tracker2 << " was not found " << endl;
            cout << endl;
        }
        else{ //if return value something other than -1
            cout << line3 << " was found in the dictionary! " << endl;
            //cout << "Word in position " << tracker2 << " was found! " << endl;
            cout << "It took: " << numBackward << " backward searches to find it! " << endl;
            cout << endl;
        }

    }
    inputfile3.close(); //close the file
    cout << "===========================================================" << endl;
    cout << "Printed dictionary contents in reverse order to revsorted.txt " << endl;
    ofstream outputfile("revsorted.txt"); //create a ofstream with file revsorted.txt
    dictionary1.revPrintList(outputfile,list1); //pass the outputfile and the list into the function
    outputfile.close(); //close the ouput file
    cout << "===========================================================" << endl;

    //dictionary1.revPrintList(cout, list1);
    //seekg to reset the stream, but takes an argument
    //ifstream inputfile
    //inputfile. seekg(ios_base::beg)



    cout << "End of program" << endl;
    return 0;
}
