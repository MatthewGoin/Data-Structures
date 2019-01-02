*******************************************************
*  Name      :  Matthew Lynn-Goin
*  Student ID:  107776584          
*  Class     :  CSC 2421           
*  HW#       :  7                
*  Due Date  :  Oct. 19, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program "Bank Simulation" reads information from a data file containing customer's arrival time and the lenght of their transaction,
and uses the data to to create arrival events and store those events in a priority Q. It then activitaes an event loop that gets the event in the front 
of the priority Q and processes arrival event and departure event depending on the type of event it just pulled from the priority Q. If it is an arrival
event and there is a teller available, it creates a departure event based on the information in the arrival event, and then inserts that departure event
into the priorityQ to be processed later in the event loop, if there is no teller avaiable it inserts the event into the bankLine Q.

If it is a departure event, it checks the bankline Q, if its not empty it pulls that event from the front of the bankline (because someone just left the bank that means someone can be helped now)
and creates a departure event to insert into the priority Q to processed later in time. if the bankline is empty it alters the program that a teller is now available.

So this program processes all arival and departures, and calculates the number of cstomers helped, and then calculates the averge wait time of all the customers and displays this information.
=================================================================================================================================================================================================
The modification to this program from hw7_lynngoin, the that now there are three tellers and three banklines. There is still 1 priority Q but now there are 3 bankline queue's and 3 tellers. The
simulation function is basically but the algorithm for processing arrivals and departures has changed. A decision algorithm was built to choose what teller each arrival event would go to based
on the availability fo all of them (if teller 1 is unavailable to go teller 2 and so ona so forth). Then, when a departure event is created, another piece of data was provided to indicate what teller
each event dealt with and what line they were in. If all tellers are unavailable, another decision algorithm was biult to choose what bankline each new customer would enter.

now, once a departure event was processed, with the new data member we know what teller becomes available, so the next person in that specific line can be processed, if the line is empty then it signals
that a teller is avaialable so when an event is processed in the event loop and it sends an arrival event to the processArrival function the customer will go to the teller that just became availabel.



*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program, all main does is create a simulation object,
   and calls the simulation function to run the simulation. It then also calls the print resuts function to print the results to the screen.
 
Name:  simulation.h
   Contains the definition for the class simulation.  

Name: simulaiton.cpp
   Defines and implements the simulation class for running the bankline simulaiton.  
   This class provides functions to read data froma  text file and create events and put those events into  a priority Q, Then run an event loop to start the simulation.
   Itt also provides functions to process a departure event and an arrival event. There is also a function to compute and print
   the resuts of the programs findings.

Name: Event.h
   Contains the definition for the class Event. Contains the member variables as well as the member functions (getter and setter functions)
   to manipulate/access/set the data. It also contains the overloaded < operator to work in
   conjunction witht the STL priority Q to properly sort the contents of the priority Q based on arrival and departure times.

   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on codeblocks.  It was 
   compiled, run, and tested on codeblocks and the cse grid.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [hw7_lynngoin_partC]

   Now you should see a directory named homework with the files:
        main.cpp
        simulation.h
        simulation.cpp
	Event.h
	datafile2.txt
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [hw7_lynngoin_partC] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[hw7]

4. Delete the obj files, executables, and core dump by
   %./make clean
