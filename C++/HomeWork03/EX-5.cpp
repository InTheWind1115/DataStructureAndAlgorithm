#include<iostream>
#include<sstream>
#include"./stack.cpp"
#define MAXSIZE 30
using namespace std;


char match[]=">><<<>>>><<<>>>>>><>>>>>><>><<<<<= >>>>>><<<<< =";
char opera[]="+-*/()@";
const char& Match(const char &ch1,const char &ch2)
{
int i=0,j=0;
while(opera[i]!=ch1) i++;
while(opera[j]!=ch2) j++;
return match[i*7+j];
}
class TNode
{
public:
TNode(string str="",int b=0,TNode *l=NULL,TNode *r=NULL,TNode *p=NULL){
strcpy(id,str.c_str());
bit=b;
left=l;
right=r;
parent=p;
}
TNode(const char ch,TNode *l=NULL,TNode *r=NULL,TNode *p=NULL){
id[0]=ch;
id[1]=0;
bit=0;
left=l;
right=r;
parent=p;
}
const TNode& operator=(const TNode& tn){
strcpy(id,tn.id);
bit=tn.bit;
left=tn.left;
right=tn.right;
parent=tn.parent;
}
char id[MAXSIZE];
int bit;
TNode *parent,*left,*right;
};
int ReadExpr(char *str,char *expr,int start,int bit,int &length)
{
length=0;
if(str[start]==0){
expr[0]=0;
return 0;
}
else if(str[start]=='*'||str[start]=='/'||str[start]=='('||str[start]==')'||str[start]=='@'){
expr[0]=str[start];
expr[1]=0;
length=1;
return 2;
}
else if(bit||isdigit(str[start])||str[start]=='.'){ 
int b=0;
int k=0; 
while(str[start]=='+'||str[start]=='-'){ 
if(str[start]=='-') b++;
start++;
length++;
}
if(b%2) expr[k++]='-';
while(isdigit(str[start])||str[start]=='.'){
expr[k++]=str[start++];
length++;
}
expr[k]=0;
return 1;
}
else if(str[start]=='+'||str[start]=='-'){ 
int b=0;
while(str[start]=='+'||str[start]=='-'){
if(str[start]=='-') b++;
start++;
length++;
}
if(b%2) expr[0]='-';
else expr[0]='+';
expr[1]=0;
return 2;
}
else return -1; 
}
TNode *Translate(const string &str) 
{
char substr[MAXSIZE];
Stack<char> cstk;
Stack<TNode*> tstk;
char *tempstr=new char[str.length()+2];
int start=0,bit=1;
int t,length;
strcpy(tempstr,str.c_str());
tempstr[str.length()]='@';
tempstr[str.length()+1]=0;
cstk.push('@');
t=ReadExpr(tempstr,substr,start,bit,length);
while(cstk.top()!='@'||substr[0]!='@'){
if(t==1){ 
TNode *np=new TNode(substr,1);
tstk.push(np);
bit=0;
}
else if(t==2){ 
if(substr[0]=='(') bit=1;
else bit=0;
char tch=cstk.top();
if(Match(tch,substr[0])=='>'){
TNode *right=tstk.top();
tstk.pop();
TNode *left=tstk.top();
tstk.pop();
TNode *np=new TNode(tch,left,right);
left->parent=np;
right->parent=np;
tstk.push(np);
cstk.pop();
continue;
}
else if(Match(tch,substr[0])=='<') cstk.push(substr[0]);
else cstk.pop();
}
start+=length;
t=ReadExpr(tempstr,substr,start,bit,length);
}
delete[] tempstr;
return tstk.top();
}
void print(TNode *root)
{
if(root->left){
print(root->left);
print(root->right);
cout<<root->id;
}
else cout<<root->id;
}
void prints(TNode*);
double solve(TNode*);
void printExpr(string str)
{
TNode *root=Translate(str);
cout<<"后缀式:";
print(root);
cout<<endl;
cout<<"中缀式:";
prints(root);
cout<<"="<<solve(root)<<endl;
}
void prints(TNode *root) 
{
if(root->left==NULL) cout<<root->id; 
else if(root->parent==NULL){
prints(root->left);
cout<<root->id;
prints(root->right);
}
else if(root->parent->left==root&&Match(root->id[0],root->parent->id[0])=='>'){
prints(root->left);
cout<<root->id;
prints(root->right);
}
else if(root->parent->right==root){
if(Match(root->parent->id[0],root->id[0])=='<'||root->parent->id[0]=='+'){
prints(root->left);
cout<<root->id;
prints(root->right);
}
else{
cout<<"(";
prints(root->left);
cout<<root->id;
prints(root->right);
cout<<")";
}
}
else{
cout<<"(";
prints(root->left);
cout<<root->id;
prints(root->right);
cout<<")";
}
}
double solve(TNode *root)
{
if(root->left==NULL){
istringstream in;
in.str(root->id);
double value;
in>>value;
return value;
}
else{
switch(root->id[0]){
case '+':
return solve(root->left)+solve(root->right);
case '-':
return solve(root->left)-solve(root->right);
case '*':
return solve(root->left)*solve(root->right);
case '/':
return solve(root->left)/solve(root->right);
}
}
}
void Check(char *str) 
{
int k=0,i=0;
if(str[0]=='+'||str[0]=='-'){
int b=0;
while(str[k]=='+'||str[k]=='-'){
if(str[k]=='-') b++;
k++;
}
if(str[k]!='(') return;
char *np=new char[strlen(str)+3];
if(b%2){
np[0]='0';
np[1]='-';
memcpy(np+2,str+k,strlen(str)+1-k);
memcpy(str,np,strlen(np)+1);
}
else{
memcpy(np,str+k,strlen(str)+1-k);
memcpy(str,np,strlen(np)+1);
}
delete[] np;
}
}
void main()
{
char buf[100];
while(1){
cin>>buf;
Check(buf);
printExpr(buf);
}
}

#include<iostream>
#include<string>
using namespace std;
//class stack
template <typename T>
class SNode
{
public:
SNode(){next=NULL;}
SNode(const T& td,SNode<T>* p=NULL){data=td; next=p;}
T data;
SNode<T> *next;
};
template <typename T>
class Stack
{
public:
Stack(){pdata=NULL;length=0;}
~Stack();
bool isEmpty();
bool pop();
bool push(const T& );
T top();
int size(){ return length;}
private:
SNode<T> *pdata;
int length;
};
template <typename T>
Stack<T>::~Stack<T>()
{
SNode<T> *sp=pdata,*np;
while(sp)
{
np=sp->next;
delete sp;
sp=np;
}
}
template <typename T>
bool Stack<T>::isEmpty()
{
return pdata==NULL;
}
template <typename T>
bool Stack<T>::pop()
{
SNode<T> *sp=pdata;
if(!sp) return false;
length--;
if(!sp->next){
delete sp;
pdata=NULL;
return true;
}
else{
while((sp->next)->next) sp=sp->next;
delete sp->next;
sp->next=NULL;
return true;
}
}
template <typename T>
bool Stack<T>::push(const T& st)
{
SNode<T> *np=new SNode<T>(st),*sp=pdata;
if(!np) return false;
length++;
if(!sp){
pdata=np;
return true;
}
else{
 while(sp->next) sp=sp->next;
sp->next=np;
return true;
}
}
template <typename T>
T Stack<T>::top()
{
SNode<T> *sp=pdata;
if(!sp) return T();
while(sp->next) sp=sp->next;
return sp->data;
}

