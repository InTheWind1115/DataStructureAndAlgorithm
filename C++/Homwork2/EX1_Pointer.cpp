#include <iostream>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 100
typedef int elementtype;

struct celltype {
    elementtype element;
    celltype *next;
    celltype() : next(NULL), element(0) {};
    celltype(elementtype x) : next(NULL), element(x) {};
};

typedef celltype *List;
typedef celltype *position;

void error(char str[]) {
    cout<<str<<endl;
}

//在p节点后面位置处插入一个新的节点
void insert (elementtype x, position p, List &l) {
    celltype *q = new celltype;
    if (q == NULL) {
        error("创建节点失败！");
        return;
    }
    q -> element = x;
    q -> next = p -> next;
    p -> next = q;
}

//删除p节点后面的一个节点
void del (position p, List &l) {
    celltype * q = p -> next;
    if(q == NULL) {
        error("删除节点失败！");
        return;
    }
    p -> next = q -> next;
    delete q;
}

//此链表带有头节点，故如此返回
celltype *first(List l) {
    return l -> next;
}

celltype *end(List l) {
    return NULL;
}

celltype *locate(elementtype x, List l) {
    celltype *p = first(l);
    while(p != end(l)) {
        if(p -> element == x)
            return p;
        p = p -> next;
    }
    return NULL;
}

elementtype retrieve(position p, List l) {
    if (p == NULL) {
        return INF;
    }
    return p -> element;
}

position next(position p, List l) {
    if(p == NULL) {
        error("无效位置！");
        return NULL;
    }
    return p -> next;
}

position previous(position p, List l) {
    position q = l -> next, r = l;
    while (q != end(l)) {
        if(p == q)
            return r;
        r = q;
        q = q -> next;
    }
}

void makeNull(List &l) {
    celltype *p = first(l);
    celltype *q = new celltype;
    while (p != end(l)) {
        q = p;
        p = p -> next;
        delete q; 
    }
}

void print(List l) {
    List q = first(l);
    while (q != NULL) {
        cout<<q -> element<<'\t';
        q = q -> next;
    }
}

List merge(List l1, List l2) {
    List l3 = new celltype;
    celltype *p;
    for (p = first(l1); p != end(l1); p = p -> next) {
        insert(p -> element, l3, l3);
    }

    for (p = first(l2); p != end(l2); p = p -> next) {
        if(locate(p -> element, l3) == NULL) {insert(p -> element, l3, l3);}
    }

    return l3;
}
int main()
{
    List header1 = new celltype;
    insert(10, header1, header1);
    insert(8, header1, header1);
    insert(4, header1, header1);
    insert(3, header1, header1);
    insert(1, header1, header1);

    List header2 = new celltype;
    insert(10, header2, header2);
    insert(8, header2, header2);
    insert(6, header2, header2);
    insert(5, header2, header2);
    insert(3, header2, header2);
    insert(2, header2, header2);


    List header3 = merge(header1, header2);
    print(header3);
    system("pause");
    return 0;
}