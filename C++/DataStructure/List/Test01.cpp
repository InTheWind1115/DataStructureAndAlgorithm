#include<iostream>
#include<vector>
using namespace std;
#define maxlength 100
#define INF 0x3f3f3f3f
//const int maxlength = 100;
/*typedef int elementtype;
enum boolean{FALSE, TRUE};
struct node
{           
    int no;
    int age;
    char name[20];
    elementtype elements[maxlength];
};

struct List{
    elementtype elements[maxlength];
    int last; //最后一个元素的下标
    List() : last(0) {

    }
};

typedef int position;

void error(char str[20]) {
    cout<<str<<endl;
}


void makeNull(List &l) {
    l.last = 0;
}

boolean isNull(List l) {
    return (l.last == 0)? TRUE : FALSE;
}

boolean isFull(List l) {
    return (l.last == maxlength - 1)? TRUE : FALSE;
}

int first(List l) {
    if (isNull(l) == 0)
        return 1;
    return 0;
}

int end(List l) {
    return l.last + 1;
}

int previous(position p, List l) {
    if (p > 0 && p <= l.last + 1)
        return p - 1;
    else {
        cout<<"下标越界"<<endl;
        return 0;
    }
}

int next(position p, List l) {
    if(p >= 0 && p < l.last)
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

//判断x是否在l中，如果在，返回下标，否则返回0
//O(n)
int locate(elementtype x, List l) {
    int i;
    for (i = first(l); i != end(l); i++) {
        if (x == retrieve(i, l))
            return i;
    }
    return 0;
    
}

//O(n)
void insert(elementtype x, position p, List &l) {
    int i;
    if (isFull(l)) {
        error("顺序表已满");
        return;
    }

    if (p < 0)
        p = 0;
    else if (p > l.last)
        p = l.last;

    for (i = l.last; i > p; i++) {
        l.elements[i + 1] = l.elements[i];
    }
    l.elements[p] = x;
    ++l.last;
}

//O(n)
void del(position p, List &l) {
    int i;
    if (isNull(l)) {
        error("顺序表为空");
        return;
    }

    if (p < 0 || p > l.last) {
        error("下标越界！");
        return;
    }

    for (i = p + 1; i < l.last; i++)//我觉得i的开始是不是有点问题
    {
        l.elements[i] = l.elements[i + 1];
    }
    --l.last;
    

}*/


 int main() {
     vector<int> ve(10, 2);
     vector<int>::iterator it;
     /*ve.push_back(3);
     ve.push_back(5);
     ve.push_back(10);*/
     for (it = ve.begin(); it != ve.end(); it++)
     {
         cout<<*it<<endl;
     }
     system("pause");
     
 }