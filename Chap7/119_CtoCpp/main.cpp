#include <iostream>
using namespace std;

class Array{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);
    
public:
    Array(){
        size = 10;
        A = new int[size];
        length = 0;
    }
    Array(int sz){
        size = sz;
        A = new int[size];
        length = 0;
    }
    ~Array(){
        delete []A;
    }
    
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int SwapLinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    int Average();
    void Reverse();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
};

void Array::Display(){
    cout << "Elements are: " << endl;
    for(int i=0; i<length; i++){
        cout << A[i] << ", ";
    }
    cout << endl;
}

void Array::Append(int x){
    if(length < size){
        A[length++] = x;
    }
}

void Array::Insert(int index, int x){
    if(index >= 0 && index <= length){
        for(int i=length; i>index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index){
    int x;
    if(index >= 0 && index < length){
        x = A[index];
        for(int i=index; i<length-1; i++){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}

void Array::swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch(int key){
    for(int i=0; i<length; i++){
        if(key == A[i]){
            return i;
        }
    }
    return -1;
}

int Array::SwapLinearSearch(int key){
    for(int i=0; i<length; i++){
        if(key == A[i]){
            swap(&A[i], &A[i-1]);
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key){
    // The array value has to be sorted in order to use binarySearch.
    int l = 0, h = length;
    int mid;
    while(l <= h){
        mid = (l + h) / 2;
        if(A[mid] == key){
            return mid;
        }
        else if(A[mid] > key){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}

int Array::Get(int index){
    if(index >= 0 && index < length){
        return A[index];
    }
    return -1;
}

void Array::Set(int index, int x){
    if(index >= 0 && index < length){
        A[index] = x;
    }
}

int Array::Max(){
    int max = A[0];
    for(int i=0; i<length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    for(int i=0; i<length; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array::Sum(){
    int sum = 0;
    for(int i=0; i<length; i++){
        sum = sum + A[i];
    }
    return sum;
}

int Array::Average(){
    return float(Sum()/length);
}

void Array::Reverse(){
    int *rev = new int[length];
    for(int i=length-1, j=0; i>=0; i--, j++){
        rev[j] = A[i];
    }
    for(int i=0; i<length; i++){
        A[i] = rev[i];
    }
    delete []rev;
}

void Array::InsertSort(int x){
    int i = length - 1;
    if(length == size){
        return;
    }
    while(i >= 0 && A[i] > x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}

int Array::isSorted(){
    for(int i=0; i<length-1; i++){
        if(A[i] > A[i+1]){
            return 0;
        }
    }
    return 1;
}

void Array::Rearrange(){
    int l = 0, r = length-1;
    while(l < r){
        while(A[l] < 0) l++;
        while(A[r] > 0) r--;
        if(l < r){
            swap(&A[l], &A[r]);
        }
    }
}


int main(){
    int ch;
    int sz;
    int x, index;

    cout << "Enter Size of Array: ";
    cin >> sz;
    Array arr(sz);

    do{
        cout << "\n\n";
        cout << "Menu: " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Sum" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch){
            case 1: 
                cout << "Enter an element and index: ";
                cin >> x >> index;
                arr.Insert(index, x);
                break;
            case 2:
                cout << "Enter index: ";
                cin >> index;
                x = arr.Delete(index);
                cout << "Deleted Element is " << x << endl;
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> x;
                index = arr.LinearSearch(x);
                cout << "Element index is " << index;
                break;
            case 4:
                cout << "Sum is " << arr.Sum() << endl;
                break;
            case 5:
                arr.Display();
        }
    }
    while(ch < 6);
}

