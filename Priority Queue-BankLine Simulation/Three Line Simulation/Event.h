//Matthew Lynn-Goin
//107776584
//10/19/17
//successfully compiled an ran on  codeblocks and cse grid
#ifndef EVENT_
#define EVENT_


#include <iostream>
using namespace std;

class Event{
    private:
        char type; //arrival or departure event
        int Time; //time of arrival or departure
        int length; //length of transaction
        int bankline;

    public:
        int getbankLine(){return bankline;}
        void setbankLine(int _bankLine){bankline = _bankLine;}
        char gettype(){return type;}
        int getTime(){return Time;}
        int getlength(){return length;}
        void settype(char _type){type = _type;}
        void setTime(int _Time){Time = _Time;}
        void setlength(int _length){length = _length;}
        friend bool operator < (const Event &lhs, const Event &rhs){ //overloaded less than operator to use with the priority Q

             if(lhs.Time == rhs.Time){ //if left hand time is equal to right hand time
                return lhs.type < rhs.type;
                }
             else{
                return (1000 - lhs.Time) < (1000 - rhs.Time); //subtract from 1000 (arbitrarily large number) to have the most recent times at the front of the priority Q
             }

        }
};
#endif // EVENT_

