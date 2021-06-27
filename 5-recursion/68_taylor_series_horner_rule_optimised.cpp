#include <iostream>
using namespace std;

double e(int x, int n)
{
    static double s=1;
    if(n==0)
        return s;
    s = 1 + x*s/n;
    return e(x,n-1);
}

double eI(int x, int n)     // iterative version
{
    double s = 1;
    for (;n>0;n--)
    {   s= 1 + x*s/n;  }
    return s;
}
int main()
{
    cout << e(4,25) << endl;
    cout << eI(4,25) << endl;
    return 0;
}