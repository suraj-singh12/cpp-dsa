// This is the highest level of code that can be written in C
// as it is similar to Object oriented programming
// there is an object (of Rectangle struct) and remaining all are its functions/behaviors/methods
// OOPs is not in C, but is in c++
#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};
//-----------------------------------------------------------------------
void initialise(struct Rectangle *r1, int l, int b){
    r1->length = l;
    r1->breadth = b;
}
// float area(struct Rectangle r1){
//     return r1.length*r1.breadth;
// }

// a better way, this one will save us from copying the struct and still not allow us to make any modification to original object
float area(const struct Rectangle *r1){ // now *r1 supposes that the value it is pointing to is a constant value, so we cannot make any change to that using this pointer
    return (r1->length)*(r1->breadth);
}
void changeLength(struct Rectangle *r1,int l){
    r1->length = l;
}
//-----------------------------------------------------------------------
int main(){
    struct Rectangle r;
    
    initialise(&r,10,5);
    float area_is = area(&r);
    changeLength(&r,20);
    return 0;
}