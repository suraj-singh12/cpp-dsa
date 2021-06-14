#include <iostream>
using namespace std;

void fun(int n){
    if(n>0)
    {
        cout << n;
        fun(n-1);
    }
}

int main()
{
    int x=3;
    fun(x);
    return 0;
}

/*
fun(int n) (\home\suraj\Documents\udemy-cpp-dsa\5-recursion\5_1_tail_head.cpp:10)
fun(int n) (\home\suraj\Documents\udemy-cpp-dsa\5-recursion\5_1_tail_head.cpp:8)
fun(int n) (\home\suraj\Documents\udemy-cpp-dsa\5-recursion\5_1_tail_head.cpp:8)
fun(int n) (\home\suraj\Documents\udemy-cpp-dsa\5-recursion\5_1_tail_head.cpp:8)
main() (\home\suraj\Documents\udemy-cpp-dsa\5-recursion\5_1_tail_head.cpp:15)
*/