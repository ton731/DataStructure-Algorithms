#include <iostream>
using namespace std;

// Using Hash table
void FindDuplicates(int *arr){
    for(int i=0; i<10; i++){
        if(arr[i] == arr[i+1]){
            int j = i + 1;
            while(arr[i] == arr[j]){
                j++;
            }
            cout << arr[i] << " is appearing " << j-i << " times..." << endl;
            i = j - 1;
        }
    }
}

int main(){
    int arr[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    FindDuplicates(arr);
}

