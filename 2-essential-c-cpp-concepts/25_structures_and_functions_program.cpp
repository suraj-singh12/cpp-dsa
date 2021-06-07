#include <stdio.h>

struct Rectangle{
    int length;
    int breadth;
};

void initialise(struct Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}

int area(const struct Rectangle *r){
    return r->length*r->breadth;
}
int perimeter(const struct Rectangle *r){
    return 2*(r->length+r->breadth);
}
int main()
{
    Rectangle r;
    int length = 0, breadth = 0;
    printf("Enter length and breadth of rectangle: ");
    scanf("%d%d",&length,&breadth);

    initialise(&r,length,breadth);
    int ar = area(&r);
    int peri = perimeter(&r);

    printf("Area : %d \t Perimeter  : %d\n",ar,peri);
    return 0;

}