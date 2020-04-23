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
    cout<<d<<endl;
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
int main() {

    BTREE t1, t2, t3;
    t1 = createBT(4, NULL, NULL);
    t2 = createBT(2, t1, NULL);
    t1 = createBT(6, NULL, NULL);
    t3 = createBT(5, NULL, NULL);
    t3 = createBT(3, t1, t2);
    t1 = createBT(1, t2, t3);

    preOrder(t1);
    system("pause");
    return 0;
}