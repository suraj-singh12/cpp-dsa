// sine series
// sin(x) = x - x^3/3! + x^5/5! - x^7/7! + .......
// sin(2,4) = 0.907937
// in above 2 is x and 4 is number of terms

#include <iostream>
using namespace std;
#define last_term_power  (2*n-1)    // 2n-1 did so that series knows right power
                                    // like n = 4, so four terms of series go to x^7  2*4 - 1 = 7
#define radian (degree*0.017)   // (3.142 / 180.0)= 0.017 (taking only this much)

double sin(float x, int n)     // double x; as x may be a floating point value like 30*3.142/180) radian is in fraction
{
    static double p=1,f=1;
    static int sign = 1;
    double result;
    if(n==1)
    {
        p*=x;
        return x;
    }
    else{
       result = sin(x,n-2);
       p*=x*x;
       f*=n*(n-1);
       sign *= -1;
       return (result+(sign*(p/f))); 
    }
}

int main()
{
    int degree=30,n=20;    // n = number of terms
    cout << sin(radian,last_term_power) << endl; 
    degree=45, n = 5;
    cout << sin(radian,last_term_power) << endl;
    degree=60, n = 5;
    cout << sin(radian,last_term_power) << endl;
    degree=90, n = 5;
    cout << sin(radian,last_term_power) << endl;
    degree=180, n = 5; 
    cout << sin(radian,last_term_power) << endl;
    return 0;
}