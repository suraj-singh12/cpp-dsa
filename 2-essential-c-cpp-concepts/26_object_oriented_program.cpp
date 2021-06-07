// A structure can have member functions inside it, this fuctionality is given by c++, it is not available in C language
// Packing data and their associated functions within a single unit allows the implementation of Object oriented programming.

// NOTE: a struct is public but a class is private by default. so class implements better security using access specifiers (private, public, protected)
// NOTE: class are still far more better than struct, because struct does not have constructor/destructor and type of functionality.
// When you have a choice always go for class.
#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;

    void initialise(int l, int b){
        length = l;
        breadth = b;
    }
    int area(){
        return length*breadth;
    }
    int perimeter(){
        return 2*(length+breadth);
    }
};

int main()
{
    Rectangle r;

    int length=0 , breadth=0;
    cout << "Enter length and breadth : ";
    cin >> length >> breadth;

    r.initialise(length, breadth);
    int ar = r.area();
    int peri = r.perimeter();

    cout << "Area : " << ar << "\t Perimeter : " << peri << endl;
    return 0;
}