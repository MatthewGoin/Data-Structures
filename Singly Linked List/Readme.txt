*******************************************************
*  Name      :  Matthew Lynn-Goin
*  Student ID:  107 776 584               
*  Class     :  CSC 2421           
*  HW#       :  5              
*  Due Date  :  Sep. 28, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program "LinkedList" creates nodes with data and a next pointer, fills the data with
a character and points the next pointer to the next node that in turn has data stored in it,
thus creating a "liinked list". This linked list has a head pointer(something that points to the 
firstitem in the list, a tial pointer, a current pointer and a previous pointer). The main driver demeonstrates
the functions such as add  a node to the beginning, end or middle, or remove a node from the beginning, end, or middle.
It also has two overloaded operators (+ and -) that combines two lists and subtracts two lists.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from an input file, use the data to create linked lists,
   and calls functions to manipulate these lists in various ways.

Name:  LinkedList.h
   Contains the definition for the class LinkedList, and the struct Node.  

Name: Linkedlist.cpp
   Defines and implements the LinkedList class for craeting and manipulating a linked list.  
   This class provides routines to add a node to the beginning middle or end, as
   well as remove a node from the beginning middle or end, and overloaded operators to add and
   subtarct two linked lists.
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on codeblocks.  It was 
   compiled, run, and tested on cse grid ucdenver.  the program compiled
   and ran successfully on both platforms


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [hw5_lynngoin]

   Now you should see a directory named homework with the files:
        main.cpp
        LinkedList.h
        LinkedList.cpp
	makefile
        Readme.txt
	analysis.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [hw5_lynngoin] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[hw5]

4. Delete the obj files, executables, and core dump by
   %./make clean
