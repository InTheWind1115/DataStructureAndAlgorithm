#include <iostream>
using namespace std;
typedef char datatype;
#define maxsize 100
struct elementtype {
    int key;
    datatype data;
    bool operator==(const elementtype e) const {
        return key == e.key && data == e.data;
    }

};

typedef struct node{
    elementtype eles[maxsize];
    int n; //表示eles数组存了多少个原素 从下标1开始
    node(): n(0) {}
} Heap;

int heapFull(Heap h) {
    return h.n == maxsize - 1;
}

void insert(elementtype e, Heap &h) {
    if (heapFull(h)) {
        cout<<"堆已满，插入失败！"<<endl;
        return;
    }
    ++h.n;
    h.eles[h.n] = e;

    int ch = h.n, fa = ch / 2;
    while (1) {
        if (h.eles[ch].key > h.eles[fa].key && fa != 0) {
            swap(h.eles[ch], h.eles[fa]); // ?
            ch = fa;
            fa = ch / 2;
            if (fa == 0)
                return;
        } else {
            return;
        }
    }    
}

int maxIndex(int fa, Heap h) {
    if (2 * fa > h.n)
        return 0;
    else if (2 * fa + 1 > h.n) {
        return 2 * fa;
    }
    if (h.eles[2 * fa].key > h.eles[2 * fa + 1].key)
        return 2 * fa;
    else
        return 2 * fa + 1;
    
}

int empty(Heap h) {
    return h.n == 0;
}

void del(Heap &h) {
    if (empty(h)) {
        cout<<"堆为空！"<<endl;
        return;
    }

    h.eles[1] = h.eles[h.n];
    --h.n;
    int fa = 1, ch = maxIndex(fa, h);
    while (1) {
        if (h.eles[fa].key < h.eles[ch].key) {
            swap(h.eles[fa], h.eles[ch]);
            fa = ch;
            ch = maxIndex(fa, h);

            if (ch == 0) 
                return;
        } else 
            return;
    }
    swap(h.eles[fa], h.eles[ch]);

}

 Heap copy(Heap h) {
     int i;
     static Heap newH;
     newH.n = h.n;
     for (i = 1; i <= h.n; i++) {
         newH.eles[i].data = h.eles[i].data;
         newH.eles[i].key = h.eles[i].key;
     }
     return newH;

 }

int find(Heap h,elementtype e) {
    int i;
    Heap newH = copy(h);
    for (i = h.n; i >= 1; i--) {
        del(newH);
        if (h.eles[i] == e) {
            return i;
        }
    }
    return -1; //没找到
}

int main() {
    Heap h;
    insert({1, 'a'}, h);
    insert({2, 'b'}, h);
    insert({3, 'c'}, h);
    insert({4, 'd'}, h);
    insert({5, 'e'}, h);
    insert({6, 'f'}, h);
    insert({7, 'g'}, h);
    cout<<find(h, {12, 'h'})<<endl;
    cout<<find(h, {7, 'g'})<<endl;
    cout<<find(h, {6, 'f'})<<endl;
    /*insert({1, 'a'}, h);
    cout<<find(h, {12, 'h'})<<endl;
    cout<<find(h, {1, 'a'})<<endl;*/


    int i;
    cin>>i;
    return 0;
}
