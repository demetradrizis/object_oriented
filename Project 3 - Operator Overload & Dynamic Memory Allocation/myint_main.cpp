#include <iostream>
#include <cstring> 
#include <cctype>

#include "myint.h"
using namespace std;

//MyInt Fibonnaci(MyInt num);

int main()
{

  // demonstrate behavior of the two constructors and the << overload

  MyInt x(12345), y("9876543210123456789"), r1(-1000), r2 = "14H67", r3;
  char answer;
  cout << "Initial values: \nx = " << x << "\ny = " << y
       << "\nr1 = " << r1 << "\nr2 = " << r2 << "\nr3 = " << r3 << "\n\n";

  // demonstrate >> overload

  cout << "Enter first number: ";
  cin >> x;
  cout << "Enter second number: ";
  cin >> y;

  cout << "You entered:\n";
  cout << "  x = " << x << '\n';
  cout << "  y = " << y << '\n';

  // demonstrate assignment =
  cout << "Assigning r1 = y ...\n";
  r1 = y;
  cout << "  r1 = " << r1 << '\n';

   // demonstrate comparison overloads
    if (x < y)	cout << "(x < y) is TRUE\n";
    if (x > y)	cout << "(x > y) is TRUE\n";
    if (x <= y)	cout << "(x <= y) is TRUE\n";
    if (x >= y)	cout << "(x >= y) is TRUE\n";
    if (x == y)	cout << "(x == y) is TRUE\n";
    if (x != y)	cout << "(x != y) is TRUE\n";


 r1 = x + y;
    cout << "The sum (x + y) = " << r1 << '\n';
 cout << "The sum (x + 12345) = " << x + 12345 << '\n';
}
