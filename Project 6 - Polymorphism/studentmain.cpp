/*
Name: Demetra Drizis
Section: 7
Due Date: 4/9/18
*/
#include "studentlist.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;


void menu();

int main()
{
    char letter;
    char filename[20];
    char outfile[20];
    fstream in;
    ofstream out;
    StudentList x;
    
    menu();
    do
    {
        
        cout << "> ";
        cin >> letter;			//asks for user input
        
        
        if (letter == 'I' || letter == 'i')
        {
            cout << "Enter filename: ";
            cin >> filename;
            
            x.ImportFile(filename);		//imports file info 		
            
        }
        else if (letter == 'S' || letter == 's')
        {
            x.ShowList();			// shoes brief list
        }
        else if (letter == 'E' || letter == 'e')
        {
            cout << "Enter filename: ";
            cin >> outfile;
            
           x.CreateReportFile(outfile);		//exports info
        }
        else if (letter == 'M' || letter == 'm')
        {
            menu();				//reprints menu
        }
        else if (letter == 'Q' || letter == 'q')
        {
            cout << "Goodbye!" << endl; 		//quits
            break;
        }
        else if (letter == 'O' || letter == 'o')
        {
            x.Sort();   				//sorts
        }
    }while (letter == 'I' || letter == 'i' || letter == 'S' || letter == 's' || letter == 'E' || letter == 'e' ||  letter == 'M' || letter == 'm' || letter == 'Q' || letter == 'q' || letter == 'O' || letter == 'o');
    
    
    
    
}
void menu()						//menu function
{
    cout << "\t\t\t *** Student List Menu *** " << endl;
    cout << endl;
    cout << "\t\tI \t Import student from a file" << endl;
    cout << "\t\tS \t Show student list (brief)" << endl;
    cout << "\t\tE \t Export a grade report (to file)" << endl;
    cout << "\t\tM \t Show this Menu" << endl;
    cout << "\t\tQ \t Quit Program" << endl;
    cout << "\t\tO \t sOrt student list" << endl; 
}

