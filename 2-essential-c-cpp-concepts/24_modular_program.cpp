#include <stdio.h>

int area(int l, int b){
    return l*b;
}
int perimeter(int l, int b){
    int p = 2*(l+b);
    return p;
}

int main()
{
    int length = 0, breadth = 0;
    printf("Enter length and breadth : ");
    scanf("%d%d",&length,&breadth);

    int ar = area(length,breadth);
    int peri = perimeter(length,breadth);

    printf("Area : %d \t Perimeter : %d\n",ar,peri);
    return 0;
}