/*
Name: Demetra Drizis
Section: 7
Due Date: 2/16/18
*/
#include <iostream> 
using namespace std; 

class Time
{
    friend ostream & operator << (ostream & s, const Time & t);             //output and input streams
    friend istream & operator >> (istream & s, Time & t);
    friend Time operator + (const Time & t1, const Time & t2);              //add and suptract 2 time functions
    friend Time operator - (Time & t1, Time & t2);
    friend bool operator < (const Time t1, const Time t2);
    friend bool operator > (const Time t1, const Time t2);
    friend bool operator <= (const Time t1, const Time t2);
    friend bool operator >= (const Time t1, const Time t2);             //bool comparison operators
    friend bool operator == (const Time t1, const Time t2);
    friend bool operator != (const Time t1, const Time t2);
public:
    Time();
    Time(int s);
    Time(int d, int h, int m, int s);
    
    Time operator *(const int multiplier) const;             //multiply by const int
    Time & operator++();
    Time operator++(int);                                   //increment and decrement functions
    Time & operator--();
    Time operator--(int);
    
private:
    int seconds;
    int minutes;
    int hours;                              //pivate data accessed by object
    int days;
};
