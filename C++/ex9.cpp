#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int findWords(char* s)
{
    int i, k = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] != ' ' && s[i+1] == ' ' || s[i] != ' ' && s[i+1] == '\0') {
            k++;
        }
    }
    return k;
}
int main() {  
    char line[80];    
    int num = 0;
    cout<<"Enter a string :\n";
    gets(line);
    num = findWords(line);
    cout<<"The number of word is:\n"<<num<<endl;

    system("pause");
    return 0;
}