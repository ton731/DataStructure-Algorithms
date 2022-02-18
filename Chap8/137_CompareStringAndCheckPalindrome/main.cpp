#include <iostream>
using namespace std;

int main(){
    char A[] = "TonynoT";
    int i, j;
    bool ifPal = true;
    for(j=0; A[j]!='\0'; j++){
    }
    j--;
    for(i=0; i<j; i++, j--){
        if(A[i]!=A[j]){
            ifPal = false;
            break;
        }
    }
    if(ifPal){
        cout << A << " is palindrone" << endl;
    }
    else{
        cout << A << " is not palindrone" << endl;
    }
}

