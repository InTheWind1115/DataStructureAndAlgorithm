#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 100
typedef int elementtype;

void error(char str[]) {
    cout<<str<<endl;
}

struct dcelltype {
    elementtype element;
    dcelltype *next, *pre;
    dcelltype() : next(NULL), pre(NULL) {};
};
typedef dcelltype *dList;
typedef dcelltype *position;

void insert(elementtype x, position p, dList &l) {
    position s = p -> next;
     position q = new dcelltype;
     q -> element = x;
    q -> next = s;
    if (s != NULL)
        s -> pre = q;
    p -> next = q;
    q -> pre = p;
}

void del(position p, dList &l) {
    position q = p -> next, s = q -> next;
    if (q == NULL)
        return;
    p -> next = s;
    if (s != NULL)
        s -> pre = p;
    delete q;
}

int swap(elementtype x, dList &l) {

    position p = l -> next;
    while (p != NULL) {
        if (p -> element == x) {
            p -> element = p -> pre -> element;
            p -> pre -> element = x;
            return 1;
        }
        p = p -> next;
    }

    return 0;
}

void print(dList l) {
    position p = l -> next;
    while (p != NULL) {
        cout<<p -> element<<" ";
        p = p -> next;
    }
    cout<<endl;
}


int main() {
    dList list = new dcelltype();
    insert(1, list, list);
    insert(2, list, list);
    insert(3, list, list);
    insert(4, list, list);
    print(list);
    cout<<endl;

    cout<<swap(2, list)<<endl;
    print(list);
    
    cout<<swap(6, list)<<endl;
    print(list);
    system("pause");
    return 0;
}