#include<iostream>
using namespace std;

#define maxsize 100
#define maxblock 10
typedef int keytype;

struct records {
    keytype key;
    //fields other;
};

typedef records LIST[maxsize]; /* 线性表 - 主表 */
typedef keytype INDEX[maxblock]; /* 线性表 - 索引表 */


//返回ix中第一个值不小于k的下标 ix中最后一个元素的下标为blocks
int bsearch(INDEX ix, int blocks, keytype k) {
    int up = blocks, low = 0, mid;
    while (low < up) {
        mid = (low + up) >> 1;
        if (ix[mid] < k) {
            low = mid + 1;
        } else {
            up = mid;
        }
    }

    if (ix[low] >= k)
        return low;
    else 
        return -1;
}

int index_search(keytype k, int last, int blocks, INDEX ix, LIST F, int L) {
    int i;
    i = bsearch(ix, blocks, k);
    if (i == -1)
        return -1;
    i = i * L;
    for (; i < (i + 1) * L && i <= last; i++) {
        if (F[i].key == k)
            return i;
    }

    return -1;
}

int main() {
    return 0;
}