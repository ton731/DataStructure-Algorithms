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

int Get(struct Array arr, int index){
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x){
    if(index >= 0 && index < arr->length){
        arr->A[index] = x;
    }
}

int Max(struct Array arr){
    int max = arr.A[0];
    for(int i=0; i<arr.length; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for(int i=0; i<arr.length; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr){
    int sum = 0;
    for(int i=0; i<arr.length; i++){
        sum = sum + arr.A[i];
    }
    return sum;
}

int Average(struct Array arr){
    return float(Sum(arr)/arr.length);
}

void Reverse(struct Array *arr){
    int *rev = new int[arr->length];
    for(int i=arr->length-1, j=0; i>=0; i--, j++){
        rev[j] = arr->A[i];
    }
    for(int i=0; i<arr->length; i++){
        arr->A[i] = rev[i];
    }
    delete []rev;
}

void Reverse2(struct Array *arr){
    for(int i=0, j=arr->length-1; i<j; i++, j--){
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x){
    int i = arr->length - 1;
    if(arr->length == arr->size){
        return;
    }
    while(i >= 0 && arr->A[i] > x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted(struct Array arr){
    for(int i=0; i<arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr){
    int l = 0, r = arr->length-1;
    while(l < r){
        while(arr->A[l] < 0) l++;
        while(arr->A[r] > 0) r--;
        if(l < r){
            swap(&arr->A[l], &arr->A[r]);
        }
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] <= arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else{
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for(; i<arr1->length; i++){
        arr3->A[k++] = arr1->A[i];
    }
    for(; j<arr2->length; j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

struct Array* Union(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr1->A[i] > arr2->A[j]){
            arr3->A[k++] = arr2->A[j++];
        }
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(; i<arr1->length; i++){
        arr3->A[k++] = arr1->A[i];
    }
    for(; j<arr2->length; j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            i++;
        }
        else if(arr1->A[i] > arr2->A[j]){
            j++;
        }
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;

    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr1->A[i] > arr2->A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main(){
    struct Array arr = {{2, 3, 5, 8, 12}, 10, 5};
    struct Array arr2 = {{1, 8, 12, 22}, 10, 4};
    // struct Array *arr3 = Union(&arr, &arr2);
    // struct Array *arr3 = Intersection(&arr, &arr2);
    struct Array *arr3 = Difference(&arr, &arr2);

    Display(*arr3);

}

