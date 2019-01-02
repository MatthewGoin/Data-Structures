//Matthew Lynn-Goin
//107776584
//10/19/17
//successfully compiled an ran on  codeblocks and cse grid
#include <iostream>
#include "Event.h"
#include "simulation.h"

using namespace std;

int main()
{
    simulation simulation1;
    cout << "==========================================================================" << endl;
    cout << "================BANK LINE AND TELLER SIMULATION PROGRAM===================" << endl;
    cout << "==========================================================================" << endl;
    cout << endl;
    cout << "--------------> Simulation Begins " << endl;
    simulation1.simulate(); //create a simulatoin object
    cout << "--------------> Simulation Ends " << endl;
    cout << endl;
    cout << "Final Statistics: " << endl;
    cout << endl;
    simulation1.printFinalStatistics();//print the final statistics
    cout << endl;
    cout << "=========================================================================" << endl;
    cout << "END OF SIMULATION PROGRAM " << endl; //end of the program
    return 0;
}
