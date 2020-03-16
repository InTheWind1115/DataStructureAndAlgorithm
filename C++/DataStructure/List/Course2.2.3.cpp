#include <iostream>
using namespace std;
#define maxsize 100
#define INF 0x3f3f3f;
typedef int elementtype;

struct spacestr {
    elementtype element;
    int next;
};

spacestr SPACE[maxsize];
typedef int position, cursor;

cursor avaiable;//空闲池头节点

void error(char str[]) {
    cout<<str<<endl;
}

void initialize() {
    avaiable = 0;
    int i;
    for (i = 0; i < maxsize - 1; i++)
    {
        SPACE[i].next = i + 1;
    }
    SPACE[maxsize - 1].next = -1;
}

int getNode() {
    int ret = SPACE[avaiable].next;
    if(ret == -1) {
        error("空闲池为空！");
        return -1;
    }
    SPACE[avaiable].next = SPACE[ret].next;
    return ret;
}

void freeNode(cursor p) {
    SPACE[p].next = SPACE[avaiable].next;
    SPACE[avaiable].next = p;
}

void insert(elementtype x, position p, cursor &l) {
    position q = getNode();
    if (q == -1) {
        error("插入失败！");
        return;
    }
    SPACE[q].element = x;
    SPACE[q].next = SPACE[p].next;
    SPACE[p].next = q; 
}

void del(position p, cursor &l) {
    position q = SPACE[p].next;
    if(q == -1) {
        error("删除失败！");
        return;
    }
    SPACE[p].next = SPACE[q].next;
    freeNode(q);
}

position locate(elementtype x, cursor l) {
    cursor c = SPACE[l].next;
    while (c != -1) {
        if(SPACE[c].element == x)
            return c;
        c = SPACE[c].next;
    }
    return -1;
}
int main()
{
    system("pause");
    return 0;
}