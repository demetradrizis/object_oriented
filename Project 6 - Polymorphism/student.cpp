/*
Name: Demetra Drizis
Section: 7
Due Date: 4/9/18
*/
#include "student.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

Student :: Student()
{
    cin.getline(last_name, 20, ',');
    cin.getline(first_name, 20);	//get the name and course
    cin.getline(course, 10, ' ');
}
Student :: Student(char * first, char * last, char * c)
{
    strncpy(first_name, first, 20);
    strncpy(last_name, last, 20);	//name and course over
    strncpy(course, c, 10); 
}
StudentList :: StudentList()
{
    list = '\0';			//set string to empty
    count = 0;				//count keeps track of size
}

StudentList :: ~StudentList()
{
    delete [] list;			//destructor
}
void StudentList :: Grow()
{
    Student ** newlist = new Student *[count + 1];
    
    for (int i = 0; i < count; i++)
    {
        newlist[i] = list[i];		//this function grows the list to size
    }
    count++;
    
    delete [] list;
    list = newlist;
}

bool StudentList :: ImportFile(const char* filename)
{
    ifstream in;
    int start; 
    int size;
    char a[20];	
    char b[20];
    char c[10];
    int x1, x2, x3, x4, x5, x6, x7, x8;
    
    in.open(filename);				//opens file
    
    if (!in)
    {						//if file doesn't work return false
        cout << "Invalid File. No data imported" <<endl;
        return false;
    }
    
    else
    {
        in >> size;				//if it does, take in size

        start = count;					
         
       for (int i = 0; i < size; i++)
       {
           Grow();				//grow the function to right size
       }
               
        in.ignore();
 
        for (int i = start; i < count; i++)
        {
            in.getline(a, 20, ',');
            in.ignore();				//takes in the name and course
            in.getline(b, 20, '\n');
            in.getline(c, 10, ' ');
  
            if (strcmp(c, "English") == 0)		//check the course
            {
                in >> x1 >> x2 >> x3 >> x4;		//input info
                list[i] = new English (a, b, c, x1, x2, x3, x4);
            }
            else if (strcmp(c, "History") == 0)
 	   {
                in >> x1 >> x2 >> x3;
                list[i] = new History (a, b, c, x1, x2, x3);
            }
           else if (strcmp (c, "Math") == 0)
	   {
                in >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 >> x8;
                list[i] = new Math(a, b, c, x1, x2, x3, x4, x5, x6, x7, x8);
	    }
            in.ignore();
        }
        
	in.close(); 
        
        return true;
    }  
}
bool StudentList :: CreateReportFile(const char *filename)
{
   ofstream out;
   int gradeA = 0;                                                                              
   int gradeB = 0;
   int gradeC = 0;
   int gradeD = 0;
   int gradeF = 0;
   out.open(filename);		//open output
 
   if (!out)
   {
     cout << "Invalid File. No data exported" <<endl;	//check it
     return false;
   }
   else
   {
     out.clear();
 
     out << "Student Grade Summary" << endl;
     out << "---------------------" << endl;
     out << endl;
     out << "ENGLISH CLASS" << endl << endl;
 
     out << "Student \t\t\t\t Final  Final   Letter" << endl;
     out << "Name    \t\t\t\t Exam   Avg     Grade" << endl;
     out << "----------------------------------------------------------------------" << endl; 
 
     for(int i = 0; i < count; i++)
     {
       if(strcmp(list[i]->Get_Course(), "English") == 0)	//this all formats it right
       {
         out << list[i]->Get_Last() << " " << list[i]->Get_First();
         out << (setw(42-(strlen(list[i]->Get_Last()))-(strlen(list[i]->Get_First()))));             //sets spacing so its the same regardless of name length
         out << list[i]->Final() << "     ";
         out << fixed << showpoint << setprecision(2);
	   if (list[i] -> Average() < 10)
             out << list[i] -> Average() << "    ";
           else if (list[i] -> Average() >= 100)
             out << list[i] -> Average() << "  ";
           else 
             out << list[i] -> Average() << "   ";
         out << list[i]->Final_Grade() << endl;
       }
     
     }
     out << endl;
     out << endl;
     out << "HISTORY CLASS" << endl << endl;
 
     out << "Student \t\t\t\t Final  Final   Letter" << endl;
     out << "Name    \t\t\t\t Exam   Avg     Grade" << endl;
     out << "----------------------------------------------------------------------" << endl;
    
     for (int i = 0; i < count; i++)
     {
        if(strcmp(list[i]->Get_Course(), "History") == 0)
       { 
         out << list[i]->Get_Last() << " " << list[i]->Get_First();
         out << (setw(42-(strlen(list[i]->Get_Last()))-(strlen(list[i]->Get_First()))));             //sets spacing so its the same regardless of name length
         out << list[i]->Final() << "     ";
         out << fixed << showpoint << setprecision(2);
           if (list[i] -> Average() < 10)
             out << list[i] -> Average() << "    ";
           else if (list[i] -> Average() >= 100)
   	     out << list[i] -> Average() << "  ";
	   else
	     out << list[i] -> Average() << "   ";
         out << list[i]->Final_Grade() << endl;       
        }
     }

     out << endl;
     out << endl;
     out << "MATH CLASS" << endl << endl;
 
     out << "Student \t\t\t\t Final  Final   Letter" << endl;
     out << "Name    \t\t\t\t Exam   Avg     Grade" << endl;
     out << "----------------------------------------------------------------------" << endl;

     for (int i = 0; i < count; i++)
     {
        if(strcmp(list[i]->Get_Course(), "Math") == 0)
       {
         out << list[i]->Get_Last() << " " << list[i]->Get_First();
         out << (setw(42-(strlen(list[i]->Get_Last()))-(strlen(list[i]->Get_First()))));             //sets spacing so its the same
	 out << list[i]->Final() << "     ";
         out << fixed << showpoint << setprecision(2);
           if (list[i] -> Average() < 10)
               out << list[i] -> Average() << "    ";
           else if (list[i] -> Average() >= 100)
               out << list[i] -> Average() << "  ";
           else 
               out << list[i] -> Average() << "   ";
	 out << list[i]->Final_Grade() << endl;
        }
     } 	
    
    out << endl << endl; 
    out << "OVERALL GRADE DISTRIBUTION" << endl; 
    
    for(int i = 0; i < count; i++)                                                                        
    {														
        if(list[i]->Final_Grade() =='A')
	{                                                        						
            gradeA++;							
	}                                                                            
        if(list[i]->Final_Grade() =='B')
        {
	    gradeB++;
	}
        if(list[i]->Final_Grade() =='C')
        { 
	   gradeC++;					//checks grades and adds to each one
	}
        if(list[i]->Final_Grade() =='D')
        { 
	   gradeD++;
	}
        if(list[i]-> Final_Grade() =='F')
        {
	    gradeF++;
	}
    }
    out << "A:\t" << gradeA << endl;                     //outputs number of each grade
    out << "B:\t" << gradeB << endl;
    out << "C:\t" << gradeC << endl;
    out << "D:\t" << gradeD << endl;
    out << "F:\t" << gradeF << endl;

   
     return true; 
    }

}
void StudentList :: ShowList() const
{
    cout << left
    << setw(24) <<  "Last"
    << setw(18) << "First"
    <<  setw(18) << "Course" <<endl; 
    cout <<endl;

    for (int i = 0; i < count; i++)
    {
      cout << left
      << setw(24) <<  list[i] -> Get_First()
      << setw(18) << list[i] -> Get_Last()
      << setw(18) << list[i] -> Get_Course()
      << endl; 

    }
    
}
const char * Student :: Get_First() const
{
    return first_name;					//gets first name
}
const char * Student :: Get_Last() const
{
    return last_name;					//gets last name
}
const char * Student :: Get_Course() const
{
    return course;					//gets course
}

English :: English(char * first, char * last, char * c, int A, int P, int M, int F) : Student(first, last, c)
{
    attendance = A;					//english constructor
    project = P;
    midterm = M;
    final_ex = F;
}
History :: History(char * first, char * last, char * c, int t, int M, int F) : Student(first, last, c)
{
    term_p = t;
    midterm = M;					//history constructor
    final_ex = F;
}
Math :: Math (char * first, char * last, char * c, int q1, int q2, int q3, int q4, int q5, int t1, int t2, int F) : Student(first, last, c)
{
    quiz1 = q1;
    quiz2 = q2;
    quiz3 = q3;						//math constructor
    quiz4 = q4;
    quiz5 = q5;
    test1 = t1;
    test2 = t2;
    final_ex = F;
    
}

int English :: Final()
{
    return final_ex;					//return english final
}
double English :: Average()
{
    english_average = (attendance * 0.10) + (project * 0.30) + (midterm * 0.30) + (final_ex * 0.30);	//return english avergae
    return english_average;
}
char English :: Final_Grade()
{
    double avg = Average();
    
    if (avg >= 90 && avg <= 100)
        avg = 'A';
    else if (avg >= 80 && avg <= 89)
        avg = 'B';
    else if (avg >= 70 && avg <= 79)
        avg = 'C';
    else if (avg >= 60 && avg <= 69)
        avg = 'D';
    else
        avg = 'F';						//check the average and compute it to a grade
    
    return avg;
}
int History :: Final()
{
    return final_ex;						//return final exam
}
double History :: Average()
{
    history_average = (term_p * 0.25) + (midterm * 0.35) + (final_ex * 0.40);	
    return history_average;						//return history average
}
char History:: Final_Grade()
{
    double avg = Average();
    
    if (avg >= 90 && avg <= 100)
        avg = 'A';
    else if (avg >= 80 && avg <= 89)
        avg = 'B';
    else if (avg >= 70 && avg <= 79)
        avg = 'C';
    else if (avg >= 60 && avg <= 69)
        avg = 'D';
    else
        avg = 'F';				//check the average and compute it to a grade
    
    return avg;
}
double Math :: Average()
{
    double quiz_avg;
    quiz_avg = (quiz1 + quiz2 + quiz3 + quiz4 + quiz5) / 5.0;
    math_average = (quiz_avg * 0.15) + (test1 * 0.25) + (test2 * 0.25) + (final_ex * 0.35);
    return math_average;				//return math average
}
char Math:: Final_Grade()
{
    double avg = Average();
    
    if (avg >= 90 && avg <= 100)
        avg = 'A';
    else if (avg >= 80 && avg <= 89)
        avg = 'B';
    else if (avg >= 70 && avg <= 79)
        avg = 'C';
    else if (avg >= 60 && avg <= 69)
        avg = 'D';
    else
        avg = 'F';					//check the average and compute it to a grade
    
    return avg;
}
int Math :: Final()
{
    return final_ex;					//return final exam
}

void StudentList :: Sort()
{
   int t_size;
   int t_firstsize;  							//sorts the list
   Student ** temp = new Student * [count]; 

       for (int i = 0; i < count - 1; i++)
       {

          for (int j = i + 1; j < count; j++)
          {
	    
	    if (strlen(list[i] -> Get_First()) > strlen(list[j] -> Get_First()))
                t_size = strlen(list[i] -> Get_First());				//gets the last name size
            else 
	        t_size = strlen(list[j] -> Get_First());

	    if (strlen(list[i] -> Get_Last()) > strlen(list[j] -> Get_Last()))		//gets the first name size
                t_firstsize = strlen(list[i] -> Get_Last());
            else
                t_firstsize = strlen(list[j] -> Get_Last());

             char temp1 [t_size]; 
             char temp2 [t_size]; 							//makes temp array of larger last name
             char temp3 [t_firstsize]; 
             char temp4 [t_firstsize]; 							//makes temp array of larger first name

	     strcpy(temp1, list[i] -> Get_First());
             strcpy(temp2, list[j] -> Get_First());					// copies contents over 
             strcpy(temp3, list[i] -> Get_Last());
             strcpy(temp4, list[j] -> Get_Last()); 					

             for (int a = 0; a < t_size; a++)
             {
		temp1[a] = toupper(temp1[a]); 						//changes last name to all uppercase
		temp2[a] = toupper(temp2[a]);
             }
             
             for (int b = 0; b < t_firstsize; b++)
             {
		temp3[b] = toupper(temp3[b]); 						//changes first name to all uppercase
                temp4[b] = toupper(temp4[b]); 
             }

	      if (strcmp(temp1, temp2) > 0)
              {
                    temp[i] = list[i];
                    list[i] = list[j];							//checks if last names are equal 
                    list[j] = temp[i];							//if not swaps them
              }										//if they are goes onto the first name
              else if (strcmp(temp1, temp2) == 0)
              {
		  if (strcmp(temp3, temp4) > 0)
		  {
		    temp[i] = list[i];							//then sorts by first name
                    list[i] = list[j];
                    list[j] = temp[i];
                  }
              }
          }
       }
}
