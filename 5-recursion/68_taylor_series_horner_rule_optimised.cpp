/*
 * Taylor Series
 * e^x = 1 + x/1! + x^2/2! + x^3/3! + ------- + n terms
 * This is optimised version, with time complexity O(n) using Horner's rule
 * This basically works by simplifying things, by taking common in eqn
 * Take a copy pen and simplify
 * */

#include <iostream>
using namespace std;

double e(int x, int n)
{
    static double s=1;
    if(n==0)
        return s;
    s = 1 + (x/float(n))*s;
    return e(x,n-1);
}

double eI(int x, int n)     // iterative version
{
    double s = 1;
    for (;n>0;n--)
    {   s= 1 + (x/float(n))*s;  }
    return s;
}
int main()
{
    cout << e(4,25) << endl;
    cout << eI(4,25) << endl;
    return 0;
}