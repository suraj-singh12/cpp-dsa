// HOW TO FIX : warning: address of local variable ‘A’ returned [-Wreturn-local-addr]

#include <iostream>
using namespace std;

int* func(){
    int A[5]={1,2,3,4,5};
    return A;
}
int main()
{
    int *arr = func();
    return 0;
}
/* 
 * warning: address of local variable ‘A’ returned [-Wreturn-local-addr]
 * solution for this:
 *                  1. make the array static; 
 *                      static int A[5]={1,2,3,4,5};
 *                  2. declare the array on heap; 
 *                      int *A = int [5] {1,2,3,4,5};
 *                      (but then don't forget to delete this when its no more in use)
 * */

/* 
 * int A[5] is an array with automatic storage duration. 
   Memory where it resides is deallocated once the execution goes out of the scope of your function, thus pointer to this memory that you return becomes invalid (dangling pointer).
   Trying to access memory, that has already been deallocated, results in undefined behaviour.

 * static variables are those which live in memory untill the program ends.
 * and variables that are allocated memory on heap live untill they are deleted by the programmer manually.
 * 
 * so when our function returns the address of a variable which is static 
 * or which is present on heap, then we can easily access that, and no error is generated.
 * */