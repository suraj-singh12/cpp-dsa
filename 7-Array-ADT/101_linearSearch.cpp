#include <iostream>
using namespace std;

struct Array{
    int A[20];
    int len;
    int size;
};

void swap(int &n1, int &n2){
    n1=n1+n2;
    n2=n1-n2;
    n1=n1-n2;
}
int linearSearch(Array &arr, int key){
    for(int i=0;i<arr.len;++i){
        if(key==arr.A[i]){
            //Transposition
            // swap(arr.A[i],arr.A[i-1]);               
            // return i-1;
            
            // Move to head/front
            swap(arr.A[i],arr.A[0]);                  //move to head
            return 0;
        }
    }
    return -1;
}

int main()
{
    Array arr = {{1,2,3,4,8,6,7,5,0},9,10};
    int key = 5;
    char ch;
    
    do{
        int res = linearSearch(arr, key);
        if(res==-1)
            cout << "The key " << key << " is not found.\n";
        else 
            cout << key << " is found at index: " << res << '\n';
        
        cout << "Continue?(y/n)";
        cin >> ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}