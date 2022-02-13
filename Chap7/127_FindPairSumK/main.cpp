#include <iostream>
using namespace std;

// Using Hash table
void FindPairSumK(int *arr, int k){
    int max = 16;
    int *hash = new int(max+1);
    for(int i=0; i<max; i++){
        if(hash[k - arr[i]] != 0){
            cout << arr[i] << " + " << k-arr[i] << " = " << k << endl;
        }
        hash[arr[i]]++;
    }
}

int main(){
    int arr[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int k = 10;
    FindPairSumK(arr, k);
}

