#include <iostream>
#include <stdio.h>
using namespace std;

struct Array{
    int *A;
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

int main(){
    struct Array arr;
    int n;

    cout << "Enter the size of an array: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;

    cout << "Enter the number of numbers: ";
    cin >> n;

    cout << "Enter all elements: " << endl;
    for(int i=0; i<n; i++){
        cin >> arr.A[i];
    }
    arr.length = n;

    Display(arr);
}

