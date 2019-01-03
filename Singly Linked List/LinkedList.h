 #ifndef BAG_
#define BAG_
//Matthew Lynn-Goin
//compiled and ran successfuly on codeblocks and cse grid
//hw5

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;


struct Node{

    char data;
    Node* next;
    char getData();
};

class LinkedList{
private:
    Node *headPtr; //declare a pointer to a node
    Node *currentPtr; //declare a pointer to a node
    Node *previousPtr; //declare a pointer to a node
    Node *tailPtr; //declare a pointer to a node
    int tracker =0;
    int accumulator =0;

public:

    LinkedList(); // constructor
    ~LinkedList(); // destructor

    bool insertAtFront(char& character); //function to insert a node at the front of the list
    bool insertBeforePosition(int index, char& character); // function to insert a node before a specified position
    bool inserAtBack(char& character); //function to insert at the back of the list
    bool deleteAtFront();//function to delete the first node
    bool deleteBeforePosition(int index);// function to delete before a specified position
    bool deleteAtBack(); // function to delete the last node
    void printNode(int node); //function to print a speific node
    void printList(); //function to pirnt the contents of the linked list
    bool getIntsfromfile(ifstream& inputfile); //function to load data from text file into linked list
    friend LinkedList operator +(LinkedList &lhs, LinkedList &rhs); //overloaded binary operator, combining two lists
    friend LinkedList operator -(LinkedList &lhs, LinkedList &rhs); //overloaded subtraction operator


};
#endif // BAG_
