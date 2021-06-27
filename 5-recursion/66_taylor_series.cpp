#include <iostream>
using namespace std;

double e(int x, int n)
{
    static double p=1,f=1;
    double result;
    if(n==0)
        return 1;
    else{
        result = e(x,n-1);
        p*=x;    f*=n;
        return (result + p/f);
    }
}
int main()
{
    int x=4,n=25;
    cout << e(x,n) << endl;
    return 0;
}