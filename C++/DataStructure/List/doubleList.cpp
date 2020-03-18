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

int main() {
    string s = "hello";
    cout<<s<<endl;
    cout<<"Hello"<<endl;
    system("pause");
    return 0;
}