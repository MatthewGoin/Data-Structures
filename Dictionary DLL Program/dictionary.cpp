//Matthew Lynn-Goin
//107 776 584
//compiled and ran successfully 10/5/17#include <string>
#include <list>
#include <iterator>
#include <iostream>
#include <fstream>
#include "DictEntry.h"
#include "dictionary.h"

using namespace std;


dictionary::dictionary(){  //constructor left empty

}

//searchforward function:searches the sorted list from the first posiotn to the last
//if nothing wa found returns -1, if something was found it returns an integer equal to the number of searches it took to find

int dictionary::searchForward(list<DictEntry> &wordList,wordType &findString){ //accepts as argument a list, and a target word to search list for
                                                                               //returns an int
        int counter = 0; //set the counter
        int numsearches =0; //set the numsearches variable
        for (list<DictEntry>::iterator it = wordList.begin(); it != wordList.end(); ++it){ //create iterators and have it point beginning of list and loop until end of list
            numsearches ++; //incrementing the number of searches
            if (it->getWord() == findString){ //if the word that it is pointing to is equal to the passed in search word
                counter ++; //increment the counter
                goto endfunction; //break out of the loop
            }
        }

endfunction: if (counter == 0){ //if loop end and counter has not been incremented signaling nothing was found
            numsearches = -1;
        }
        return numsearches; //return the number of searches it took
 }


 //search backwards funciton, creates an iterator that starts and the back and works it way to front. returns -1 if
 //nothing was found, otherwise returns the number of searches it took to find it.

 int dictionary::searchBackward(list<DictEntry> &wordList,wordType &findString){ //accepts as argument a list and a target word to search that list for
                                                                                 //returns an int
        int counter =0;
        int numsearches =0;
        for (list<DictEntry>::reverse_iterator it = wordList.rbegin(); it != wordList.rend(); ++it){ //create iterator and have it point to back and loop until beginning of list
            numsearches ++; //incrmeent number of searches
            if (it->getWord() == findString){ //if the word it is pointing to is equal to the target word
                counter ++; //incrememnt counter
                goto endfunction; //break out of loop
            }

        }
endfunction:if (counter == 0){ //if counter is equal to 0 signalling that nothing was found
            numsearches = -1;
        }
        return numsearches; //return the number of searces it took
 }


//this function accepts an osteram object and list
void dictionary::revPrintList(ostream& output, list<DictEntry> &wordList){



        //ofstream outputfile("revsorted.txt");
        for (list<DictEntry>::reverse_iterator it = wordList.rbegin(); it != wordList.rend(); ++it){ //create an iterator and have it point to end of list and loop until beginning
            output << it->getWord() << " "; // write the word that it is pointing to the file with a space after
        }
        //output.close(); //outputfile.close();


}
