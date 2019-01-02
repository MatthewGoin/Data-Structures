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
    teller2Available = true;
    teller3Available = true;
    ifstream inputFile ("datafile2.txt"); //open the txt file to read in the data

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
    int banklineNumber;

    if (tellerAvailable && teller2Available && teller3Available){ //if all of the tellers are available
        banklineNumber = 1;
        //tempEvent2.setbankLine(banklineNumber);
        departureTime = currentTime + tempEvent2.getlength(); //set the departure time for the departure event
        addwatingTime = departureTime - tempEvent2.getlength() - tempEvent2.getTime(); //get the wait time
        waitTime = waitTime + addwatingTime; //add the wait time to the total wait time of all customers
        departureEvent.settype(departure); //fill the depature event with the necessayr info
        departureEvent.setTime(departureTime); //fill the departure event with the necessary info
        departureEvent.setbankLine(banklineNumber);
        eventPriorityQueue.push(departureEvent); //add the departure event to the priority Q
        tellerAvailable = false; //indicate that there if no teller available //send to teller1

    }
    else if (!tellerAvailable && teller2Available && teller3Available){ //if teller one is not available; but 2/3 are.
        banklineNumber = 2;
            //tempEvent2.setbankLine(banklineNumber);
        departureTime = currentTime + tempEvent2.getlength(); //set the departure time for the departure event
        addwatingTime = departureTime - tempEvent2.getlength() - tempEvent2.getTime(); //get the wait time
        waitTime = waitTime + addwatingTime; //add the wait time to the total wait time of all customers
        departureEvent.settype(departure); //fill the depature event with the necessayr info
        departureEvent.setTime(departureTime); //fill the departure event with the necessary info
        departureEvent.setbankLine(banklineNumber);
        eventPriorityQueue.push(departureEvent); //add the departure event to the priority Q
        teller2Available = false; //indicate that there if no teller available //send to teller2
    }
    else if (!tellerAvailable && !teller2Available && teller3Available){ //if teller 1 and 2 are not available but 3 is
        banklineNumber = 3;
        departureTime = currentTime + tempEvent2.getlength(); //set the departure time for the departure event
        addwatingTime = departureTime - tempEvent2.getlength() - tempEvent2.getTime(); //get the wait time
        waitTime = waitTime + addwatingTime; //add the wait time to the total wait time of all customers
        departureEvent.settype(departure); //fill the depature event with the necessayr info
        departureEvent.setTime(departureTime); //fill the departure event with the necessary info
        departureEvent.setbankLine(banklineNumber);
        eventPriorityQueue.push(departureEvent); //add the departure event to the priority Q
        teller3Available = false; //indicate that there if no teller available //send to teller3
    }
    else if (!tellerAvailable && teller2Available && !teller3Available){ //if teller 2 is available; 1 and 3 are not
            banklineNumber = 2;
        departureTime = currentTime + tempEvent2.getlength(); //set the departure time for the departure event
        addwatingTime = departureTime - tempEvent2.getlength() - tempEvent2.getTime(); //get the wait time
        waitTime = waitTime + addwatingTime; //add the wait time to the total wait time of all customers
        departureEvent.settype(departure); //fill the depature event with the necessayr info
        departureEvent.setTime(departureTime); //fill the departure event with the necessary info
        departureEvent.setbankLine(banklineNumber);
        eventPriorityQueue.push(departureEvent); //add the departure event to the priority Q
        teller2Available = false; //indicate that there if no teller available //send to teller2
    }
    else if (tellerAvailable && !teller2Available && teller3Available){ //teller 1/3 available: 2 is not
            banklineNumber = 1;
        departureTime = currentTime + tempEvent2.getlength(); //set the departure time for the departure event
        addwatingTime = departureTime - tempEvent2.getlength() - tempEvent2.getTime(); //get the wait time
        waitTime = waitTime + addwatingTime; //add the wait time to the total wait time of all customers
        departureEvent.settype(departure); //fill the depature event with the necessayr info
        departureEvent.setTime(departureTime); //fill the departure event with the necessary info
        departureEvent.setbankLine(banklineNumber);
        eventPriorityQueue.push(departureEvent); //add the departure event to the priority Q
        tellerAvailable = false; //indicate that there if no teller available //send to teller 1
    }
    else if (tellerAvailable && !teller2Available && !teller3Available){ //teller 1 available: 2/3 are not
            banklineNumber = 1;
        departureTime = currentTime + tempEvent2.getlength(); //set the departure time for the departure event
        addwatingTime = departureTime - tempEvent2.getlength() - tempEvent2.getTime(); //get the wait time
        waitTime = waitTime + addwatingTime; //add the wait time to the total wait time of all customers
        departureEvent.settype(departure); //fill the depature event with the necessayr info
        departureEvent.setTime(departureTime); //fill the departure event with the necessary info
        departureEvent.setbankLine(banklineNumber);
        eventPriorityQueue.push(departureEvent); //add the departure event to the priority Q
        tellerAvailable = false; //indicate that there if no teller available //send to teller 1
    }
    else if (tellerAvailable && teller2Available && !teller3Available){ //teller 1/2 available; 3 is not
        banklineNumber = 1;
        departureTime = currentTime + tempEvent2.getlength(); //set the departure time for the departure event
        addwatingTime = departureTime - tempEvent2.getlength() - tempEvent2.getTime(); //get the wait time
        waitTime = waitTime + addwatingTime; //add the wait time to the total wait time of all customers
        departureEvent.settype(departure); //fill the depature event with the necessayr info
        departureEvent.setTime(departureTime); //fill the departure event with the necessary info
        departureEvent.setbankLine(banklineNumber);
        eventPriorityQueue.push(departureEvent); //add the departure event to the priority Q
        tellerAvailable = false; //indicate that there if no teller available // send to teller1
    }
    /*else if (!tellerAvailable && !teller2Available && !teller3Available){

    }*/
    else { //if the line is not empty or a teller is not available //if all tellers are unavailable
        //bankLine.push(tempEvent2);
        if (bankLine.size() == 0 && bankLine2.size() ==0 && bankLine3.size() == 0){ //if all lines are empty
            //banklineNumber =1
            //tempEvent2.setbankLine(banklineNumber);
            bankLine.push(tempEvent2); //put into bankline 1
        }
        else if (bankLine.size() < bankLine2.size() && bankLine.size() < bankLine3.size()){ //if line 1 is the smallest
            //banklineNumber = 1;
            //tempEvent2.setbankLine(banklineNumber);
            bankLine.push(tempEvent2); //put into bankline 1
        }
        else if(bankLine2.size() < bankLine.size() && bankLine2.size() < bankLine3.size()){ //if line 2 is the smallest
            //banklineNumber = 2;
            //tempEvent2.setbankLine(banklineNumber);
            bankLine2.push(tempEvent2); //put into bankline 2
        }
        else if(bankLine3.size() < bankLine.size() && bankLine3.size() < bankLine2.size()){ //if line 3 is the smallest
            //banklineNumber = 3;
            //tempEvent2.setbankLine(banklineNumber);
            bankLine3.push(tempEvent2); //put into bankline3
        }
        else if (bankLine.size() == bankLine2.size()){ // if first 2 banklines are equal in size
            //banklineNumber = 1;
            //tempEvent2.setbankLine(banklineNumber);
            bankLine.push(tempEvent2); //put into first bankline
        }
        else if (bankLine.size() == bankLine3.size()){ //if first and third are equal in size
            //banklineNumber = 1;
            //tempEvent2.setbankLine(banklineNumber);
            bankLine.push(tempEvent2); //put into first bankline
        }
        else if (bankLine2.size() == bankLine3.size()){ //if second and third are equal in size
            //banklineNumber = 2;
            //tempEvent2.setbankLine(banklineNumber);
            bankLine2.push(tempEvent2); //put into bankline 2
        }
    }

}

void simulation::processDeparture(Event tempEvent){ //process departure function: accepts an event from the front of the priority Q

    cout << "processing departure event at time: " << setw(2) <<tempEvent.getTime() << endl; //display the departure time
    int addWaitingTime =0;
    Event tempEvent4; //create an event
    Event departureEvent;
    char departure = 'd';
    int departureTime;
    if (tempEvent.getbankLine() == 1){ //if customer was in line 1
        if (!bankLine.empty()){
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
            tellerAvailable = true; //indicate teller 1 is now available
        }
    }
    else if (tempEvent.getbankLine() == 2){ //if customer was in line 2
        if (!bankLine2.empty()){ //if there are customers in the line
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
            teller2Available = true; //indicate teller 2 is now available
        }

    }
    else if (tempEvent.getbankLine() == 3){ //if customer was in line 3
        if (!bankLine3.empty()){ //if there are customers in the line
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
            teller3Available = true; //indicate teller 3 is now available
        }

    }
   /* if (!bankLine.empty()){ //if there are customers in the line
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
    }*/
}

void simulation::printFinalStatistics(){ //print the final statistics
    //cout << waitTime << endl;
    averageWaitTime = waitTime / amountofCustomers; //determine the average wait time of all the cutsomers
    cout << "      Total number of people processed: " << amountofCustomers << endl; //display the number of customers processed
    cout << "      Average amount of time spent waiting: " << averageWaitTime << endl; //display the average amount of time waited

}
