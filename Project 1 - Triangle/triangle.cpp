/*
Name: Demetra Drizis 
Section: 7
Due Date: 1/16/18
*/ 

#include <iostream>
#include <cmath>
#include <iomanip>
#include "triangle.h"

using namespace std;

Triangle :: Triangle()				//sets triangle size to range and default broder/fill
{
    if (size < 1)
    {
        size = 1;
    }
    else if (size > 39)
    {
        size = 39;
    }
    border = '#';
    fill = '*';
}

Triangle :: Triangle(int s, char b, char f)     // defualt border and fill characters for constructor
{
    size = s;
    border = b;
    fill = f;					//accessing the private components for error checking
}

int Triangle :: GetSize()
{						//returns size that must be in the range 1-39
    if (size < 1)
    {
        size = 1;
    }
    else if (size > 39)
    {
        size = 39;
    }
    return size;
}

int Triangle :: Perimeter()
{							//multiples size by 3 to return perimeter
    int perimeter = size * 3;
    return perimeter;
}

double Triangle :: Area()				// equation to return area
{
    double area = (sqrt(3)/ 4) * pow(size, 2);
    return area;
}
void Triangle :: Grow()
{
    if (size > 39 || size < 1 )					//doesn't allow triagle to grow bigger than 39
    GetSize();
    else
    size++;
}

void Triangle :: Shrink()
{
    if (size >39 || size < 1 )
    GetSize();					//doesnt't allow triangle to be smaller than 1
    else
    size --;
}

void Triangle ::  SetBorder(char new_border)
{
    if (new_border > char(32) && new_border < char(127))
    {
        border = new_border;		//checks to see if the character is ok and sets default if not
    }
    else
    border = '#';
}

void Triangle :: SetFill(char new_fill)
{
    if (new_fill > char(32) && new_fill < char(127))
    {
      fill = new_fill;		// character check for fill
    }
    else
    fill = '*';
    
}

void Triangle :: Draw()
{
    int start = 2;
    int beginning = 4;				//starts triangle at correct spaces
    int i;
    for(i = start; i <= size; i++)		//loops through the size of the triangle
    {
        for(int gap = 0; gap <= size-i; gap++)
        {
            cout << " ";			//space in between each character
        }
        
        if(i > start)
        {
           cout << border << " ";		// prints border
            
            for(int b = beginning; b <= i; b++)
            {
                cout << fill << " ";			//fills inside border
            }
            
        }
    
        cout <<  border << " ";
        cout << endl;
        
    }
    for (int j = beginning; j < size+beginning; j++)            //starts the bottom line of the triangle
    {
        cout << border << " ";
    }
    cout << endl;
    
}

void Triangle :: Summary()
{
    cout << fixed << showpoint << setprecision(2);
    cout << "Size of triangle's side = " << size << " units." << endl;
    cout << "Perimeter of triangle = " << size * 3 << " units." << endl;
    cout << "Area of triangle = " << (sqrt(3)/ 4) * pow(size, 2) << " units." << endl;
    cout << "Triangle looks like: "<<endl;
    Draw();							//summary of specified triangle
}
