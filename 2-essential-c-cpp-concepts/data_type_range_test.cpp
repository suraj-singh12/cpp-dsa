#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // Formula : -2^(n-1) to 2^(n-1)-1      ; where n = no of bits the data type takes
    // so sizeof(dataType) returns no of bytes that data type takes, so we need to do sizeof(dataType)*8    as 1 byte = 8 bits
    cout << "\nThe range of int data type on your machine is : " 
         << pow(-2,(sizeof(int)*8)-1) << " to " << pow(2,(sizeof(int)*8)-1)-1 << endl; 
    
    cout << "\nThe size of a data type largely depends on the compiler, operating system, hardware and various things, but mainly compiler.\n";
    cout << "So your system might have an int of 4 bytes, but a primitive/old system or a system with some other compiler might have 2 bytes.\n";
    cout << "So in competitive programming we assume things to be at minimum level.\n";
    cout << "For eg, in the server (such as codechef, we have int of 2 bytes as the server is old machine)\n";
    cout << "So on codechef, the range of int data type will be : "
         << pow(-2,(2*8)-1) << " to " << pow(2,(2*8)-1)-1 << endl;
    cout << "\nWe need to take all these things in mind, to avoid data overflow in our programs.\n";

}