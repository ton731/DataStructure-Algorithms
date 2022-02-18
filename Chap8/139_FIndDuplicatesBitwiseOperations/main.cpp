#include <iostream>
using namespace std;

int main(){
    char A[] = "finding";
    // 26 alphabets need 4byte(32bit) to store, so use long int (we assume int is 2 byte)
    long int H, x;
    for(int i=0; A[i]!='\0'; i++){
        // check if chac exists, if not, then add 1
        x = 1;
        x = x << (A[i] - 97);
        if((H & x) > 0){
            cout << A[i] << " is duplicated..." << endl;
        }
        else{
            H = H | x;
        }
    }
    cout << H << endl;

}
