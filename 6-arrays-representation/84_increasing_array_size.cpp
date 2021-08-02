#include <iostream>
using namespace std;

int main()
{
    int *p,*q;
    // first array
    p=(int *)malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        *(p+i) = i*2;
    }

    q=(int *)malloc(10*sizeof(int));
    // copy array pointed to by *p into array pointed to by *q 
    // (that's how we increase size, by copying the content of small array into another big array)
    for(int i=0;i<5;++i){
        q[i] = p[i];
    }

    // elements in *p
    printf("In array pointed to by *q\n");
    for(int i=0;i<5;++i){
        printf("%d ",p[i]);
    }
    printf("\n");

    free(p);
    p=q;
    q=NULL;
    printf("Array size extended\n");
    for(int i=0;i<5;++i){
        printf("%d ",p[i]);
    }
    printf("\n");
    return 0;
}