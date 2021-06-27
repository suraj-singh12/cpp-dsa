#include <iostream>
using namespace std;

int sum(int n)      // recursive function
{
    if(n==0)
        return n;
    return sum(n-1)+n;
}
// Time complexity : O(n)
// Space Complexity : O(n)

int Isum(int n)     // iterative function
{
    int i,sum=0;
    for(i=1;i<=n;++i)
    {
        sum += i;
    }
    return sum;
}
// Time complexity : O(n)
// Space Complexity : O(1)

int Fsum(int n)     // direct forumula
{
    return n*(n+1)/2;
}
// Time complexity : O(1)
// Space Complexity : O(1)

int main()
{
    int input = 5;
    cout << sum(input) << endl;
    cout << Isum(input) << endl;
    cout << Fsum(input) << endl;
}
