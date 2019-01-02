//Matthew Lynn-Goin
//107776584
//10/19/17
//successfully compiled an ran on  codeblocks and cse grid
#ifndef SIMULATION_H
#define SIMULATION_H
#include "Event.h"
#include <queue>




class simulation{

private:
    bool tellerAvailable; //member variable to indicate if a teller is avaialable and a customeer can move out of the line
    int currentTime;
    float amountofCustomers =0;
    float averageWaitTime;
    float waitTime;

public:
    queue<Event>bankLine; //create a queue of event objects called bankline
    priority_queue<Event>eventPriorityQueue; //create a priority queue of event objects (sorted by time)

    simulation(); //constructor
    void simulate(); //main simulation function this function runs the entire simulation
    void processArrival(Event); //process arrival function accepts an event as an argument and returns nothing
    void processDeparture(Event); //process departure function accepts an event as an argument and returns nothing
    void printFinalStatistics(); //print function that print the simulations findings
};

#endif // SIMULATION_H

