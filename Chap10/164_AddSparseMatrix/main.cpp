#include <iostream>
using namespace std;

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s){
    cout << "Enter Dimensions: " << endl;
    cin >> s->m;
    cin >> s->n;
    cout << "Enter number of non-zero: ";
    cin >> s->num;

    s->ele = new struct Element[s->num];
    cout << "Enter all element: " << endl;
    for(int i=0; i<s->num; i++){
        // cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
        cin >> s->ele[i].i;
        cin >> s->ele[i].j;
        cin >> s->ele[i].x;
    }
}

void display(struct Sparse s){
    int k = 0;
    for(int i=0; i<s.m; i++){
        for(int j=0; j<s.n; j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                cout << s.ele[k].x << " ";
                k++;
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

struct Sparse add(struct Sparse s1, struct Sparse s2){
    struct Sparse sum;
    sum.m = s1.m;
    sum.n = s1.n;
    sum.ele = new struct Element[s1.num + s2.num];

    if(s1.m != s2.m || s1.n != s2.n){
        cout << "Dimension of 2 matrix should be the same!" << endl;
        return sum;
    }

    int i=0, j=0, k=0;
    while(i<s1.num && j<s2.num){
        if(s1.ele[i].i < s2.ele[j].i){
            sum.ele[k++] = s1.ele[i++];
        }
        else if(s1.ele[i].i > s2.ele[j].i){
            sum.ele[k++] = s2.ele[j++];
        }
        else{
            if(s1.ele[i].j < s2.ele[j].j){
                sum.ele[j++] = s1.ele[i++];
            }
            else if(s1.ele[i].j > s2.ele[j].j){
                sum.ele[k++] = s2.ele[j++];
            }
            else{
                sum.ele[k] = s1.ele[i++];
                sum.ele[k++].x += s2.ele[j++].x;
            }
        }
    }
    for(; i<s1.num; i++) sum.ele[k++] = s1.ele[i];
    for(; j<s2.num; j++) sum.ele[k++] = s2.ele[j];
    sum.num = k;

    return sum;
}




int main(){
    struct Sparse s1;
    struct Sparse s2;
    struct Sparse s3;
    create(&s1);
    create(&s2);
    display(s1);
    display(s2);
    s3 = add(s1, s2);
    display(s3);
}


