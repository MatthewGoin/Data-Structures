//Matthew Lynn-Goin
//compiled and ran successfuly on codeblocks and cse grid
//hw5
#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include "LinkedList.h"
#include <limits>
using namespace std;

using namespace std;

int main()
{
    int accumulator =0;
    int counter = 0, position, position2;
    char character, character2;
    cout << "===========================================" << endl;
    cout << "==========Linked List Program==============" << endl;
    cout << "===========================================" << endl;
    LinkedList list1, list2, list3, list4, list5, list6; ////declare linked list objects
    cout << "How many items would you like in your list? " << endl;
    cin >> counter;
    //cin.clear();
    cin.ignore();
    cout << endl;
    cout << endl;

    for (int i =0; i < counter; i ++){

        cout << "please enter a lowercase letter to add to your list: " << endl;
        cin >> character;
        //cin.clear();
        list1.inserAtBack(character); //add the characters to the list
        //cin.ignore('\n');
    }
    cout << "===========================================" << endl;
    list1.printList(); //print the contents
    cout << "===========================================" << endl;
    cout << "now enter a lowercase letter to add to the beginning of your list " << endl;
    cin >> character2;
    list1.insertAtFront(character2); //insert to the front of the linked list
    cout << "here is the new updated list: " << endl;
    list1.printList(); //print the contents
    cout << "===========================================" << endl;
    cout << "Now pick a position in the list that you would like to add a character behind (note position starts at 1) " << endl;
    cin >> position;
    cout << "Now pick a lowercase letter you like to add in that position " << endl;
    cin >> character;
    list1.insertBeforePosition(position -1, character); //call th funtion to insert a node bfore a specified position
    cout << "Here is the new updated list " << endl;
    list1.printList(); //print the updated list
    cout << "===========================================" << endl;
    cout << "Now we are going to delete the first entry in the list: " << endl;
    list1.deleteAtFront(); //delete first node
    list1.printList(); //print the updated list
    cout << "===========================================" << endl;
    cout << "Now we are going to delete the last position in the list: " << endl;
    list1.deleteAtBack(); //delete last position
    list1.printList(); //print updated list
    cout << "===========================================" << endl;
    cout << "now we will delete a character before a desired position (note: please pick a position greater than one)" << endl;
    cout << "please enter the the position: " << endl;
    cin >> position2;
    list1.deleteBeforePosition(position2 - 1); //call function
    cout << "Here is the updated list: " << endl;
    list1.printList(); //print updated list
    cout << "===========================================" << endl;
    cout << "===========================================" << endl;
    cout << "Now we will create two linked lists from an input file: " << endl;
    ifstream inputfile ("input.txt"); //load in the input file
    if(list2.getIntsfromfile(inputfile)){ //Read the first line of integers into the first array
       cout << "input file loaded successfully: Here is list2 " << endl; //if all integers, print out a message
        list2.printList();
        accumulator ++;
        } //print the values in the array
        else{
            cout << "file failed to load " << endl;
        }
    cout << "===========================================" << endl;
     if(list3.getIntsfromfile(inputfile)){ //Read the first line of integers into the first array
       cout << "input file loaded successfully: Here is list3 " << endl; //if all integers, print out a message
        list3.printList();
        }//print the values in the array
    cout << "============================================" << endl;
    cout << "Now we will combine the two newly created lists: " << endl;
    list4 = list2 + list3; //combine list2 and list 3
    list4.printList(); //print the new list
    cout << "============================================" << endl;
    cout << "Now we will subtract List3 from List2: " << endl;
    list5 = list2 - list3; //subtract list3 from list 2
    list5.printList(); //print the contents
    cout << "============================================" << endl;
    cout << "PLEASE SCROLL UP TO SEE ALL OF THE FUNCTIONALITY " << endl;
    cout << "============================================" << endl;

    cout << "=======End of Linked List Program===========" << endl;
    cout << "============================================" << endl;
    return 0;
}
