#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 20
typedef int element;
typedef int elementtype;

struct spacestr {
    elementtype element;
    int next;
};

spacestr space[maxsize];
typedef int position, cursor;
cursor available;//空闲池的头结点

void error(char str[]) {
    cout<<str<<endl;
}

void initialize() {
    available = 0;
    int i;
    for (i = 0; i < maxsize - 1; i++) {
        space[i].next = i + 1;
    }
    space[maxsize].next = -1; 
    
} 
//从空闲池获得一个结点
int getNode() {
    int ret = space[available].next;
    if (ret == -1) {
        error("空闲池为空！");
        return -1;
    }
    space[available].next = space[ret].next;//有bug，ret可能为-1
    return ret;
}

void freeNode(cursor p) {
    space[p].next = space[available].next;
    space[available].next = p;
}

//插在p结点之后
void insert(elementtype x, position p, cursor &l) {
    position q = getNode();
    if (q == -1) {
        error("存储池已满,插入失败！");
        return;
    }
    space[q].element = x;
    if (space[p].next != q) 
        space[q].next = space[p].next;
    else
        space[q].next = -1;
    
    space[p].next = q;
}

//删除p的后一个结点
void del(position p, cursor &l) {
    position q = space[p].next;
    if (q == -1) {
        error("删除失败！");
        return;
    }
    space[p].next = space[q].next;
    freeNode(q); 
}

void merge(cursor m, cursor n) {
    position mTail = -1;
    while(space[m].next != -1) {
        mTail = space[m].next;
        m = space[m].next;
    }
    space[mTail].next = space[n].next;
    freeNode(n);
}
position locate(elementtype x, cursor l) {
    cursor c = space[l].next;
    while (c != -1) {
        if (space[c].element == x) {
            return c;
        }
        c = space[c].next;
    }
    return -1;
}

void print(cursor l) {
    int i;
    for (i = space[l].next; i != -1; i = space[l].next)
    {
        cout<<space[i].element<<'\t';
        l = i;
    }
    
}
int main() {

    initialize();
    cursor l = getNode();
    insert(3, l, l);
    insert(4, l, l);
    insert(6, l, l);
    print(l);
    cout<<endl;

    cursor m = getNode();
    insert(7, m, m);
    insert(8, m, m);
    insert(4, m, m);
    print(m);

    merge(l, m);
    cout<<endl;

    print(l);

    system("pause");
    return 0;
}