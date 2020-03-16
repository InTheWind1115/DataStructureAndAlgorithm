#include <iostream>
using namespace std;
#define INF 0x3f3f3f;

struct celltype {
    elementtype element;
    celltype *next;
    celltype() : next(NULL) {

    }
};
typedef celltype *List;
typedef int elementtype;
typedef celltype *position;


void error(char str[]) {
    cout<<str<<endl;
}
void insert(elementtype x, position p, List &l) {
    List q = new celltype;
    if (q == NULL) {
        error("创建节点失败！");
        return;
    }
    q -> element = x;

    q -> next = p -> next;
    p -> next = q;
}

void del(position p, List &l) {
    List q = p -> next;
    if (q == NULL) {
        error("删除节点失败！");
        return;
    }
    p -> next = q -> next;
    delete q;

}

List first(List l) {
    return l -> next;
}

List end(List l) {
    return NULL;
}

List locate(elementtype x, List l) {
    List p = first(l);
    while (p != end(l))
    {
        if (p -> element == x)
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
    if(p == NULL)
    {
        error("");
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
    List q = first(l);
    while (q != NULL)
    {
        del(q, l);
        q = first(l);
    }
    
}

void print(List l) {
    List q = first(l);
    while (q != NULL)
    {
        cout<<q -> element<<endl;
        q = first(l);
    }
}
int main()
{
    List header = new celltype;
    insert(2, header, header);
    insert(3, header, header);
    insert(4, header, header);
    position p = locate(3, header);
    insert(5, p, header);

    makeNull(header);
    delete header;
    system("pause");
    return 0;
}