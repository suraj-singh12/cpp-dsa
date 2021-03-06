#include <iostream>
using namespace std;

void TOH(int n,int A, int B, int C)
{
    if(n>0)     // if number of rings in tower is >0
    {
        TOH(n-1,A,C,B);     // shift from tower A->B
        // printf("from %d to %d \n",A,C);
        printf("(%d,%d) ",A,C);
        TOH(n-1,B,A,C);     // shift from tower B->C
    }
}
int main()
{
    int n;
    int A=1, B=2, C=3;      // towers
    cout << "Enter the no of rings in tower: ";
    cin >> n;

    TOH(n,A,B,C);
    printf("\n");
    return 0;
}