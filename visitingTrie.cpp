#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node{
    bool endMark;
    Node * next[26];
    Node(){
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
};
Node * root;
void insert(char *s){
    
    Node * temp=root;   // Pointing the temp as root i.e it is 500 
    int len=strlen(s);

    for(int i=0;i<len;i++){
        int index=s[i]-'a';
        if(temp->next[index]==NULL) temp->next[index]=new Node();
        temp=temp->next[index];
    }
    temp->endMark=true;

}

void visit(Node * root,char str[],int level){
    
    
    if(root->endMark) {str[level]='\0'; cout<<str<<endl;}

    for(int i=0;i<26;i++){
        
        if(root->next[i]){
            // printf("%c",'a'+i);
             str[level]='a'+i;
             visit(root->next[i],str,level+1);
             
             }
    }
    
}
 
int main() {
   
   cout<<"Program Started.........."<<endl;
    root=new Node();  /// root suppose pointing the address like 500   
    
    int n;
    cin>>n;

    while(n--){
    char s[23];
    scanf("%s",s);
    insert(s);
    }
    char str[43];
    visit(root,str,0);
}