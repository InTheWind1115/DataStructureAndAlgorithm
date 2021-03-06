#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 100
typedef int element;
typedef int datatype;

void error(char str[]) {
    cout<<str<<endl;
}

struct node {
    datatype data;
    node *lChild, *rChild;
    bool lTag, rTag;//true指向孩子，false指向前/后驱
};
typedef node *thTree;

thTree inNext(thTree p) {
    thTree q = p -> rChild;
    if (p -> rTag == true) {
        while (q -> lTag ==true) {
            q = q -> lChild;
        }
    }
    return q;
}

thTree inPre(thTree p) {
    thTree q = p -> lChild;
    if (p -> lTag == true) {
        while (q -> rTag ==true) {
            q = q -> rChild;
        }
    }
    return q;
}

void visit(thTree t) {
    cout<<t -> data<<endl;
}

void thInOrder(thTree h) {
    thTree t = h;
    do {
        t = inNext(t);
        if (t != h) {
            visit(t);
        }
    } while (t != h);
}
//将结点r插入为结点s的右孩子
void rInsert(thTree s, thTree r) {
    r -> rTag = s -> rTag;
    r -> rChild = s -> rChild;
    r -> lTag = false;
    r -> lChild = s;
    s -> rChild = r;
    s -> rTag = true;
    if (r -> rTag == true) {
        thTree v = inNext(r);
        v -> lChild = r;
    }
}

thTree preNext(thTree p) {
    if (p -> lTag == true) {
        return p -> lChild;
    } else {
        thTree q = p;
        while (q -> rTag == false)  {
            q = q -> rChild;
        }
        return q -> rChild;
    }
}

int main() {
    string s = "hello";
    cout<<s<<endl;
    cout<<"Hello"<<endl;
    system("pause");
    return 0;
}