#include <iostream>
#include "Queue.h"

using namespace std;

class Tree{
    Node *root;

    public:
    Tree(){root = nullptr;}
    void createTree();
    void preOrder(){preOrder(root);}
    void preOrder(Node *p);
    void postOrder(){postOrder(root);}
    void postOrder(Node *p);
    void inOrder(){inOrder(root);}
    void inOrder(Node *p);
    void levelOrder(){levelOrder(root);}
    void levelOrder(Node *p);
    int height(){return height(root);}
    int height(Node *p);
    int count(){return count(root);}
    int count(Node *p);
    int sum(){return sum(root);}
    int sum(Node *p);
};

void Tree::createTree(){
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while(!q.isEmpty()){
        p = q.dequeue();
        // cout << "hello" << endl;
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p){
    if(p){
        cout << p->data << ", ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::inOrder(Node *p){
    if(p){
        inOrder(p->lchild);
        cout << p->data << ", ";
        inOrder(p->rchild);
    }
}

void Tree::postOrder(Node *p){
    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << ", ";
    }
}

void Tree::levelOrder(Node *p){
    Node *t;
    Queue q(100);
    cout << p->data << ", ";
    q.enqueue(p);

    while(!q.isEmpty()){
        t = q.dequeue();
        if(t->lchild){
            cout << t->lchild->data << ", ";
            q.enqueue(t->lchild);
        }
        if(t->rchild){
            cout << t->rchild->data << ", ";
            q.enqueue(t->rchild);
        }
    }
}

int Tree::height(Node *p){
    int x = 0, y = 0;
    if(!p){
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    if(x > y){
        return x+1;
    }
    else{
        return y+1;
    }
}

int Tree::count(Node *p){
    int x, y;
    if(p){
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int Tree::sum(Node *p){
    int x, y;
    if(p){
        x = sum(p->lchild);
        y = sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}


int main(){
    Tree tree;
    tree.createTree();

    cout << "Preorder: ";
    tree.preOrder();
    cout << endl;

    cout << "Inorder: ";
    tree.inOrder();
    cout << endl;

    cout << "Tree height: " << tree.height() << endl;
    cout << "Tree count: " << tree.count() << endl;
    cout << "Tree sum: " << tree.sum() << endl;
}
