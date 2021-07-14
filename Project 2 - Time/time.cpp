/*
Name: Demetra Drizis
Section: 7
Due Date: 1/16/18
*/

#include <iostream>
#include "time.h"

Time :: Time()                      //default constructor
{
    seconds = 0;
    minutes = 0;
    hours = 0;
    days = 0;
}
Time :: Time (int s)                    //conversion constructor
{
    if (s > 0)
    {
        days = s/60/60/24;
        hours = (s/60/60) % 24;
        minutes = (s/60) % 60;          //converts seconds to days, hours and mins
        seconds = s % 60;
    }
    else if (s <= 0)
    {
        seconds = 0;
        minutes = 0;                    //if less than 0 defaults back to 0
        hours = 0;
        days = 0;
    }
}

Time :: Time (int d, int h, int m, int s)       //constructor with parameters
{
    days = d;
    hours = h;
    minutes = m;
    seconds = s;
    if (d < 0 || h < 0 || m < 0 || s < 0)
    {
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 0;
    }
    
    if (hours > 24)
    {
        days++;
        hours = hours - 24;                     //simplied format
    }
    if (minutes > 60)
    {
        hours++;
        minutes = minutes - 60;
    }
    if (seconds > 60)
    {
        minutes++;
        seconds = seconds - 60;
    }
    
    
}
ostream & operator << (ostream & s, const Time & t)             //outputting objects
{
    s << t.days << "~";
    if (t.hours > 9)
        s << t.hours;
    else
        s << "0" << t.hours;
    if (t.minutes > 9)
        s << ":" << t.minutes;                                  //putting 0's where necessary
    else
        s << ":0" << t.minutes;
    if (t.seconds > 9)
       s << ":" << t.seconds;
    else
        s << ":0" << t.seconds;
    return s;
}
istream & operator >> (istream & s, Time & t)
{
    s >> t.days >> t.hours >> t.minutes >> t.seconds;                   //reading in data
    if (t.days < 0 || t.hours < 0 || t.minutes < 0 || t.seconds < 0)    //can't be less than 0
    {
        t.days = 0;
        t.hours = 0;
        t.minutes = 0;
        t.seconds = 0;
    }
    if (t.hours > 24)
    {
        t.hours = t.hours - 24;
        t.days++;
    }
    if (t.minutes > 60)                                         //simplifying the data
    {
        t.minutes = t.minutes - 60;
        t.hours++;
    }
    if (t.seconds > 60)
    {
        t.seconds = t.seconds - 60;
        t.minutes++;
    }
    return s;
}
Time operator + (const Time & t1, const Time & t2)
{
    Time r;
   
    r.days = t1.days + t2.days;
    r.hours = t1.hours + t2.hours;
    r.minutes = t1.minutes + t2.minutes;                //adding 2 times together
    r.seconds = t1.seconds + t2.seconds;
    
    if (r.hours > 24)
    {
        r.hours = r.hours - 24;
        r.days++;
    }
    if (r.minutes > 60)
    {
        r.minutes = r.minutes - 60;                     //simplifying the format
        r.hours++;
    }
    if (r.seconds > 60)
    {
        r.seconds = r.seconds - 60;
        r.minutes++;
    }
    return r;
}
Time operator - (Time & t1, Time & t2)
{
    Time r;
    
    if (t1 < t2)
    {
       r.days = 0;
       r.hours = 0;
       r.minutes = 0;                               //if first time is less than second, default to 0
       r.seconds = 0;
        return r;
    }
    if (t2.seconds > t1. seconds)
    {
        --t1.minutes;
        t1.seconds = t1.seconds + 60;
    }
    r.seconds = t1.seconds - t2.seconds;            //subtracting time aand simplifying
    
    if (t2.minutes > t1.minutes)
    {
        --t1.hours;
        t1.minutes = t1.minutes + 60;
    }
    r.minutes = t1.minutes - t2.minutes;
    
    if (t2.hours > t1.hours)
    {
        --t1.days;
        t1.hours = t1.hours + 24;
    }
    r.hours = t1.hours - t2.hours;
    r.days = t1.days - t2.days;
    
    return r;
}
Time Time :: operator * (const int multiplier) const
{
    Time r;
    r.days = days * multiplier;
    r.hours = hours * multiplier;
    r.minutes = minutes * multiplier;
    r.seconds = seconds * multiplier;                           //multiplying time by an int
    
  do{
    if (r.seconds > 60)
    {
        r.seconds = r.seconds - 60;
        r.minutes++;
    }
    if (r.minutes > 60)
    {
        r.minutes = r.minutes - 60;                             //simplifying the data
        r.hours++;
    }
    if (r.hours > 24)
    {
        r.hours = r.hours - 24;
        r.days++;
    }
        
  }while (r.seconds > 60 || r.minutes > 60 || r.hours > 24);    //loop needed bc time can go higher than 120 secs/mins
    
    return r;
}
bool operator < (const Time t1, const Time t2)
{
    if (t1.days < t2.days)
        return true;
    if (t1.days == t2.days && t1.hours < t2.hours)                  //checking all the parameters
        return true;
    if (t1.days == t2.days && t1.hours ==  t2.hours && t1.minutes < t2.minutes)
        return true;
    if (t1.days == t2.days && t1.hours ==  t2.hours && t1.minutes == t2.minutes && t1.seconds < t2.seconds)
        return true;
    else
        return false;
}
bool operator > (const Time t1, const Time t2)
{
    if (t1.days > t2.days)
        return true;
    if (t1.days == t2.days && t1.hours > t2.hours)                  //checking all the parameters
        return true;
    if (t1.days == t2.days && t1.hours ==  t2.hours && t1.minutes > t2.minutes)
        return true;
    if (t1.days == t2.days && t1.hours ==  t2.hours && t1.minutes == t2.minutes && t1.seconds > t2.seconds)
        return true;
    else
        return false;
    
}
bool operator <= (const Time t1, const Time t2)
{
    return !(t1 > t2);                          //opposite of greater than
}
bool operator >= (const Time t1, const Time t2)
{
    return !(t1 < t2);                          //opposite of less than
}
bool operator == (const Time t1, const Time t2)
{
    if (t1.days == t2.days && t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds == t2.seconds)
        return true;
    else                                //checking if equal
        return false;
}
bool operator != (const Time t1, const Time t2)
{
    return !(t1 == t2);                          //opposite of equal to
}

Time & Time :: operator ++()
{
    seconds++;                                  //pre increment and simplify
    
    if(seconds > 59 )
    {
        seconds = 0;
        minutes++;
    }
    if(minutes > 59 )
    {
        minutes = 0;
        hours++;
    }
    if(hours > 23 )
    {
        hours =  0;
        days++;
    }
   return *this;
}
Time Time :: operator ++(int)
{
    Time temp = *this;
    seconds = seconds + 1;                  //post increment and simplify
    if(seconds > 59 )
    {
        seconds = 0;
        minutes++;
    }
    if(minutes > 59 )
    {
        minutes = 0;
        hours++;
    }
    if(hours > 23 )
    {
        hours =  0;
        days++;
    }
    
    return temp;
}
Time & Time :: operator --()
{
    if (seconds == 0 && minutes == 0 && hours == 0 && days == 0)
    {
        seconds = 0;
        minutes = 0;                                // pre decrement that cannot be less than 0
        hours = 0;
        days = 0;
    }
    else
    seconds--;
    return *this;
}
Time Time :: operator --(int)
{
    Time temp = *this;
    
    if (seconds == 0 && minutes == 0 && hours == 0 && days == 0)
    {
        seconds = 0;
        minutes = 0;                                    //post decrement that cannot be less than 0
        hours = 0;
        days = 0;
        return temp;
    }
    
    else if (seconds > 0)
    {
        seconds = seconds - 1;
        do
        {
            --minutes;
            seconds = 60;
        }while (seconds < 0);
    };
    return temp;
}

