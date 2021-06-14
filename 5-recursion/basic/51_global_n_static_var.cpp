#include<iostream>
using namespace std;

int x = 0;

int fun2(int n)
{
    // static int x = 0;
    if(n>0)
    {
        x++;
        return fun2(n-1) + x;
    }
    return 0;
}
int main()
{
    int a = 5;
    cout << fun2(a) << endl;
    cout << fun2(a) << endl;
    return 0;
}