#include <iostream>
using namespace std;

//--------------------------------------
int fact(int n)
{
    if (n==0)
        return 1;
    return n*fact(n-1);
}

int ncr(int n, int r)   // non recursive
{
    int num = fact(n);
    int denom = fact(n-r) * fact(r);
    return num/denom;
}
//--------------------------------------
//--------------------------------------
int NCR(int n, int r)   // recursive 
{
    if(r==0 || n==r)
        return 1;
    return NCR(n-1,r-1)+NCR(n-1,r);
}
//--------------------------------------

int main()
{
    cout << ncr(5,2) << endl;
    cout << NCR(5,2) << endl;
}