#include <iostream>
using namespace std;
typedef char datatype;
#define maxsize 100
struct elementtype {
    int key;
    datatype data;
};

typedef struct node{
    elementtype eles[maxsize];
    int n;
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
        if (h.eles[ch].key > h.eles[fa].key) {
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
int main() {
    return 0;
}