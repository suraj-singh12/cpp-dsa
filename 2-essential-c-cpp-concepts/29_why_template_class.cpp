#include <iostream>
using namespace std;

class Arithmetic
{
private:
    int a;
    int b;
public:
    Arithmetic(int a, int b);
    int add();
    int subtract();
};

Arithmetic::Arithmetic(int a, int b){
    this->a = a;
    this->b = b;
}
int Arithmetic::add(){
    int c; 
    c = a + b;
    return c;
}
int Arithmetic::subtract(){
    int c;
    c = a - b;
    return c;
}

int main()
{
    Arithmetic ar(5,10);
    cout << ar.add() << endl;
    cout << ar.subtract() << endl;
    return 0;

    /*
     * All went fine. Right?
     * But now suppose you need to have same functionality for float, and double data types.
     * Then what would you do?
     * you would need to write two more same class just with different data types
     * But that does not make much sence, its like whole code repeated 3 times just with different data types
     * so to help us in such situations Template classes come
     * A template class is transparent to data type, i.e. they work for any data type (even user defined data types)
     * we will write a generic class (template class)
     * and as we use different data types, the compiler would make a dedicated class for that data type by using our generic class for us
     * check file 29.2_template_class.cpp
     * */
}