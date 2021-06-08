#include <iostream>
#include <string>
using namespace std;

//observe the syntax

template<class T>
class Arithmetic
{
private:
    T a;
    T b;
public:
    Arithmetic(T a, T b);
    T add();
    T subtract();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b){
    this->a = a;
    this->b = b;
}

template<class T>
T Arithmetic<T>::add(){         //observe the syntax
    T c;
    c = a + b;
    return c;
}

template<class T>
T Arithmetic<T>::subtract(){
    T c;
    c = a - b;
    return c;
}

int main()
{
    Arithmetic <int> ar(5,10);  // observe the syntax
    cout << ar.add() << endl;
    cout << ar.subtract() << endl;

    Arithmetic <float> af(5.8,10.5);
    cout << af.add() << endl;
    cout << af.subtract() << endl;

    Arithmetic <unsigned char> ac('B','A');
    cout << (int)ac.add() << endl;
    cout << (int)ac.subtract() << endl;
    // about cout are printing the ascii codes of the characters returned by the functions

    Arithmetic <string> as("Hello", " World");
    cout << as.add() << endl;
    //cout << as.subtract;    // this will not work here, because we can add two strings(concatenation) but subtraction does not make any sense
    return 0;
}