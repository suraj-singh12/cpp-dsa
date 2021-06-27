// Exponential using recursion 
#include <iostream>
using namespace std;

int pow(int m, int n)
{
    if(n==0)
        return 1;
    return pow(m,n-1)*m;
}

// More efficient and faster than pow(m,n) function
int pow2(int m, int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return pow(m*m,n/2);
    return m*pow(m*m,(n-1)/2);
}

int main()
{
    int num, power;
    cin >> num >> power;
    cout << pow(num,power) << endl;
    cout << pow2(num,power) << endl;
    return 0;
}