/*
Name: Demetra Drizis
Section: 7
Due Date: 2/4/18
*/

class Temperature
{
public:
    Temperature();                                  // constructor
    Temperature(double deg, char s);                //default temperature
    
    void Input();                                   //user input
    void Show() const;
    
    bool Set(double deg, char s);                   //set temp and scale
    
    double GetDegrees() const;
    char GetScale() const;
    
    bool SetFormat(char f);
    bool Convert(char sc);                          //convert scale
    
    int Compare(const Temperature & d) const;           //compare two temps
    double DegreestoFahrenheit() const;             //used to convert temp to compare them

private:
    double degree;
    char scale;
    char format;
};

