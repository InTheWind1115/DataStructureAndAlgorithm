#include <iostream>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 100

typedef int elementtype;
typedef int position;

struct List {
    elementtype elements[maxsize];
    int last;
    List() : last(0) {}
};

void error(char str[]) {
    cout<<str<<endl;
}

void makeNull(List &l) {
    l.last = 0;
}

bool isNull(List l) {
    return l.last == 0;
}

bool isFull(List l) {
    return l.last == maxsize - 1; 
}

int first(List l) {
    if (isNull(l) == 0)
        return 1;
    return 0;
}

int end(List l) {
    return l.last;
}
 
int previous(position p, List l) {
    if (p > 0 && p <= l.last + 1)
        return p - 1;
    else {
        error("下标越界！");
        return 0;
    }
    
}

int next(position p, List l) {
    if (p >= 0 && p < l.last)
        return p + 1;
    else {
        error("下标越界！");
        return 0;
    }
}

elementtype retrieve(position p, List l) {
    if(p < 1 || p > l.last) {
        error("Error!");
        return INF;
    }
    return l.elements[p];
}

int locate(elementtype x, List l) {
    int i;
    for (i = first(l); i <= end(l); i++)
    {
        if (x == retrieve(i, l))
            return i;
    }
    return 0;
    
}

void insert(elementtype x, position p, List &l) {
    int i;
    if (isFull(l)) {
        error("顺序表已满！");
        return;
    }
    if(p < 0)
        p = 0;
    /*else if (p > l.last && l.last != 0) { 
        p = l.last;
    }*/

    for(i = l.last; i >= p; i--) {
        l.elements[i + 1] = l.elements[i];
    }
    l.elements[p] = x;
    ++l.last;
}

void del(position p, List &l) {
    int i;
    if (isNull(l)) {
        error("顺序表为空！");
        return;
    }
    if(p < 0 ||p > l.last) {
        error("下标越界！");
        return;
    }

    for(i = p + 1; i <= l.last; i++) {
        l.elements[i - 1] = l.elements[i];
    }
    --l.last;
}

void print(List l) {
    int i;
    for (i = 1; i <= l.last; i++)
    {
        cout<<l.elements[i]<<'\t';
    }
    cout<<endl;  
}



List merge(List l1, List l2) {
    List l3 = List();
    int i, j;
    for (i = first(l1); i <= end(l1); i++)
    {
        insert(l1.elements[i], l3.last + 1, l3);
    }

    for (i = first(l2); i <= end(l2); i++)
    {
        if(locate(l2.elements[i], l3) == 0) {insert(l2.elements[i], l3.last + 1, l3);}
            
    }

    return l3;
}



int main()
{
    List l1 = List();
    List l2 = List();
    insert(1, 1, l1);
    insert(3, 2, l1);
    insert(4, 3, l1);
    insert(8, 4, l1);
    insert(10, 5, l1);

    insert(2, 1, l2);
    insert(3, 2, l2);
    insert(5, 3, l2);
    insert(6, 4, l2);
    insert(8, 5, l2);
    insert(10, 6, l2);

    List l3 = merge(l1, l2);
    print(l3);
    system("pause");
    return 0;
}