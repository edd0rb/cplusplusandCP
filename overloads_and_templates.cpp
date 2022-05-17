#include <iostream>
using namespace std;

// e.g.1 In C++, 2 functions can have the same name as long as their
// parameters or any parmatere types are different. It's recommended that
// the functionality be similar or the same if functions are overloaded
// (named the same thing), but it can be completely different If you want.

int operate (int a, int b) 
{
  return (a * b);
}

double operate (double a, double b) 
{
  // return (a/b); - This is an example of bad practice as the functionality
  // is completely different. However, it is completely valid code.
  return (a * b);
}

// e.g.2 Instead of overloading functions with different parameter types, 
// we can use function templates to have a generic modifiable type for 
// each parameter.

// Basic syntax:
// template <template-parameters> function-declaration
// the template-parameters are seperated by commas and represent generic
// types specifying either the class or typename followed by an identifier.
// This identifier can be used in the function declaration as if it was a
// regular type.

template <class someType>
someType sum (someType a, someType b)
{
  return a + b;
}

// In this context, class and typename are 100% synonyms.
// someType represents a generic type that will be determined on the moment
// the template is instantiated.

// Instantiating a template is applying the template to create a function 
// using particular types or values for its template parameters. 

// Basic syntax:
// name <template-arguments> (function-arguments)

// e.g.2.1 below

// lets see an actual example - e.g.2.2

template <class T>
T sum2 (T a, T b)
{
  T result;
  result = a + b;
  return result;
}

// e.g.2.3

template <class T, class U>
bool are_equal (T a, U b)
{
  return (a == b);
}

// e.g.3 The template parameters can not only include types introduced by
// class or typename, but can also include expressions of a particular type:

template <class T, int N>
T fixed_multiply (T val)
{
  return val * N;
}

// One major difference between this and an ordinary function parameter is
// that only constants can be passed into it, and it's done during compile time.
// Therefore, calls to fixed_multiply in main essentially call differen 
// versions of the same function. These versions maintain whatever N value
// was put in them at comple, that is why variables are not allowed.

int main ()
{
  // e.g.1

  int x=5, y=6;
  double n=5, m=6.3;
  cout << operate (x,y) << '\n';
  cout << operate (n,m) << '\n';
  
  // above code returns 
  // 30
  // 31.5

  // e.g.2.1

  x = sum<int>(10,20);

  // The function sum<int> is one of the many possible instantiations of
  // function template sum (). In this case, by using int as template-arguemnt,
  // the compiler automatically instantiates a version of sum where each 
  // occurrence of SomeType is replaced by int. As if it were defined as:

  // int sum (int a, int b)
  // {
  //    return a + b;
  // }

  // e.g.2.2
  
  int i=5, j=6, k;
  double f=2.0, g=0.5, h;
  k=sum2<int>(i,j);
  h=sum2<double>(f,g);
  cout << k << '\n';
  cout << h << '\n';

  // In this case there is no need to make two seperate functions since
  // we have one template function for which we can specify the types of
  // input parameters.

  // e.g.2.3

  if (are_equal(10,10.0))
    cout << "x and y are equal\n";
  else
    cout << "x and y are not equal\n";

  // Note that this example uses automatic parameter deduction in the call
  // to are_equal():
  // are_equal(10,10.0)
  // This would have been equivalent to:
  // are_equal<int,double>(10,10.0)
  // Since literals always have a specific, this does not create ambiguity.

  // e.g.3

  std::cout << fixed_multiply<int,2>(10) << '\n';
  std::cout << fixed_multiply<int,3>(10) << '\n';

  // output: 
  // 20
  // 30

  return 0;
}