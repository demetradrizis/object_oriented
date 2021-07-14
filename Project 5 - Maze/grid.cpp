
/*
Name: Demetra Drizis
Section: 7
Due Date: 3/5/18
*/

#include <iostream>
#include <ctime>
#include <cstdlib> 
#include "grid.h"

using namespace std; 

Grid :: Grid ()
{
    array[0][0] = '>';		//initialize grid to mover facing east
}
Grid :: Grid(int r, int c)
{   
    toggle = true;
    int randx, randy, randz;      // 2 param constructor
    rows = r;
    columns = c;
    srand((unsigned int)time(0));
    
    if (rows < 3)
        rows = 3;
    else if (rows > 40)
        rows = 40;
    if (columns < 3)            //doesn't allows rows to be < 3 or >40
        columns = 3;
    else if (columns > 40)
        columns = 40;
    
    
    direction = rand()% 4;
    if (direction == 0)
        mover = '^';
    else if (direction == 1)   //random direction
        mover = '<';
    else if (direction == 2)
        mover = 'v';
    else if (direction == 3)
        mover = '>';
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if ((i == 0) || (i == rows - 1))
            {
                array[i][j] = '#';           //prints out grid
            }
            else if ((j == 0) || (j == columns - 1))
            {
                array[i][j] = '#';
            }
            else
            {
                array[i][j] = '.';
            }
        }
    }
    
    
    mover_row = rand() % (rows - 2) + 1;
    mover_column = rand() % (columns - 2) + 1;
    
    array[mover_row][mover_column] = mover;
    
    randz = rand() % 4;
    randx = rand() % (rows - 2) + 1;
    randy = rand() % (columns - 2) + 1;
    
    if (randz == 0)
    {
        randz = array[0][randy];
        array[0][randy] = ' ';			//randomize wall position
    }
    else if (randz == 1)
    {
        randz = array[rows - 1][randy];
        array[rows - 1][randy] = ' ';
    }
    else if (randz == 2)
    {
        randz = array[randx][0];
        array[randx][0] = ' ';
    }
    else if (randz == 3)
    {
        randz = array[randx][columns - 1];
        array[randx][columns - 1] = ' ';
    }
 
    
}
Grid :: Grid (int r, int c, int mr, int mc, int d)
{
    toggle = true;
    rows = r;
    columns = c;
    mover_row = mr;
    mover_column = mc;				// 5 param constructor
    direction = d;
    
    if (direction == NORTH)
        mover = '^';
    if (direction == WEST)
        mover = '<';
    if (direction == SOUTH)		//mover direction
        mover = 'v';
    if (direction == EAST)
        mover = '>';
    
    if (rows < 1)
        rows = 1;
    if (columns < 1)
        columns = 1;
    
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            if (mover_row < 1 || mover_row > 40)
            {
                if (mover_row <= 20)
                    mover_row = 1;
                else
                    mover_row = 40;
            }
            if (mover_column < 1 || mover_column > 40)
            {
                if (mover_column <= 20)
                    mover_column = 1;
                else
                    mover_column = 40;
            }
            array[i][j] = '.';				//pritns grid
            array[mr][mc] = mover;
        }
    }
}
void Grid :: Display() const
{
    cout << "The Grid:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)	//grid display with toggle
        {
            if (toggle == false && array[i][j] == ' ')
              cout << ". ";
            else 
             cout << array[i][j] << " ";                  
         }
        cout << endl;
    }
    cout << endl;

}
void Grid :: TogglePath()
{
   if(toggle == true)
     toggle = false;
   else if (toggle == false)   // turns toggle on and off
     toggle = true;
}
int Grid :: GetRow() const
{
    return mover_row;    // return mover row
}
int Grid :: GetCol() const
{
    return mover_column;   //return mover col
}
int Grid :: GetNumRows() const
{
    return rows;    //gets rows
}
int Grid :: GetNumCols() const
{
    return columns;      //gets cols
}
bool Grid :: FrontIsClear() const
{
				// checks if front is clear
 if (direction == SOUTH)
    {
        if (array[mover_row + 1][mover_column] == '.' || array[mover_row + 1][mover_column] == ' ')
            return true;
    }
    else if(direction == WEST)
    {
       if (array[mover_row][mover_column - 1] == '.' || array[mover_row][mover_column - 1] == ' ')
           return true;
    }
   else if (direction == NORTH)
    {
       if (array[mover_row - 1][mover_column] == '.' || array[mover_row - 1][mover_column] == ' ')
           return true;

    }
   else if (direction == EAST)
    {
        if (array[mover_row][mover_column + 1] == '.' || array[mover_row][mover_column + 1] == ' ')
           return true;
    }
    
      return false;
}
bool Grid :: RightIsClear() const
{			//checks if position to right is clear
    if (direction == SOUTH)
    {
        if (array[mover_row][mover_column - 1] == ' ' || array[mover_row][mover_column - 1] == '.')
            return true;
    }
    else if(direction == WEST)
    {
        if (array[mover_row - 1][mover_column] == ' ' || array[mover_row - 1][mover_column] == '.')
            return true;
    }
    else if (direction == NORTH)
    {
        if (array[mover_row][mover_column + 1] == ' ' || array[mover_row][mover_column + 1] == '.')
            return true;
    }
    else if (direction == EAST)
    {
        if (array[mover_row + 1][mover_column] == ' ' || array[mover_row + 1][mover_column] == '.')
            return true;
    }
    
    return false;
}
void Grid :: PutDown()
{
     array[mover_row][mover_column] = '@'; // puts down an object
}
bool Grid :: PutDown(int r, int c)
{
   if (r <= rows && c <= columns && array[r][c] == '.')
    {
        array [r][c] = '0';
        return true;		// puts down object with param
    }
    else
        return false;
    
    
}
bool Grid :: PlaceBlock(int r, int c)   //places block at param location 
{
    if (r <= rows && c <= columns && array[r][c] == '.')
    {
        array [r][c] = '#';
        return true;
    }
    else
        return false;
}
bool Grid :: PickUp()
{ 
    {				//picks up block
        array[mover_row][mover_column] = '^'; 
        return true;
    }
 
       return false;
 
}
bool Grid :: valid(int r, int c)
{
    if ((r < rows && r >= 0) && (c < columns && c >= 0) && (array[r][c] != '#' ))
        return true;
        
        return false;   // checks if move is valid
        
}
bool Grid :: Move(int s)
{
    int x = mover_row;
    int y = mover_column;
    int count = 0;
    int put_down = 0;
    
    			//moves around grid
if (valid(mover_row,mover_column) == true)
{
   if (array[x][y] == '@')
       put_down = 1;
  
  
    if (direction  == SOUTH)
    {
        for (int i = mover_row; i < mover_row + s; i++)
           {           
               array[i][mover_column] = ' '; 
           }
     
        char * pos = &array[mover_row + s][mover_column];
        if (*pos != '0')
          *pos = 'v';
	else
	  *pos = '@';
        mover_row = mover_row + s;
         
    }    
    else if (direction  == WEST )
    {
        for (int i = mover_column; i >  mover_column -  s; i--)
           {

               array[mover_row][i] = ' '; 
           }
       
        char * pos = &array[mover_row][mover_column - s];
        if (*pos != '0')
          *pos = '<';
	else
	  *pos = '@';
        mover_column = mover_column - s;
            
    }
    else if (direction  == NORTH)
    { 
       for (int i = mover_row; i > mover_row - s; i--)
           {

               array[i][mover_column] = ' '; 
           }
        
        char * pos = &array[mover_row - s][mover_column];
        if (*pos != '0')
          *pos = '^';
	else
	  *pos = '@';
        mover_row = mover_row - s;
            
    }
    else if (direction  == EAST)
    {
        for (int i = mover_column; i < mover_column + s; i++)
           {
               array[mover_row][i] = ' '; 
           }
      
        char * pos = &array[mover_row][mover_column + s];
        if (*pos != '0')
          *pos = '>';
	else
	  *pos = '@';
        mover_column = mover_column + s;
           
    }

     if (put_down == 1)
	array[x][y] = '0'; 
     if (array[mover_row][mover_column] == '0')
	array[mover_row][mover_column] = '@';
             return true;  
 
}
    return false;

}
void Grid :: TurnLeft()
{
    
    if (direction == NORTH)	  // changes position of direction
    {
	direction = WEST;
    }
    else if (direction == WEST)
    {
        direction = SOUTH;
    }
    else if (direction == SOUTH)
    {
        direction = EAST;
    }
    else if (direction == EAST)
    {
        direction = NORTH; 
    }
    
    
}
void Grid :: Grow(int gr, int gc)
{
   rows = rows + gr; 
   columns = columns + gc; 

  if (rows  > 40)		//grows grid size
   rows = 40;
  if (columns > 40)
   columns = 40; 
     

}
