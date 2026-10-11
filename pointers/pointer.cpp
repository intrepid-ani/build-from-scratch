#include <iostream>
using namespace std;

void memoryAddress(int a, char b)
{
  cout << "Memory addresses" << endl;
  cout << "Memory address of a: " << &a << "\n";
  cout << "Memory address of b: " << (void *)&b << "\n"
       << endl;
}

void pointerDetails(int *pointer_a, char *pointer_b, int **double_p_a, char **double_p_b)
{
  cout << "Pointer variables: " << "\n";
  cout << pointer_a << " " << (void *)pointer_b << "\n";

  cout << double_p_a << " " << double_p_b << "\n"
       << endl;

  cout << "Dereferenced values" << endl;
  cout << "Dereferenced value of pointer_a: " << *pointer_a << endl;
  cout << "Dereferenced value of pointer_b: " << *pointer_b << endl;

  cout << "Dereferenced value of double_p_a: " << **double_p_a << endl;
  cout << "Dereferenced value of double_p_b: " << **double_p_b << endl
       << endl;
}

// Pass by refernce and it type
// 1. Refernced by pointer
void pointerRef(int *pointer_of_var = NULL, int **dpointer_of_var = NULL)
{
  if (pointer_of_var != NULL)
  {
    cout << "In pointerRef(), I'm changing the value to 20." << endl;
    *(pointer_of_var) = 20;
  }
  if (dpointer_of_var != NULL)
  {
    cout << "In pointerRef(), I'm changing the value to 30.\n"
         << endl;
    **(dpointer_of_var) = 30;
  }
}

// 2. Referenced by memory address
void memoryAddRef(int &a)
{
  cout << "In memeoryAddRef(): changing value to 50, \n\n";
  a = 50;
}

int main()
{
  int a = 10;
  char b = 'b';

  memoryAddress(a, b);

  int *pointer_a = &a;
  char *pointer_b = &b;

  int **double_p_a = &pointer_a;
  char **double_p_b = &pointer_b;

  pointerDetails(pointer_a, pointer_b, double_p_a, double_p_b);

  pointerRef(pointer_a, double_p_a);
  cout << "In main(), Changed value of 'a' by pointerRef is: " << a << endl
       << endl;

  memoryAddRef(a);
  cout << "In main(), Changed value of 'a' by memoryAddRef is: " << a << endl
       << endl;

  return 0;
}