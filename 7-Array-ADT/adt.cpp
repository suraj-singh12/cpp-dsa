#include <iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int len;
};

void swapElem(int *n, int *m){
    int temp = *n;
    *n = *m;
    *m = temp;
}

void displayData(const Array *arr)
{
    for(int i=0;i<arr->len;++i){
        cout << arr->A[i] << " ";
    }
    cout << endl;
}
void fillData(Array *arr)
{
    cout << "Enter " << arr->len << " space seperated integers: ";
    for(int i=0;i<arr->len; ++i){
        cin >> arr->A[i];
    }
}
void insertData(Array *arr, int elem, int index)
{
    if((index>=0 && index<= arr->len) && arr->len < arr->size)
    {
        for(int i=arr->len; i>index; i){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=elem;
        arr->len++;
    }
    else{
        cout << "Ops!!, invalid input.\n";
    }
}
void appendData(Array *arr, int elem)
{
    if(arr->len < arr->size){
        arr->A[arr->len++]=elem;
    }
    else{
        cout << "Array is full !!\n";
    }
}
int deleteData(Array *arr, int index)
{
    if((index >= 0 && index <= arr->len-1) && (arr->len >= 1)){
        int x=arr->A[index];
        
        for(int i=index ; i<arr->len-1 ; ++i){
            arr->A[i]=arr->A[i+1];
        }
        arr->len--;
        return x;
    }
    else{
        cout << "Array is already empty!!\n";
    }
    return 0;
}

void insertSorted(Array *arr, int elem){
    if(arr->len < arr->size){
        int i=arr->len-1;
        while(i>0 && arr->A[i]>elem){
            arr->A[i+1] = arr->A[i];
            i--;
        }
        arr->A[i+1]=elem;
    }
    else{
        cout << "Error!!, there is no more space in array!";
        return;
    }
}

bool isSorted(const Array *arr){
    for(int i=0;i<arr->len-1;++i){
        if(arr->A[i]>arr->A[i+1])
            return false;
    }
    return true;
}

void ReArrange(Array *arr){
    int i=0;
    int j=arr->len -1;
    while(i<j){
        while(arr->A[i]<0)   i++;
        while(arr->A[j]>=0) j--;
        if(i<j)
            swapElem(&arr->A[i],&arr->A[j]);
    }
}

Array* merge(Array *arr1, Array *arr2){
    int i=0,j=0,k=0;
    Array *arr3 = new Array;        // this ate my 10 minutes; (see it's one pointer object, 
    //so you need to allocate memory like this; for one only; that to for the reason that we will return it's address to the caller function, 
    //so it needs to exist dynamically, otherwise we send a dangling pointer; see practise.cpp for more understanding)
    
    // Array *arr3 = new Array[arr1->size + arr2->size];   this does not make sence, you understood!!
    arr3->size = arr1->size+arr2->size;
    // now see, you need to dynamically allocate memory for the array A that this pointer object contains inside
    arr3->A = new int[arr3->size];

    while(i < arr1->len && j < arr2->len){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->len;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->len;++j)
        arr3->A[k++] = arr2->A[j];
        
    arr3->len = arr1->len + arr2->len;
    return arr3;
}

int main()
{
    Array arr1, arr2;
    arr1.A = new int[5] {};
    arr1.len = 5;
    arr1.size = 5;
    arr2.A = new int[5] {};
    arr2.len = 5;
    arr2.size = 5;
    for(int i=0;i<arr1.len;++i){
        arr1.A[i] = (i+1)*2;
        arr2.A[i] = (i+1)*3;
    }

    Array *arr3 = merge(&arr1,&arr2);
    displayData(arr3);
    cout << arr3->len << " " << arr3->size << endl;
    return 0;
}

// int main()
// {
//     Array arr;
//     int len, sz;
//     cout << "Enter the size of the array: ";
//     cin >> sz;

//     arr.size = sz;
//     arr.A = (int *)malloc(arr.size*sizeof(int));

//     cout << "Enter lenght of array: ";
//     cin >> len;
//     while(len>sz){
//         cout << "Ops!!, invalid input.";
//         cout << "Enter the length of the array (len<=size): ";
//         cin >> len;
//     }

//     arr.len=len;
//     fillData(&arr);
//     displayData(&arr);
//     int indx;
//     cout << "Enter the index of the element to be deleted: ";
//     cin >> indx;
//     cout << deleteData(&arr, indx) << endl;
//     cout << "After deleting element at index : " << indx << endl; 
//     displayData(&arr);
//     return 0;
// }