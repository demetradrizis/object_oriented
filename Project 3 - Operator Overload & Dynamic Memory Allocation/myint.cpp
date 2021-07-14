/*
Name: Demetra Drizis
Section: 7
Due Date: 3/26/18
*/
#include <iostream> 
#include "myint.h"
#include <iomanip> 
#include <cstring>
#include <cctype>

using namespace std; 

int MyInt :: C2I(char c)
// converts character into integer (returns -1 for error)
{
    if (c < '0' || c > '9')	return -1;	// error
    return (c - '0');				// success
}
//source Bob Myers
char MyInt :: I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
    if (x < 0 || x > 9)		return '\0';	// error
    return (static_cast<char>(x) + '0'); 	// success
}
//source Bob Myers
MyInt :: MyInt (int n)
{
    currentsize = 1;            //starts size at 0
    maxsize = 5;
    int number = n;
    int reverse;
    
    list = new char[maxsize];   //creating dynamic array
  
  if (n > 0)
  {
        while ((n = n /10))
        {
            n = n/10;           // divide n by 10 until u can only mod
            currentsize++;
        };
    if (maxsize < currentsize)
    {
        do
        {
            Grow();
        }while (maxsize < currentsize);     //grow to appropriate size
    }
      
    for (int i = 0; i < maxsize; i++)
    {
        char new_val = I2C(number % 10);
        number = number/10;
        list[i] = new_val;                  //setting list equal to new value and it its backwards
        
    }
      for (int i = 0; i < maxsize/2; i++)
      {
          reverse = list[maxsize-1-i];
          list[maxsize-1-i] = list[i];                  //flips the array to be in correct order
          list[i] = reverse;
      }
  }
    
  else if (n < 0)
  {
      currentsize = 1;
      list[0] = '0';                      // if n < 0 the list just equals 0
  }
    else
    {
        currentsize = 1;                    //if empty, default to zero
        list[0] = '0';
    }
   
}

MyInt :: MyInt(const char * s)
{
    maxsize = currentsize = strlen(s);
    list = new char[maxsize + 1];           //new array for size of string
    strcpy(list, s);                        //copy one over
    

   for (int i = 0; i < maxsize; i++)
    {
        if (list[i] < '0' || list[i] > '9')
        {
            list = new char[1];                 //if list isnt a number defaults to 0
            list[0] = '0';
        }
    }
}

MyInt :: ~MyInt()
{
    delete [] list;                     //destructor
}

MyInt & MyInt :: operator= (const MyInt & M)
{
    if (this != & M)
    {
        delete [] list;
        maxsize = M.maxsize;
        currentsize = M.currentsize;            //assignment operator
        list = new char[maxsize];
        strcpy(list, M.list);
    }
        return * this;
}

MyInt :: MyInt (const MyInt & M)
{
    maxsize = M.maxsize;
    currentsize = M.currentsize;            //copy cosntructor
    list = new char [maxsize];
    strcpy (list, M.list);
}

MyInt MyInt :: operator ++()
{
    int num;

    for (int i = 0; i < maxsize; i++)
    {
        list[i] = I2C(num++);               //pre increment
    }
    
    return * this;
}

MyInt MyInt :: operator ++(int)
{
    MyInt temp = *this;
    int num;

    for (int i = 0; i < maxsize; i++)
    {
        list[i] = I2C(num + 1);         //post increment
    }
    return temp;
}

MyInt operator + (const MyInt& x, const MyInt& y)
{
    MyInt z;
    MyInt a = y;
    MyInt b = x;
    int total = 0;
    int carry = 0;
    int num1 = 0;
    int num2 = 0;

    
    if (x.maxsize >= y.maxsize)
    {
        z.maxsize = x.maxsize + 1;
        
    }

   if (x.maxsize < y.maxsize)
    {
        z.maxsize = y.maxsize + 1;
        
    }

    z.list = new char [z.maxsize];
    
    for (int i = z.maxsize - 1; i >= 0; i--)
    {
        num1 = z.C2I(x.list[i]);
        num2 = z.C2I(y.list[i]);

        total = (num1 + num2 + carry) % 10;
        carry = (num1 + num2 + carry) / 10;

        
        char new_val = z.I2C(total);
        z.list[i] = new_val;
    }

    if (carry > 0)
    {
        for (int i = z.maxsize; i >= 0; i--)
        {
            z.list[i + 1] = z.list[i];
        }
        z.list[0] = z.I2C(carry);
    }
   

    return z;
}

/*MyInt operator* (const MyInt & x, const MyInt & y)
{
 
}*/

ostream & operator << (ostream & s, const MyInt & M)
{
    for (int i = 0; i < M.maxsize; i++)
        s << M.list[i];                             //output operator
    return s;
}

istream & operator >> (istream & s, MyInt & M)
{
    delete [] M.list;
    M.maxsize = 5;                              // new list of size
    M.currentsize = 0;
    
    M.list = new char[M.maxsize];

    while (isspace(s.peek()))           //check for spaces
    {
            s.ignore();
    }

    while(isdigit(s.peek()))
    {
        M.list[M.currentsize] = s.get();
        M.currentsize++;
                                                    //get digits
        if (M.currentsize > M.maxsize)
            M.Grow();
    }
    
    return s;
}

bool operator < (const MyInt x, const MyInt y)
{
    if (strcmp(x.list, y.list) < 0)
        return true;
    else
        return false;
}

bool operator > (const MyInt x, const MyInt y)
{
    if (strcmp(x.list, y.list) > 0)
        return true;
    else
        return false;
}

bool operator <= (const MyInt x, const MyInt y)
{
    return !(x > y);
}

bool operator >= (const MyInt x, const MyInt y)
{
    return !(x < y);
}

bool operator == (const MyInt x, const MyInt y)
{
    if (strcmp(x.list, y.list) == 0)
        return true;
    else
        return false;
}

bool operator != (const MyInt x, const MyInt y)
{
    return !(x == y);
}

void MyInt :: Grow()
{
    maxsize = currentsize + 5;
    char * newlist = new char[maxsize];

   for (int i = 0; i < currentsize; i++)
    {
        newlist[i] = list[i];
    }
    for (int i = currentsize; i < maxsize; i++)
    {
        newlist[i] = '\0';
    }
        delete [] list;
        list = newlist;
}



