//Matthew Lynn-Goin
//compiled and ran successfuly on codeblocks and cse grid
//hw5
#include "LinkedList.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;


LinkedList::LinkedList(){ //constructor creating new nodes and setting everything to nullptr//

    headPtr = new Node;
    tailPtr = new Node;
    currentPtr = new Node;
    previousPtr = new Node;
    headPtr ->next = nullptr;
    tailPtr ->next = nullptr;
    currentPtr ->next = nullptr;
    previousPtr ->next = nullptr;


}
LinkedList::~LinkedList(){ //destructor


}

bool LinkedList::insertAtFront(char& character){ //function to create a node, fill with info, and add it to front of linked list



    if(tracker == 0){ //if nothing else has been created

        Node *newNode = new Node; //create a new node
        newNode ->data = character; //fill the new nodes data with the character being passed in.
        headPtr = newNode; //have head pointer equal this new node
        newNode ->next = nullptr; //have the new nodes next pointer = nullpointer to signify the ned of the list
        //currentPtr ->next = newNode;
        //previousPtr ->next = newNode;
        tailPtr ->next = newNode; //have the tail pointer equal this new node
        tracker ++; //increment tracker to signify something has been added


    }
    if(tracker >= 1 ){ //if something already exists in the list
        Node *newNode = new Node;//create a new node
        newNode ->data = character; //fill the node with data
        newNode ->next = headPtr; //have the new node point to pre existiing first item in list
        headPtr = newNode; //have headptr point to this new node making it the new fist item in the array
        tracker ++; //increment tracker t signify somthing has been added to list
            }
    return true;

}
bool LinkedList::inserAtBack(char& character){ //function to insert at the end of the list

    if(tracker == 0){ //if nothing is in the list
        //char check=0;
        /*Node *newNode = new Node;
        newNode ->data = character;
        headPtr ->next = newNode;
        tailPtr ->next = newNode;
        newNode ->next = nullptr;*/

        Node *newNode = new Node; //create a new node
        newNode->data = character; //fill it with data
        headPtr = newNode; //have the head pointer equal to this new node
        tailPtr = newNode; //have the tail pointer equal to this new node
        newNode->next = nullptr; //set the new node's next pointer equal to nullpointer to signify end of linked list

        tracker ++; //increment tracker
        //check = newNode->data; //check to see if added correctly
        //cout << check << endl;
        //cout << "hello" << endl;

            }
    else { //if somehting is already in the list
        //char check =0;
        Node *newNode = new Node; //create a new node
        newNode ->data = character; //fill the node with data
        tailPtr ->next = newNode; //connect the previous node with this new node
        tailPtr = tailPtr ->next; //have the tail pointer equal the last item
        newNode ->next = nullptr; //have this new nodes next pointer equal to nullptr
        tracker++; //incrememnt tracker
        //check = newNode->data; //check to see if added succesfully
        //cout << check << endl;
        //cout << "World " << endl;
    }
    //tracker = check;
   // cout << tracker << endl;
    return true;
}

bool LinkedList::insertBeforePosition(int index, char& character){ //function to insert before a specified location

    currentPtr = headPtr; //start from the beginning
    previousPtr = headPtr;
    if(index > 0){
        for (int i =0; i < index; i++){
            currentPtr = currentPtr ->next; //incrmeent until current pointer equals specified location
        }
        for (int i =0; i < index - 1; i++){
            previousPtr = previousPtr ->next; //have previous pinter point to location before current location
        }
    }else if (index == 0){
        insertAtFront(character);
        return true;
    }

    Node *newNode = new Node; //create a ew node
    newNode ->data=character; //fill it with data
    newNode ->next = currentPtr; //connect the end of new node into the list //newNode ->next = currentPtr ->next
    previousPtr ->next = newNode; //connect the beggining of new node into the list//previousPtr ->next = newNode
    tracker ++; //increment tracker

    return true;


}

bool LinkedList::deleteAtFront(){ //function to delete the first position

    currentPtr = headPtr; //set current ptr equal to head ptr
    headPtr = headPtr ->next; //have had pointer point to pre existing second item in list (now the first)

    currentPtr -> next = nullptr; //set the first items pointer to null
    delete currentPtr; //free up the memory
    currentPtr = nullptr; //set current pointer bck to nullptr
    tracker --; //decrement tracker

    return true;
}

bool LinkedList::deleteBeforePosition(int index){ //function to delete before a specified position


    currentPtr = headPtr;//start at the beginning f the list //Node *currentPtr ->next was at the beggining
    previousPtr = headPtr;
    if(index > 1){
        for (int i =0; i < index -1; i++){
            currentPtr = currentPtr ->next; //traverse list and set current pointer equal to posiiotn before specified
        }
        for (int i =0; i < index - 2; i++){
            previousPtr = previousPtr ->next; //traverse list and set previous pointer equal to two postions before specified
        }
    } else if (index == 1){
        deleteAtFront();
        return true;
    }


    previousPtr ->next = currentPtr ->next;//take link to node and break it and connect it to the one after(deleting it) // previousPtr ->next = currentPtr ->next

    currentPtr -> next = nullptr; //free up the memory from deleted node
    delete currentPtr;
    currentPtr = nullptr;
    tracker --;//decrement tracker

    return true;
}

bool LinkedList::deleteAtBack(){ //delete the last element

    currentPtr  = tailPtr; //start at the back //Node *currentPtr ->next was at the beggining
    previousPtr = headPtr; //start at he beginning
    /*for (int i =0; i < tracker; i++){
        currentPtr = currentPtr ->next;
    }*/
    for (int i =0; i < tracker - 1; i++){
        previousPtr = previousPtr ->next; //traverse until one spot before the end
    }
    previousPtr ->next= nullptr;//destroy link to last//currentPtr->next;
    tracker --; //decrement tracker



    return true;
}

char Node::getData(){ //funciton to get the data at a specific node

    return data;

}

void LinkedList::printList(){ //funtion to print the ocntents of the linked list

    char listdata;
    currentPtr = headPtr; //start at he beginning
    for(int i =0; i < tracker; i++){

        listdata = currentPtr ->data; //
        cout << listdata << endl; //display  the contents

        currentPtr = currentPtr ->next; //go to the next
    }

}

void LinkedList::printNode(int node){



}

bool LinkedList::getIntsfromfile(ifstream& inputfile){ //function to load file contents into linked list objects



    if (inputfile.fail()){ //if file fails to load
        cout << "Input file opening failed " << endl;
        return false;
    }
    char character;
    string tempString;
    stringstream ss; //create stingstream object
    getline(inputfile, tempString);
    ss << tempString;
        while (ss >> character){ //got this idea from classmate cody gardner
            inserAtBack(character);//insert character into the linked list
        }

        return true;

}

LinkedList operator +(LinkedList &lhs, LinkedList &rhs){

    LinkedList tempList;

    char listdata;
    lhs.currentPtr = lhs.headPtr; //start at he beginning
    for(int i =0; i < lhs.tracker; i++){ //for loop until end of lhs linked list

        listdata = lhs.currentPtr ->data; //
        tempList.inserAtBack(listdata);
        //cout << listdata << endl; //display  the contents
       lhs.currentPtr = lhs.currentPtr ->next; //go to the next
    }
    char listdata2;
    rhs.currentPtr = rhs.headPtr; //start at he beginning
    for(int i =0; i < rhs.tracker; i++){

        listdata2 = rhs.currentPtr ->data; //
        tempList.inserAtBack(listdata2); //insert the contents of the other linked list in templist
        //cout << listdata << endl; //display  the contents

        rhs.currentPtr = rhs.currentPtr ->next; //go to the next
    }

    return tempList; //return temp list

}

LinkedList operator -(LinkedList &lhs, LinkedList &rhs){ //overloaded subtraction operator

        LinkedList tempList; //create templist
        char listdata2;
        char listdata3;
        lhs.currentPtr = lhs.headPtr; //start from the beginning

        for (int i =0; i < lhs.tracker; i++){ //loop until end of lhs
                listdata2 = lhs.currentPtr->data; //set data equal to char variable
                rhs.currentPtr =rhs.headPtr; //start from beginning
                int counter =0; //set counter =0
            for (int i =0; i < rhs.tracker; i++){ //loop until ed of rhs
                    //listdata2 = lhs.currentPtr->data;
                    listdata3 = rhs.currentPtr->data; //set data from rhs equal to char variable
                    if( listdata3 != listdata2){ //if rhs data is not equal to lhs data
                            counter ++; //increment counter
                    }
                    if(counter == rhs.tracker){ //if counter = size of rhs (signalling that there were no matches)

                            //cout << listdata2 << endl;
                        tempList.inserAtBack(listdata2); //add data from lhs to temp list
                        goto DO; //then break out of loop

                    }
                     rhs.currentPtr = rhs.currentPtr->next; //get the next nodes data
                }


            DO: lhs.currentPtr = lhs.currentPtr->next; //get the next nodes data
        }

        return tempList; //return the temp list with the nodes entered.

}





