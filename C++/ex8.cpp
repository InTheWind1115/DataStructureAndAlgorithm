#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main() {
	char str[5][20];//定义二维数组(存放三个字符串)
	char string[20];//定义一维数组
	int i;
	for (i=0;i<5;i++) {
		gets(str[i]);//每换行输入一个字符串
	}

    strcpy(string, str[0]);
    for (i = 1; i < 5; i++) {
        if(strcmp(str[i], string) > 0)
		strcpy(string, str[i]);
    }
 
    cout<<"输入的五个字符串中最大的字符串是"<<string<<endl;
 
    system("pause");
	return 0;
}