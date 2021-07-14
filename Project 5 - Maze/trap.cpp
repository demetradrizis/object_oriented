/*
Name: Demetra Drizis
Section: 7
Due Date: 3/5/18
*/

#include <iostream>
#include <cstdlib>                  //include cstdlib and ctime for random numb$
#include <ctime>
#include "grid.h"
using namespace std;

int main()
{
    int rows, columns;
    int goal = 0; 
    
    
    cout << "Input number of rows: ";
    cin >> rows;
    cout << "Input number of columns: ";
    cin >> columns;
    Grid g(rows, columns);		// prints grid to specified size
    g.Display();

    int mover_row = g.GetRow();
    int mover_col  = g.GetCol();       //to track position

    while (!g.FrontIsClear())
    {
       g.TurnLeft();
    };
   
  if (g.FrontIsClear())
  { 
    do					//moves forward till wall is hit
    {
      g.Move(1);
      mover_row = g.GetRow();
      mover_col = g.GetCol();
      if (mover_row == rows - 1 || mover_row == 0 || mover_col == columns - 1 || mover_col == 0)
                  goal = 1;
  
    }while(g.FrontIsClear()); 
  }
 mover_row = g.GetRow();
 mover_col = g.GetCol();    	//tracks position


while (goal == 0) 	// when goal equals 1, loop breaks
{

  while (g.FrontIsClear())
{
       if (g.RightIsClear())
      {
       g.TurnLeft();
       g.TurnLeft();
       g.TurnLeft();			// checks if right is clear
       g.Move(1);			// if so turns and moves 1
       mover_row = g.GetRow();
       mover_col = g.GetCol();
       goal = 1;       
      }
       else
      {
        g.Move(1);
        mover_row = g.GetRow();
        mover_col = g.GetCol();
            if (mover_row == rows - 1 || mover_row == 0 || mover_col == columns - 1 || mover_col == 0)
                  goal = 1;   
      }
    mover_row = g.GetRow();
    mover_col = g.GetCol();
};
if (goal == 1)  // once goal is reached break the loop
 break;

   g.TurnLeft();

while (g.FrontIsClear())
{
       if (g.RightIsClear())
      {
       g.TurnLeft();
       g.TurnLeft();
       g.TurnLeft();   // repeat above steps
       g.Move(1);
       mover_row = g.GetRow();
       mover_col = g.GetCol();
        goal = 1; 
      }
       else
      {
        g.Move(1);
        mover_row = g.GetRow();
        mover_col = g.GetCol();
        if (mover_row == rows - 1 || mover_row == 0 || mover_col == columns - 1 || mover_col == 0)
                  goal = 1;
      }
    mover_row = g.GetRow();
    mover_col = g.GetCol();
};
if (goal == 1)
 break;

g.TurnLeft();

while (g.FrontIsClear())
{
       if (g.RightIsClear())
      {
       g.TurnLeft();
       g.TurnLeft();
       g.TurnLeft();
       g.Move(1);
       mover_row = g.GetRow();
       mover_col = g.GetCol();
        goal = 1;
       // g.Display();
      }
       else
      {
        g.Move(1);
        mover_row = g.GetRow();
        mover_col = g.GetCol();
         if (mover_row == rows - 1 || mover_row == 0 || mover_col == columns - 1 || mover_col == 0)
                  goal = 1;
      }
    mover_row = g.GetRow();
     mover_col = g.GetCol();
};
if (goal == 1)
 break;


};


if (goal == 1)
{
   g.Display();              // display final grid
   cout << "We Escaped!!\n";
}  

}
