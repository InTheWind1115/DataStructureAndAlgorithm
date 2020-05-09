#include <iostream>
using namespace std;
typedef int datatype;

struct node {
    node *lchild;
    node *rchild;
    datatype data;
};

typedef node *BTREE;

bool isEmpty(BTREE bt) {
    return bt == NULL;
}

BTREE lChild(BTREE bt) {
    if (isEmpty(bt))
        return NULL;
    return bt -> lchild;
}

BTREE rChild(BTREE bt) {
    if (isEmpty(bt))
        return NULL;
    return bt -> rchild;
}

BTREE createBT(datatype x, BTREE lt, BTREE rt) {
    node *newNode = new node;
    newNode -> data = x;
    newNode -> lchild = lt;
    newNode -> rchild = rt;
    return newNode;
}

void visit(datatype d) {
    cout<<d<<' ';
}

datatype data(BTREE bt) {
    return bt -> data;
}

void preOrder(BTREE bt) {
    if (!isEmpty(bt)) {
        visit(data(bt));
        preOrder(lChild(bt));
        preOrder(rChild(bt));
    }
}

int count2(BTREE t) {
    if (t == NULL)
        return 0;

    int num = 0;
    if (t -> lchild && t -> rchild) {
        num = 1;
    }

    return num + count2(t -> lchild) + count2(t -> rchild);
}

int leafnum(BTREE t) {
    if (t == NULL)
        return 0;

    int num = 0;
    if (t -> lchild == NULL && t -> rchild == NULL) {
        num = 1;
    }

    return num + leafnum(t -> lchild) + leafnum(t -> rchild);
}

int main() {

    BTREE t1, t2, t3;
    t1 = createBT(4, NULL, NULL);
    t2 = createBT(2, t1, NULL);
    t1 = createBT(6, NULL, NULL);
    t3 = createBT(5, NULL, NULL);
    t3 = createBT(3, t1, t2);
    t1 = createBT(1, t2, t3);
    cout<<"Preorder sort:\n";
    preOrder(t1);
    cout<<'\n';
    cout<<"=============================="<<endl;
    cout<<"node with two degree: \n"<<count2(t1);
    cout<<'\n';
    cout<<"=============================="<<endl;
    cout<<"the numbers of leafs:\n"<<leafnum(t1);
    int sy;
    cin>>sy;
    return 0;
}