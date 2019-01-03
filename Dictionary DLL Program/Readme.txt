*******************************************************
*  Name      :  Matthew Lynn-Goin
*  Student ID:  107 776 584               
*  Class     :  CSC 2421           
*  HW#       :  5              
*  Due Date  :  Oct. 5, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program "LinkedList" creates nodes with data and a next pointer, fills the data with
a character and points the next pointer to the next node that in turn has data stored in it,
thus creating a "liinked list". This linked list has a head pointer(something that points to the 
firstitem in the list, a tail pointer, a current pointer and a previous pointer). The main driver demeonstrates
the functions such as add  a node to the beginning, end or middle, or remove a node from the beginning, end, or middle.
It also has two overloaded operators (+ and -) that combines two lists and subtracts two lists.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from an input file, use the data to create a "dictionary" (a list of DictEntries whose data is filled with words),
   It then reads words in from another file and checks to see if those words are found in the created dictionary or not.
   It uses a forward search (iterators starting at the beginnning of the list and ending at the back) and a reverse search (iterators starting at the back and ending at the front).
   It then prints the contents of the dictionary to a text file in reverse alphabetical order.

Name:  dictionary.h
   Contains the definition for the class dictionary. Provided by professor and unchanged.  

Name: dictionary.cpp
   Defines and implements the dictionary class. This class provides functions to search a list forward or backwards with the use
   of iterators. It also provides the function to print the contents of the dictionary list to a file in reverse alphabetical order.
Name: DictEntry.h
	Defines and implements the DictEntry class. Provided by the instructor and unchanged. Has private variables to store the data, and functions to
	retrieve the data or set/change the data.
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on codeblocks.  It was 
   compiled, run, and tested on cse grid ucdenver.  the program compiled
   and ran successfully on both platforms.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [hw6_lynngoin]

   Now you should see a directory named homework with the files:
        main.cpp
        dictionary.h
        dictionary.cpp
		DictEntry.h
	makefile
    Readme.txt
	dictionary.txt
	findwords.txt
	revsorted.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [hw6_lynngoin] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[hw6]

4. Delete the obj files, executables, and core dump by
   %./make clean
