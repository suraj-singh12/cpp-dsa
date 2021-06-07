#include <iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    public:
    // overloaded constructors
    Rectangle(){
        length = breadth = 1;
    }
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }

    //Facilitators
    int area();
    int perimeter();

    // Accessors or getters
    int getLength();

    // Mutators or setters
    void setLength(int );

    // Destructor
    ~Rectangle(){
        
    }
};

int Rectangle::area(){
    return length*breadth;
}
int Rectangle::perimeter(){
    return 2*(length + breadth);
}
int Rectangle::getLength(){
    return length;
}
void Rectangle::setLength(int l){
    length = l;
}

int main()
{
    Rectangle r(10,5);
    cout << r.area() << endl;
    cout << r.perimeter() << endl;
    r.setLength(20);
    cout << r.getLength() << endl;
    return 0;
}