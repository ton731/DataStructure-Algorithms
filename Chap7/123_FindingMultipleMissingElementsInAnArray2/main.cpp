#include <iostream>
using namespace std;

// Using Hash table
void FindMultipleMissing(int *arr){
    int l = 1, h = 12, n = 10;
    int *H = new int[h];
    for(int i=0; i<h; i++){
        H[i] = 0;
    }
    for(int i=0; i<n; i++){
        H[arr[i]]++;
    }
    for(int i=l; i<h; i++){
        if(H[i] == 0){
            cout << "Missing " << i << endl;
        }
    }
}

int main(){
    int arr[10] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    FindMultipleMissing(arr);
}

