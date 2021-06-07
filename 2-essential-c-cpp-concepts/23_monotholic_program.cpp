#include <iostream>
using namespace std;

int main()
{
    int lenght = 0, breadth = 0;
    cout << "Enter the length and breadth: ";
    cin >> lenght >> breadth;

    int area = lenght*breadth;
    int perimeter = 2*(lenght+breadth);

    printf("Area : %d \t Perimeter : %d\n",area,perimeter);
    return 0;
}