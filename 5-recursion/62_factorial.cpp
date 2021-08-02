#include <iostream>
using namespace std;

int fact(int n)     // recursive version
{
    if(n==0)
        return 1;
    return fact(n-1)*n;
}
int Ifact(int n)        // iterative version 
{
    int fact = 1;
    for(int i=n;i>0;i--)
    {        fact *= i;     }
    return fact;
}

int main()
{
    int num = 5;
    cout << fact(num) << endl;
    cout << Ifact(num) << endl;
    return 0;
}