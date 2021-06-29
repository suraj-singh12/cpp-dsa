#include <iostream>
using namespace std;

int main()
{
    // all in stack
    int A[3][4] = { {1,2,3,4},
                    {2,4,6,8},
                    {1,3,5,7}
                };
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // partial in stack partial in heap
    int *B[3];      // in stack
    // in heap
    B[0]=new int[4];
    B[1]=new int[4];
    B[2]=new int[4];
    
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    // all in heap
    int **c;
    c=new int*[3];
    c[0]=new int[4];
    c[1]=new int[4];
    c[2]=new int[4];
    
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

/* C equivalent

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // all in stack
    int A[3][4] = { {1,2,3,4},
                    {2,4,6,8},
                    {1,3,5,7}
                };
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // partial in stack partial in heap
    int *B[3];      // in stack
    // in heap
    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));
    
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // all in heap
    int **c;
    c=(int **)malloc(3*sizeof(int*));
    c[0]=(int *)malloc(4*sizeof(int));
    c[1]=(int *)malloc(4*sizeof(int));
    c[2]=(int *)malloc(4*sizeof(int));
    
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

*/