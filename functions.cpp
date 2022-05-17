// working with functions: example and notes
#include <iostream>
#include <string>
using namespace std;

// How do functions work in C++?
// Basic syntax:
// type name ( parameter1, parameter2, ...) { statements }
// e.g.1.

int addition (int a, int b)
{
  int r;
  r = a + b;
  return r;
}

// e.g.2. If a function does not need to return any value,
// the type to be used is void.

// If no params are give, the void param may be used,
// but it is not required.

// The parentheses after the name differentiate functions
// between ordinary statements.

void printmessage (void) {
  cout << "Example 2: " << endl << "I'm a function with no return type!" << endl << endl;
}

// e.g.3. The functions above pass values by value, meaning
// static copies are made and the values of the parameters 
// themselved are not affected.

// In some cases it is useful to access the external variable
// from inside the function. To do this, we must pass values
// by reference, not by value.

// Basic syntax:
// type name ( type& param, type& param2, type& param3 ... ) { statments }
// instead of:
// type name ( type param, type param2, type param3 ... ) { statments }

void duplicate (int& a, int& b, int& c) 
{
  a *= 2;
  b *= 2;
  c *= 2;
}

// e.g.4. To improve efficiency with large and usually compound types, 
// it's not ideal to pass by value; the values will be copied and take
// up unneeded additional space.

// Passing by reference is an option, however there is a danger that the values
// referenced may be modified by the function.

// To garuntee not modification of values, and to save memory by only copying
// pointers, use const references

// Basic syntax: 
// type name ( const type param&, const type& param2, const type& param3 ... ) { statements }

string concatenate (const string& a, const string& b)
{
  return a + b;
}

// DONT FORGET ABOUT INLINE FUNCTIONS, BUT TBH NO ONE CARES ABOUT THEM

// e.g.5. When you have some parameters and don't need all of them provided
// when calling a function, you can have defaul values for them instead.
// Syntax is obvious from the example below:

int divide (int a, int b=2) 
{
  int r;
  r = a / b;
  return r;
}

// e.g.6. Functions cannot be called before they are declared.
// Thats why all the above functions were defined before the main () function..
// For the sake of clarity I will display the next two example functions
// and example 7 in the file named: "functions_2.cpp"

int main ()
{
  // e.g.1. The below code produces the output:
  // The result is 8
  // Every C++ program begins by calling main ()

  int z; // Declare z
  z = addition (5, 3); 
  // parameters passed to addition and copied
  // Return value of addition () assigned to z
  cout << "Example 1: " << endl << "The result is " << z << endl << endl; // Print the result

  // within a program.
  // Function calls can be replaced with their return value,
  // i.e., {z = 4 + 2} == {z = 4 + addition(3, -1)}

  int a = addition (3, 3);
  cout << "Example 1.2: " << endl << "The result is of a is " << a << endl;

  int b = addition (3, 4);
  cout << "The result of b is " << b << endl << endl;

  // e.g.2. Calling a void function
  printmessage ();

  // e.g.3. Passing by reference
  
  int n1 = 1,n2 = 3,n3 = 9;
  duplicate (n1, n2, n3);
  cout << "Example 3: " << endl;
  cout << "n1=" << n1 << ", n2=" << n2 << ", n3=" << n3 << endl << endl;

  // e.g.4. Const reference
  string string1 = "Hello my name ";
  string string2 = "is Mark.";

  cout << "Example 4: " << endl << concatenate(string1, string2) << endl << endl;

  // e.g.5. Default values
  cout << "Example 5: " << endl;
  cout << divide(12) << endl;
  cout << divide(20, 4) << endl << endl;

  return 0; 
  // main () implicitly returns zero but it's good practice to include it.
  // it can return other stuff if you like.
}