#include <iostream>
#include <iomanip>
#include "temperature.h"

using namespace std;


int main ()
{
    Temperature t1(32, 'F');		// should default to 0 Celsius
    Temperature t2(32, 'F');  // should init to 34.5 Fahrenheit
    Temperature t3(12.6, 'Z');
    Temperature t4(-300, 'c');
    Temperature t5 (15, 'k');
    
    cout << "\nTemperature t1 is: ";
    t1.Show();
    cout <<endl;
    cout << "\nTemperature t2 is: ";
    t2.Show();
      cout <<endl;
    cout << "\nTemperature t3 is: ";
    t3.Show();
      cout <<endl;
    cout << "\nTemperature t4 is: ";
    t4.Show();
      cout <<endl;
    cout << "\nTemperature t5 is: ";
    t5.Show();
    cout<< endl;
    
    cout<< t1.Compare(t2);
    cout << endl;
    cout<< t2.Compare(t1);
    
    // display dates to the screen
    cout << "\nTemperature t1 is: ";
    t1.Show();
    cout << "\nTemperature t2 is: ";
    t2.Show();
    
    //t1.Input();			// Allow user to enter a temperature for t1
    cout << "\nTemperature t1 is: ";
    t1.Show();
    
    t1.SetFormat('L');		// change format of t1 to "Long" format
    cout << "\nTemperature t1 is: ";
    t1.Show();
    t1.Convert('C');
    cout << "\nTemperature t1 is: ";
    t1.Show();
    
    
    // and so on.  Add your own tests to fully test the class'
    //   functionality.
    
    
    return 0;
}
