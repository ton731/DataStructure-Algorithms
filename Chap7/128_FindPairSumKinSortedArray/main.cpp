#include <iostream>
using namespace std;

// Using Hash table
void FindPairSumKsorted(int *arr, int length, int k){
    int i = 0, j = length - 1;
    while(i < j){
        if(arr[i] + arr[j] == k){
            cout << arr[i] << " + " << arr[j] << " = " << k << endl;
            i++;
            j--;
        }
        else if(arr[i] + arr[j] < k){
            i++;
        }
        else{
            j--;
        }
    }
}

int main(){
    int arr[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int length = 10;
    int k = 10;
    FindPairSumKsorted(arr, length, k);
}

