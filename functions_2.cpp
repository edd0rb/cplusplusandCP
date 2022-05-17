#include <iostream>
using namespace std;

// e.g.6. The prototype of a function can be declared without actually
// defining anything the function completely, giving just enough details
// to allow the types involved in a function call to be known.

// The syntax is the same as declaring a function normally, but without the
// statements. Also it is not necessecary to provide the names of the paramaters, 
// and if need be, they can be modified to anything without changing them where
// the function is actually defined.

// Syntax example:
// int protofunction (int first, int second); is equivalent to ...
// int protofunction (int, int);

// e.g.6. Here is an example of a (admittedly not practicle but) valid
// use of function declaration

// e.g.7. Here is an example of recursivity; A type of function which calls
// itself and acts as a useful alternative to iteration in certain cases.

// factorial calculator:
int factorial (int n) {
  while (n != 1) 
    return n * factorial (n-1);
  return 1;
}

void odd (int);
void even (int);

int main ()
{
  int i;
  do {
    cout << "Please, enter number (0 to exit): ";
    cin >> i;
    odd (i);
  } while (i != 0);

  int n;
  cout << "Please, enter a positive integer to calculate it's factorial: ";
  cin >> n;
  cout << factorial (n);

  return 0;
}

void odd (int x) {
  if ((x%2) != 0) cout << "It is odd.\n";
  else even (x);
}

void even (int x) {
  if ((x%2) == 0) cout << "It is even.\n";
  else odd (x);
}

// In this case, atleast one funciton declaration is needed at the top
// as even () and odd () call eachother, thereby making it impossible for
// both to be declared and defined on top to allow for them
// to reference the other function. In this case, function declarations serve
// a useful purpose.