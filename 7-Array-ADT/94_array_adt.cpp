#include <iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};


void display(const Array &arr)
{
    cout << "\nThe elements of the array are: " << endl;
    for(int i=0;i<arr.length;++i){
        cout << arr.A[i] << " ";
    }
    cout << endl;
}
void append(Array *arr,int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]= x;
    }
    else{
        cout << "Error!! cannot append. Array is already full.";
    }
}

void insert(Array *arr, int index, int x){
    if(arr->length < arr->size && (index>=0 && index<=arr->length)){
        for(int i=arr->length;i>index;--i){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
    else{
        cout << "Insertion Not Possible\nCheck if the index is less than array size and the array is not full.\n";
    }
}
int main()
{
    Array arr;
    int sz, len;
    
    cout << "Enter the size of the array: ";
    cin >> sz;
    cout << "Enter the length of the array: ";
    cin >> len;
    arr.size = sz;

    arr.A = (int *)malloc(arr.size*sizeof(int));

    cout << "Enter " << len << " space seperated integers: ";
    for(int i=0;i<len;++i){
        cin >> arr.A[i];
    }
    arr.length=len;

    display(arr);

    append(&arr,10);
    cout << "After appending 10 \n";
    display(arr);

    insert(&arr, 50,2);
    display(arr);

}