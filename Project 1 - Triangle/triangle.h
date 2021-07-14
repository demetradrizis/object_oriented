/*
Name: Demetra Drizis
Section: 7
Due Date: 1/16/18
*/ 

class Triangle
{
public:		
    Triangle();			
    Triangle(int s, char b = '#', char f = '*');	// constructor with defualt parameters
    
    int GetSize();					//returns the size
    int Perimeter();					//returns perimeter
    double Area();					//returns area
    
    void Grow();					// increases size of triangle
    void Shrink();					// decreases triangle size
    
    void SetBorder(char new_border);			//changes border
    void SetFill(char new_fill);			//changes fill
    
    void Draw();					//shows triangle
    
    void Summary();					//gives triangle info 
    
private:
    int size;
    char border;					//ensure the driver file cannot place bad vaules 
    char fill;
};

