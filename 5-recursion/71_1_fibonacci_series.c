#include <stdio.h>

void fib_itr(int n)
{
    int t1=0,t2=1,sum=0;
    for(int i=0;i<n;++i)
    {
        sum = t1+t2;
        t1=t2;
        t2=sum;
        printf("%d ",sum);
    }
}

int F[100]={[0 ... 99]=-1};
int fib(int n)
{
    if (n<=1){
        F[n] = n;
        // printf("%d ",F[n]);
        return n;
    }
    else{
        if(F[n-2]==-1)
            F[n-2] = fib(n-2);
        if(F[n-1]==-1)
            F[n-1] = fib(n-1);
        F[n] = F[n-1]+F[n-2];
        // printf("%d ",F[n]);
        return F[n];
    }
}

int main()
{
    int terms;
    printf("Enter the number of terms: ");
    scanf("%d",&terms);
    
    fib_itr(terms);

    // {
    //     fib(terms);
    //     for(int i=0;i<=terms;++i){
    //         printf("%d ",F[i]);
    //     }
    // }
    
    printf("\n");
    return 0;
}