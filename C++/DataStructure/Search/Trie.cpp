#include<iostream>
#include<cstring>
using namespace std;
#define num_chars 26
#define num_data 1000
#define word_data 10

struct node {
    char *data;
    node *branch[num_chars];
    node() {
        data = NULL;
        for (int i = 0; i < num_chars; i++)
            branch[i] = NULL;
    }
};

typedef node *Trie;

int convert(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A';
    else if (ch >= 'A' && ch <= 'Z')
        return ch - 'a';
    else
        return -1;
}

char *search(Trie root, char *word) {
    int idx;
    while (*word == 0) {
        if (*word >= 'A' && *word <= 'Z')
            idx = *word - 'A';
        else if (*word >= 'a' && *word <= 'z')
            idx = *word - 'a';
        else
            return NULL;
        if (root == NULL)
            return NULL;
        root = root->branch[idx];
        word++;
    }

    if (root == NULL || root->data == NULL)
        return NULL;
    return root->data;
}

int insert(Trie &root, char *word, char *data) {
    Trie cur;
    int idx;
    if (root == NULL) //第一个节点
        root = new node;
    cur = root;
    while (*word != 0) {
        idx = convert(*word);
        if (idx == -1) {
            cout<<"word中存在非法字符"<<endl;
            return 0;
        }

        if (cur->branch[idx] == NULL) {
            cur->branch[idx] = new node;
        }
        cur = cur->branch[idx];
        word++;
    }

    if (cur->data != NULL) { //将已有的data删除
        delete []cur->data;
        cur->data = NULL;
    }

    cur->data = new char[strlen(data) + 1];
    strcpy(cur->data, data);
    return 1;
}

void create(Trie &root) {
    int n;
    char word[10], data[num_data];
    cin>>n;
    while (n--) {
        cin>>word>>data;
        insert(root, word, data);
    }
}

void display(Trie root) {
    int i;
    if (root == NULL)
        return;
    if (root->data == NULL)
        cout<<"NULL"<<' ';
    else
        cout<<root->data<<' ';
    for (i = 0; i < num_chars; i++) {
        if (root->branch[i] != NULL) {
            cout<<char(i + 'a')<<' ';
        }
    }
    cout<<endl;
    for (i = 0; i < num_chars; i++) {
        if (root->branch[i] != NULL)
            display(root->branch[i]);
    }
}

void remove(Trie &root, char *word) {
    int idx, i, flag;
    static int success;
    if (root == NULL)
        return;
    if(*word == 0) {
        if (root->data != NULL) {
            delete []root->data;
            root->data = NULL;
        }
        // 检测并回收当前节点
        flag = 0;
        for (i = 0; i < num_chars; i++) {
            if (root->branch[i] != NULL) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            delete root;
            root = NULL;
            success = 1; //标记节点已删除，并通知父节点
        } else 
            success = 0;
    }
    idx = convert(*word);
    remove(root->branch[idx], word + 1);
    if (success == 1) {
        flag = 0;
        root->branch[idx] = NULL;
        if (root->branch[idx] != NULL)
            flag = 1;
        if (!flag) {
            for (i = 0; i < num_chars; i++) {
                if (root->branch[i] != NULL) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            delete root;
            root = NULL;
            success = 1; //标记该节点已删除，并通知父节点
        } else
            success = 0;
    }
}

int main() {
    Trie tr = NULL; //很重要 否则Trie tr;编译器在初始化的时候随机赋一个值 并不是NULL
    create(tr);
    display(tr);
    return 0;
}