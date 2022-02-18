#include <iostream>
using namespace std;

class LowerTriangle{
    private:
    int n;
    int *A;

    public:
    LowerTriangle(){
        n = 2;
        A = new int[n*(n+1)/2];
    }
    LowerTriangle(int n){
        this->n = n;
        A = new int[n*(n+1)/2];
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    int getDim();

    ~LowerTriangle(){
        delete []A;
    }
};

void LowerTriangle::set(int i, int j, int x){
    if(i >= j){
        A[i*(i-1)/2+j-1] = x;
    }
}

int LowerTriangle::get(int i, int j){
    if(i == j){
        return A[i*(i-1)/2+j-1];
    }
    else{
        return 0;
    }
}

void LowerTriangle::display(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i >= j){
                cout << A[i*(i-1)/2+j-1] << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int LowerTriangle::getDim(){
    return n;
}

int main(){
    int n;
    cout << "Enter dimension: ";
    cin >> n;

    LowerTriangle m(n);
    int x;

    cout << "Enter all elements:" << endl;;
    for(int i=1; i<=m.getDim(); i++){
        for(int j=1; j<=m.getDim(); j++){
            cin >> x;
            m.set(i, j, x);
        }
    }
    cout << endl;
    m.display();
}
