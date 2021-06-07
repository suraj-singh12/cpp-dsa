#include <iostream>
#include <stdio.h>
using namespace std;
//----------------------------------------------------------------------------------------------
struct Rectangle{
    int length;
    int breadth;
};

void fun_by_value(Rectangle r1){
    r1.length = 20;
    r1.breadth = 10;
    cout << "In fun_by_value() \n";
    cout << "Length " << r1.length << endl << "Breadth " << r1.breadth << endl;
}

// NOTE: This function uses Call by reference mechanism; it will not work in C because call by reference is a C++ feature and is not available in c
void fun_by_reference(Rectangle &r1){
    r1.length = 30;
    r1.breadth = 20;
    cout << "In fun_by_reference() \n";
    cout << "Length " << r1.length << endl << "Breadth " << r1.breadth << endl;
}

void fun_by_address(Rectangle *r1){
    r1->length = 40;
    r1->breadth = 30;
    cout << "In fun_by_address() \n";
    cout << "Length " << r1->length << endl << "Breadth " << r1->breadth << endl;
}
//----------------------------------------------------------------------------------------------

struct Rectangle2{
    int length[5];
    int breadth[5];
};

void fun2_by_value(Rectangle2 r2){
    cout << "sizeof object r2 : " << sizeof(r2) << endl;
    /* you will see the size here also would be same as in main( i.e. 40)
       It means the both array of length and breadth
       has been copied in this call 
       (copied; as the object is copied as it is)

       otherwise what happens is whenever we pass an array by value, 
       then to it is not copied, because for arrays there is no such thing as call by value
       arrays are always passed by address

       But if there's an array in a structure or a class it will get copied when 
       the object of that struct or class is used in call by value mechanism like here
    */
}

void fun3(int l[],int size){
    cout << "sizeof array l[] : " << sizeof(l) << endl;
    /* here output will be 8
       why? because arrays are always passed by address,
       so int l[] here is equivalent to int *l
       so l is a pointer
       therefore, this 8 (output) is the sizeof(int *)
       i.e. sizeof a pointer
       */
}
//----------------------------------------------------------------------------------------------

struct Rectangle *fun(){
    struct Rectangle *r = new Rectangle;      
    /* see *r is a pointer, new is allocating a new room/memory in heap to Rectangle type *r pointer (creating a room for a Rectangle type obj and assigning its memory location to pointer *r)
    (remember: memory allocated on heap is nameless, we can access it only with the help of the pointer attached to it/pointing to it   */

    // struct Rectangle *r = (struct Rectangle *)malloc(sizeof(struct Rectangle));      //C style
    r->length = 15;
    r->breadth = 10;
    return r;       // returning the pointer
}

//----------------------------------------------------------------------------------------------
int main()
{
    //----------------------------------------------------------------------------------------------

    struct Rectangle r {10,5};
    cout << "Original :  " << endl;
    printf("-----------------------------------------------\n");
    printf("Length %d \t Breadth %d\n",r.length,r.breadth);
    printf("-----------------------------------------------\n\n");

    fun_by_value(r);
    printf("In main() After calling fun_by_value(Rectangle)\n");
    printf("Length %d \t Breadth %d\n\n",r.length,r.breadth);

    fun_by_reference(r);
    printf("In main() After calling fun_by_reference(Rectangle &)\n");
    printf("Length %d \t Breadth %d\n\n",r.length,r.breadth);

    fun_by_address(&r);
    printf("In main() After calling fun_by_address()\n");
    printf("Length %d \t Breadth %d\n\n",r.length,r.breadth);
    
    //----------------------------------------------------------------------------------------------

    struct Rectangle2 rr {{0},{0}};     // will assign all the values of length array a value 0, and all the values of breadth as zero
    /*   Equivalent to
    struct Rectangle2 rr { {0,0,0,0,0},
                                {0,0,0,0,0}}
    */

   printf("sizeof object rr : %ld\n",sizeof(rr));
   fun2_by_value(rr);

   int len[5] {0};      // array len is of size 5*4(int) = 20
   fun3(len,5);

    //----------------------------------------------------------------------------------------------

    //Everything on heap now, above all was on stack
    //Below code shows Returning a pointer to an object created on heap
    cout << "\n\nOf object created on heap: \n";
    struct Rectangle *ptr = fun();      //calling fun() and storing the returned memory address in *ptr
    cout << "Length = " << ptr->length << "\tBreadth = " << ptr->breadth << endl;

    delete ptr;     // free the memory allocated on heap (thereby ensuring no memory leak happens)
    ptr = NULL;     // ensuring ptr does not become a dangling pointer
    /* What is a dangling pointer?
       A pointer pointing to a memory location/address which has been deleted is called a dangling pointer
    */
   return 0; 


}