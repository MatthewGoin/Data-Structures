//Matthew Lynn-Goin
//107776584
//10/19/17
//successfully compiled an ran on  codeblocks and cse grid
#include "simulation.h"
#include "Event.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

simulation::simulation(){ //constructor

}

void simulation::simulate(){ //main simulaiton functions the drives the entire simulation

    tellerAvailable = true; //set teller available equal to true (the bank is open and lines are empty)
    ifstream inputFile ("datafile.txt"); //open the txt file to read in the data

    while(!inputFile.eof()){ //while not end of file

        Event tempEvent; //create a temp event
        char temptype = 'a'; //set the type equal to 'a' indicating an arrival event
        tempEvent.settype(temptype); //set the type of newly created temp event equal to an arrival event
        int tempTime;
        int tempLength;

        string line = "";
        stringstream ss; //declare a stringstream
        getline(inputFile, line); //get the first line of data
        ss << line;

       ss >> tempTime; //put time information in temptime
       ss >> tempLength; //put transaction time information in templength

            tempEvent.setTime(tempTime); //set time:pass in temp time
            tempEvent.setlength(tempLength); //set length:pass in temp length
            amountofCustomers ++; //incrememt amount of customers

        eventPriorityQueue.push(tempEvent); //push this newly created arrival event into the priority event Q

    }

    while (!eventPriorityQueue.empty()){ //while the event priority Q is not empty (event loop)


        Event tempEvent2 = eventPriorityQueue.top(); //get the event at the front of priority Q and store in tempEvent2
        eventPriorityQueue.pop(); //remove this event from the priority Q
        currentTime = tempEvent2.getTime(); //set the current time
        if (tempEvent2.gettype() == 'a'){ //if it is an arrival event
            processArrival(tempEvent2); //process the arrival(pass in the event in the front of the priority Q)
        }
        else
            processDeparture(tempEvent2); //process the departure event (pass in the event from the front of the priority Q)

    }
}

void simulation::processArrival(Event tempEvent2){ //process arrival function: accepts an event as an argument

    cout << "processing arrival event at time:  " << setw(3) << tempEvent2.getTime() << endl; // display the arrival time
    int departureTime;
    int addwatingTime;
    Event departureEvent; //create a departure event
    char departure = 'd';

    if (bankLine.empty() && tellerAvailable){ //if the line is empty and the teller is available
        departureTime = currentTime + tempEvent2.getlength(); //set the departure time for the departure event
        addwatingTime = departureTime - tempEvent2.getlength() - currentTime; //get the wait time
        waitTime = waitTime + addwatingTime; //add the wait time to the total wait time of all customers
        departureEvent.settype(departure); //fill the depature event with the necessayr info
        departureEvent.setTime(departureTime); //fill the departure event with the necessary info
        eventPriorityQueue.push(departureEvent); //add the departure event to the priority Q
        tellerAvailable = false; //indicate that there if no teller available

    }
    else { //if the line is not empty or a teller is not available
        bankLine.push(tempEvent2); //add the event to the bankline
    }

}

void simulation::processDeparture(Event tempEvent){ //process departure function: accepts an event from the front of the priority Q

    cout << "processing departure event at time: " << setw(2) <<tempEvent.getTime() << endl; //display the departure time
    int addWaitingTime =0;
    Event tempEvent4; //create an event
    Event departureEvent;
    char departure = 'd';
    int departureTime;
    if (!bankLine.empty()){ //if there are customers in the line
        tempEvent4 = bankLine.front(); //get the customer at the front of the bankline
        bankLine.pop(); //now remove this event from the bankline Q
        departureTime = currentTime + tempEvent4.getlength(); //set the departure time
        addWaitingTime = departureTime - tempEvent4.getlength() - tempEvent4.getTime(); //get the wait time
        waitTime = waitTime + addWaitingTime; //add the wait time to the total wait time of all customers
        departureEvent.settype(departure);
        departureEvent.setTime(departureTime); //fill the departure event with the information
        eventPriorityQueue.push(departureEvent); //add this departur event to the priority Q

    }
    else{
        tellerAvailable = true; //indicate that a telelr is available
    }
}

void simulation::printFinalStatistics(){ //print the final statistics

    averageWaitTime = waitTime / amountofCustomers; //determine the average wait time of all the cutsomers
    cout << "      Total number of people processed: " << amountofCustomers << endl; //display the number of customers processed
    cout << "      Average amount of time spent waiting: " << averageWaitTime << endl; //display the average amount of time waited

}



