#include <iostream>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 100
typedef struct node{
    int a;
    int exp;
    bool operator ==(node n1) {
        return a == n1.a && exp ==n1.exp;
    }
}elementtype;

struct celltype {
    elementtype element;
    celltype *next;
    celltype() : next(NULL), element() {};
    celltype(elementtype x) : next(NULL), element(x) {};

};

typedef celltype *List;
typedef celltype *position;

void error(string str) {
    cout<<str<<endl;
}

//在p节点后面位置处插入一个新的节点
void insert (elementtype x, position p, List &l) {
    celltype *q = new celltype;
    if (q == NULL) {
        //error("创建节点失败！");
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
        //error("删除节点失败！");
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
        return {INF, INF};
    }
    return p -> element;
}

position next(position p, List l) {
    if(p == NULL) {
        //error("无效位置！");
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
    return NULL;
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
        cout<<q -> element.a<<' '<<q -> element.exp<<'\t';
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

void copy(List &dest, List src) {
    celltype *start = src->next;
    celltype *later = dest;
    while (start != NULL) {
        insert(start -> element, later, dest);
        later = later -> next;
        start = start -> next;
    }
    
}

List add(List a, List b) {
    List c = new celltype;
    position t = c;//t始终指向链表的最后一个元素
    position p = a -> next;
    position q = b -> next;
    while (p != NULL || q != NULL)
    {
        if (p == NULL || q != NULL && p -> element.exp < q -> element.exp) {
            insert({q -> element.a, q -> element.exp}, t, c);
            t = t -> next;
            q = q -> next;
        } else if (q == NULL ||  p != NULL && p -> element.exp > q -> element.exp) {
            insert({p -> element.a, p -> element.exp}, t, c);
            t = t -> next;
            p = p -> next;
        } else {
            if (q -> element.a + p ->element.a, q -> element.exp != 0) {
                insert({q -> element.a + p ->element.a, q -> element.exp}, t, c);
                t = t -> next;
            }
            
            q = q -> next;
            p = p -> next;
        }
    }
    return c;
}

List multiply(List a, List b) {
    
    List res = new celltype;
    position aNode = a -> next;
    //print(aNode -> next);
    position bNode = b -> next;
    for(; aNode != NULL; aNode = aNode -> next) {
        for (; bNode != NULL; bNode = bNode -> next)
        {
            List newOne = new celltype;

            celltype later = {
                {aNode -> element.a * bNode -> element.a, aNode -> element.exp + bNode -> element.exp}};

            newOne -> next = &later;
            res = add(res, newOne);
        }
        bNode = b -> next;
    }
    return res;
}

int main()
{
    cout<<"加法："<<endl;
    List header3 = new celltype;
    insert({3, 1}, header3, header3);
    insert({2, 0}, header3, header3);
    insert({5, 4}, header3, header3);
    List header4 = new celltype;
    insert({3, 1}, header4, header4);
    insert({2, 0}, header4, header4);
    insert({5, 5}, header4, header4);

    List header5 = add(header3, header4);
    print(header5);

    cout<<"\n乘法："<<endl;
    List header1 = new celltype;
    insert({3, 1}, header1, header1);
    insert({2, 0}, header1, header1);
    //insert({5, 4}, header1, header1);
    //insert(3, header1, header1);
    //insert(1, header1, header1);
    List header2 = new celltype;
    insert({3, 1}, header2, header2);
    insert({2, 0}, header2, header2);
    //insert({5, 5}, header2, header2);

    List header6 = multiply(header1, header2);
    print(header6);
    system("pause");
    return 0;
}