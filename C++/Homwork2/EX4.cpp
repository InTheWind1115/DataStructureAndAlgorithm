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
cursor available;//���гص�ͷ���

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
//�ӿ��гػ��һ�����
int getNode() {
    int ret = space[available].next;
    if (ret == -1) {
        error("���г�Ϊ�գ�");
        return -1;
    }
    space[available].next = space[ret].next;//��bug��ret����Ϊ-1
    return ret;
}

void freeNode(cursor p) {
    space[p].next = space[available].next;
    space[available].next = p;
}

//����p���֮��
void insert(elementtype x, position p, cursor &l) {
    position q = getNode();
    if (q == -1) {
        error("�洢������,����ʧ�ܣ�");
        return;
    }
    space[q].element = x;
    if (space[p].next != q) 
        space[q].next = space[p].next;
    else
        space[q].next = -1;
    
    space[p].next = q;
}

//ɾ��p�ĺ�һ�����
void del(position p, cursor &l) {
    position q = space[p].next;
    if (q == -1) {
        error("ɾ��ʧ�ܣ�");
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