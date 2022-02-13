#include <iostream>
using namespace std;

// Using Hash table
void FindDuplicatesHash(int *arr){
    int l = arr[0], h = arr[10];
    int *count = new int[h+1];
    for(int i=0; i<10; i++){
        count[arr[0]]++;
    }
    for(int i=0; i<h+1; i++){
        if(count[i] != 1){
            cout << i << " is appearing " << count[i] << " times..." << endl;
        }
    }
}

int main(){
    int arr[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    FindDuplicatesHash(arr);
}

