/*
Name: Demetra Drizis
Section: 7
Due Date: 3/26/18
*/
#include <iostream>
using namespace std; 

// starter file for MyInt class header


class MyInt
{
    // these overload starters are declared as friend functions
    
    friend MyInt operator+ (const MyInt& x, const MyInt& y);            //addition overload
    // add in multiplication, as well
    friend MyInt operator* (const MyInt & x, const MyInt & y);          //multiplication overload

    // add in the other comparison overloads, as well
    // declare overloads for input and output (MUST be non-member functions)
    //  you may make them friends of the class
    friend ostream & operator << (ostream & s, const MyInt & M);        //input and output streams
    friend istream & operator >> (istream & s, MyInt & M);
    friend bool operator < (const MyInt x, const MyInt y);
    friend bool operator > (const MyInt x, const MyInt y);
    friend bool operator <= (const MyInt x, const MyInt y);
    friend bool operator >= (const MyInt x, const MyInt y);             //bool comparison operators
    friend bool operator == (const MyInt x, const MyInt y);
    friend bool operator != (const MyInt x, const MyInt y);
    
    
public:
    MyInt(int n = 0);       // first constructor
    MyInt(const char * s);        //second constructor
    ~MyInt();               // destructor
    MyInt & operator= (const MyInt & M);	// assignment operator
    MyInt (const MyInt & M);                // copy constructor
    MyInt operator++();                     // pre increment
    MyInt operator++(int);                  // post increment

    
private:
    int currentsize;
    int maxsize;
    char * list;
    int C2I(char c);
    char I2C(int x);
    void Grow();
    int carryover;

    // member data (suggested:  use a dynamic array to store the digits)
    
};
