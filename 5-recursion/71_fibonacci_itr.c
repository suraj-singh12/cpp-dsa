// Fibonacci series is a series where every next term is the sum of previous two terms
// example: 0 1 1 2 3 5 8 13 21 ...

#include <stdio.h>

int fibo_itr(int n)     // time complexity: O(n)
{
    int sum=0, t1=0, t2=1;
    if(n<=1)
        return n;
    for(int i=2;i<=n;++i)
    {
        sum=t1+t2;
        t1=t2;
        t2=sum;
    }
    return sum;
}

int rfib(int n)     // time complexity: O(2^n)
{
    if(n<=1)
        return n;
    return rfib(n-2)+rfib(n-1);
}

// Warning !! the syntax below is compiler dependent; only works with GCC compiler
int F[100] = {[0 ... 99]=-1};
int optimised_mfib(int n)       // time complexity: O(n)
{
    if(n<=1)
    {
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==-1)
            F[n-2]=optimised_mfib(n-2);
        if(F[n-1]==-1)
            F[n-1]=optimised_mfib(n-1);
        F[n] = F[n-2] + F[n-1];
        return F[n];
    }
}
int main()
{
    int term;
    printf("Enter the term: ");
    scanf("%d",&term);

    printf("%d\n",fibo_itr(term));
    printf("%d\n",rfib(term));
    printf("%d\n",optimised_mfib(term));
    return 0;
}
