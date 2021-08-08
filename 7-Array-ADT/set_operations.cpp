#include <iostream>
using namespace std;

struct Array{
    int A[20];
    int length;
    int size;
};

void display(const Array *arr){
    for(int i=0;i<arr->length;i++){
        cout << arr->A[i] << " ";
    }
    cout << "\n";
    delete []arr;
    arr=NULL;
}
bool Lsearch(Array *arr, int elem){
    for(int i=0;i<arr->length;++i){
        if(arr->A[i]==elem)
            return true;
    }
    return false;
}
// bool Bsearch(Array *arr, int elem){
//     int l=0,h=arr->length-1;
//     int mid;
//     while(l<=h){
//         mid = (l+h)/2;
//         if(arr->A[mid]==elem)
//             return true;
//         else if(elem < arr->A[mid])
//             h=mid-1;
//         else   
//             l=mid+1;
//     }
//     return false;
// }

// Time complexity: O(n^2)
Array* unsortedArrayUnion(Array *arr1, Array *arr2){
    Array *arr=new Array;       // again you forgot it man!!, 
    // you know you need to have an object placed in memory in order to use that object; pointer just stores an address
    // object should also be there, otherwise what are you pointing at??
    arr->length=0;
    arr->size = arr1->size + arr2->size;
    // first copy first array
    for(int i=0;i<arr1->length;++i){
        arr->A[i]=arr1->A[i];
        arr->length++;
    }
    // now check if elem is not there in our arr, only then copy the arr2's elem, else don't
    for(int i=0;i<arr2->length;++i){
        if(!Lsearch(arr,arr2->A[i])){
            arr->A[arr->length]=arr2->A[i];
            arr->length++;
        }
    }
    return arr;
}
// Time complexity: O(n)
Array* sortedArrayUnion(Array *arr1, Array *arr2){
   Array *arr = new Array;
   arr->length=0;
   arr->size=arr1->size+arr2->size;

   int i=0,j=0,k=0;
   while(i<arr1->length && j<arr2->length){
       if(arr1->A[i] < arr2->A[j]){
           arr->A[k++]=arr1->A[i++];
           arr->length++;
       }
       else if(arr2->A[j] < arr1->A[i]){
           arr->A[k++]=arr2->A[j++];
           arr->length++;
       }
       else{
           arr->A[k++]=arr1->A[i++];
           j++;
           arr->length++;
       }
   }
   for(;i<arr1->length;++i){
        arr->A[k++]=arr1->A[i];
        arr->length++;
   }
   for(;j<arr2->length;++j){
       arr->A[k++]=arr2->A[j];
       arr->length++;
   }
   return arr;
}

// Time complexity: O(n^2)
Array* unsortedArrayIntersection(Array *arr1, Array *arr2){
    Array *arr = new Array;
    arr->length = 0;
    arr->size = arr1->size + arr2->size;

    int i=0, k=0;
    while(i<arr1->length){
        bool isPresent = Lsearch(arr2,arr1->A[i]);
        if(isPresent){
            arr->A[k++]=arr1->A[i];
            arr->length++;
        }
        i++;
    }
    return arr;
}
// Time complexity: O(n)
Array* sortedArrayIntersection(Array *arr1, Array *arr2){
    Array *arr = new Array;
    arr->length=0;
    arr->size = arr1->size + arr2->size;

    int i=0,j=0,k=0;
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr1->A[i] > arr2->A[j])
            j++;
        else{
            arr->A[k++]=arr1->A[i++];
            j++;    arr->length++;
        }
    }
    return arr;
}

// Time complexity: O(n^2)
Array* unsortedArrayDifference(Array *arr1, Array *arr2){
    Array *arr = new Array;
    arr->length=0;      int k=0;
    arr->size = arr1->size + arr2->size;

    for(int i=0;i<arr1->length;++i){
        bool isPresent = Lsearch(arr2,arr1->A[i]);
        // if not present, include in arr else don't
        if(!isPresent){
            arr->A[k++]=arr1->A[i];
            arr->length++;
        }
    }
    return arr;
}
// Time complexity: O(n)
Array* sortedArrayDifference(Array *arr1, Array *arr2){
    Array *arr = new Array;
    arr->length=0;
    arr->size = arr1->size + arr2->size;
    int i=0,j=0,k=0;

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr->A[k++]=arr1->A[i++];
            arr->length++;
        }
        else if(arr1->A[i] > arr2->A[j])
            j++;
        else{
            // when they are equal
            i++;    j++;
        }
    }
    for(;i<arr1->length;++i){
        arr->A[k++]=arr1->A[i];
        arr->length++;
    }
    return arr;
}

int main()
{
    // unsorted
    Array arr1={{1,2,3,4,5,6,7},7,10};
    Array arr2={{1,8,5,9,7},5,10};
    Array *arr3;
    
    // arr3 = unsortedArrayUnion(&arr1, &arr2);
    // display(arr3);
    
    // sorted
    Array arr4={{1,2,3,4,5},5,10};
    Array arr5={{3,5,7,8,9,11,12},7,10};
    
    // arr3 = sortedArrayUnion(&arr4,&arr5);
    // display(arr3);

    // arr3=unsortedArrayIntersection(&arr1,&arr2);
    // display(arr3);

    // arr3=sortedArrayIntersection(&arr4,&arr5);
    // display(arr3);
    
    // arr3=unsortedArrayDifference(&arr1,&arr2);
    // display(arr3);

    arr3=sortedArrayDifference(&arr4,&arr5);
    display(arr3);
    return 0;
}