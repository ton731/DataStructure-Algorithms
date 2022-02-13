#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    cout << "Elements are: " << endl;
    for(int i=0; i<arr.length; i++){
        cout << arr.A[i] << ", ";
    }
    cout << endl;
};

void Append(struct Array *arr, int x){
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x){
    if(index >= 0 && index <= arr->length){
        for(int i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index){
    int x;
    if(index >= 0 && index < arr->length){
        x = arr->A[index];
        for(int i=index; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr, int key){
    for(int i=0; i<arr.length; i++){
        if(key == arr.A[i]){
            return i;
        }
    }
    return -1;
}

int SwapLinearSearch(struct Array *arr, int key){
    for(int i=0; i<arr->length; i++){
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key){
    // The array value has to be sorted in order to use binarySearch.
    int l = 0, h = arr.length;
    int mid;
    while(l <= h){
        mid = (l + h) / 2;
        if(arr.A[mid] == key){
            return mid;
        }
        else if(arr.A[mid] > key){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}

int RecurBinarySearch(struct Array arr, int l, int h, int key){
    int mid;
    if(l <= h){
        mid = (l + h) / 2;
        if(arr.A[mid] == key){
            return mid;
        }
        else if(arr.A[mid] > key){
            return RecurBinarySearch(arr, l, mid-1, key);
        }
        else{
            return RecurBinarySearch(arr, mid+1, h, key);
        }
    }
    return -1;
}


int main(){
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    Append(&arr, 87);
    Insert(&arr, 5, 54);
    // Delete(&arr, 3);
    // cout << LinearSearch(arr, 54) << endl;
    cout << BinarySearch(arr, 5487) << endl;
    Display(arr);
}

