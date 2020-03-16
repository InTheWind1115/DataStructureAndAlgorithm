#include <iostream>
#include <list>
using namespace std;
#define INF 0x3f3f3f;
#define maxsize 100
typedef int element;
typedef int elementtype;

void error(char str[]) {
    cout<<str<<endl;
}
 
int main()
{
    list<int> li;
    li.push_back(3);
    li.push_front(5);
    li.push_back(4);
    cout<<li.front()<<' '<<li.back()<<endl;
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        /* code */
        cout<<endl;
    }
    
    system("pause");
    return 0;
}