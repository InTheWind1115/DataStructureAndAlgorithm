#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f;
#define maxsize 100
typedef int element;
typedef int elementtype;

void error(char str[]) {
    cout<<str<<endl;
}

void makeNull(char ch[]) {
    ch[1] = '\0';
}

bool isNull(char ch[]) {
    return ch[1] == '\0';
}

int len(char ch[]) {
    int i;
    for (i = 0; ; i++)
    {
        if(ch[i] == '\0')
            return i - 1;
    }
    
}

bool in(char ch[], char b) {
    int i;
    for (i = 0; i < len(ch); i++)
    {
        if(ch[i] == b)
            return true;
    }
    return false;
    
}

void concat(char a[], char b[]) {
    char *c = new char[len(a) + len(b) + 1];
    int i;
    for (i = 1; i <= len(a); i++)
    {
        c[i] = a[i];
    }
    
    for (int j = 1; j < len(b); j++)
    {
        a[i + j] = b[j];
    }

    for (i = 1; i <= len(c); i++) {
        a[i] = c[i];
    }

    a[i] = '\0';
    
}

char *subStr(char a[], int m, int n) {
    int i;
    char *str = new char[n - m + 2];
    if(m > n) {
        str[1] = '\0';
    } else {
        for (i = m; i <= n; i++)
        {
            /* code */
            str[i - m + 1] = a[i];
        }
        
    }
    return str;
}

//O(m*n)
int index(char a[], char b[]) {
    int i = 1, j = 1;
    while (i <= len(a) && j <= len(b))
    {
        if (a[i] == b[j])
            i++, j++;
        else {
            i = i - j + 1;
            j = 1;
        }
    }

    if(j > len(b))
        return i - j;

    return 0;  
}
 
int main()
{
    /*char str1[10]; //一定要初始化 否则可能有bug 引起系统崩溃
    // str1 = "abc"; 错误的方式

    strcpy(str1, "abc");

    char *str2 = new char[10];
    str2 = "abc";//老版本不行 现在可以 但有warning

    string s = "aab";
    s += "ce";
    cout<<s<<endl;

    str1[0] = 'a';
    str1[1] = 'b';
    str1[2] = 'c';
    str1[3] = '\0';

    cout<<str1<<endl;*/

    system("pause");
    return 0;
}