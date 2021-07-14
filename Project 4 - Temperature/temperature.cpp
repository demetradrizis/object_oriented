/*
Name: Demetra Drizis
Section: 7
Due Date: 2/4/18
*/

#include <iostream>
#include <iomanip>
#include "temperature.h"

using namespace std; 

Temperature :: Temperature()
{
    format = 'D';                                       //default constructor
    degree = 0;
    scale = 'K';
}
    Temperature :: Temperature(double deg, char s)
{
    degree = deg;
    scale = s;
    format = 'D';                                   //intializing temperature
    
    if (!Set(degree, scale))
    {
        Set(0, 'K');
    }
}
    
    void Temperature :: Input()
{
    cout << endl;
    cout << "Enter a temperature and scale: ";      //allowing for user input
    cin >> degree >> scale;
    cout << endl;
    
    
    while(!Set(degree, scale))
    {
        cout<< "Invalid temperature. Try again: ";      //makes them keep entering until valid
        cin >> degree >> scale;
        cout << endl;
    };
}

    void Temperature :: Show() const
{
    if (format == 'P')
    {
        int oldprecision = cout.precision();
        ios_base::fmtflags oldflags = cout.flags();         //capturing format settings
        
        cout << fixed;
        cout << setprecision(1);                            //setting precision to 1 decimal point
        if (scale == 'F' || scale == 'f')
            cout << degree << " F";
        else if (scale == 'C' || scale == 'C')
            cout << degree << " C";
        else if (scale == 'K' || scale == 'k')
            cout << degree << " K";
        
        cout.precision(oldprecision);           //restoring format settings
        cout.flags(oldflags);
    }
    
    else if (format == 'L')
    {
        int oldprecision = cout.precision();
        ios_base::fmtflags oldflags = cout.flags(); //capturing format settings
        
        if (scale == 'F' || scale == 'f')
            cout << degree << " Fahrenheit";
        else if (scale == 'C' || scale == 'C')      //output to full length temp name
            cout << degree << " Celsius";
        else if (scale == 'K' || scale == 'k')
            cout << degree << " Kelvin";
        
        cout.precision(oldprecision);           //restoring format settings
        cout.flags(oldflags);
    }
    else if (format == 'D')
    {
        if (scale == 'F' || scale == 'f')
            cout << degree << " F";
        else if (scale == 'C' || scale == 'c')
            cout << degree << " C";
        else if (scale == 'K' || scale == 'k')          //default setting
            cout << degree << " K";
    }
}

    bool Temperature :: Set(double deg, char s)
{
    if (degree >= 0 && scale == 'K')
    {
        return true;
    }
    if (degree >= 0 && scale == 'k')                        //checking to see if the set is correct
    {
        return true;
    }
    if (degree >= -273.15 && scale == 'C')
    {
        return true;
    }
    if (degree >= -273.15 && scale == 'c')
    {
        return true;
    }
    if (degree >= -459.67 && scale == 'F')
    {
        return true;
    }
    if (degree >= -459.67 && scale == 'f')
    {
        return true;
    }
    else
    {
        degree = 0;
        scale = 'C';                                    //default parameter set if false
        return false;
    }
}

    double Temperature :: GetDegrees() const                        //gets and return degree
{
    return degree;
}

    char Temperature :: GetScale() const                            //gets and return scale
{
    return scale;
}

    bool Temperature :: SetFormat(char f)
{
    {
        char change_format = f;
        if (change_format == 'D' || change_format == 'P' || change_format == 'L')       //changes format
        {
            format = change_format;
            return true;
        }
        return false;
    }
}

    bool Temperature :: Convert(char sc)
{
    switch (sc)
    {
        case 'F':
        case 'f':
            if (scale == 'C' || scale == 'c')
            {
                degree = (degree * 9/5.0) + 32;
                scale = 'F';
            }
            else if (scale == 'K' || scale == 'k')
            {
                degree = (degree - 273.15) * (9/5.0) + 32;          //converts all temperatures to each other
                scale = 'F';
            }
            return true;
        break;
            
        case 'C':
        case 'c':
            if (scale == 'F' || scale == 'f')
            {
                degree = (degree - 32) * (5/9.0);
                scale = 'C';
            }
            else if (scale == 'K' || scale == 'k')
            {
                degree = degree - 273.15;
                scale = 'C';
            }
            return true;
        break;
            
        case 'K':
        case 'k':
            if (scale == 'F' || scale == 'f')
            {
                degree = (degree + 459.67) * (5/9.0);
                scale = 'K';
            }
            else if (scale == 'C' || scale == 'c')
            {
                degree = degree + 273.15;
                scale = 'K';
            }
            return true;
        break;
            
        default:
        return false;
    }
    
}
   int Temperature :: Compare (const Temperature & d) const
{
    if (DegreestoFahrenheit() < d.DegreestoFahrenheit())                //takes conversion and returns 1 if parameter is smaller
        return 1;
    else if (DegreestoFahrenheit() > d.DegreestoFahrenheit())           // returns -1 if calling object is smaller
        return -1;
    else if (DegreestoFahrenheit() == d.DegreestoFahrenheit())          // return 0 if they are equal
        return 0;
    
    return 0;
}

double Temperature::DegreestoFahrenheit() const
{
    double convert_to_fahrenheit = degree;                      //variable used to hold conversion
    if (scale == 'C')
    {
        convert_to_fahrenheit = (degree * 9/5.0) + 32;          //fahrenheit from celsius
    }
    else if (scale == 'K')
    {
        convert_to_fahrenheit = degree + 273.15;                // Kelvin to Fahrenheit
    }
    return convert_to_fahrenheit;
}
