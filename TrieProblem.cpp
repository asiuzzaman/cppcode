#include<bits/stdc++.h>
using namespace std;

struct Node{
  Node * next[26+1];
  int cnt=0;
  bool endMark=false;
  Node(){
    for(int i=0;i<26;i++) next[i]=NULL;
  }
};
Node * root;

void Insert(char *s){
     Node * newNode=root;
     for(int i=0;i<strlen(s);i++){
       int id=s[i]-'a';
       if(newNode->next[id]==NULL) newNode->next[id]=new Node();
       newNode=newNode->next[id];
       newNode->cnt++;

     }
     newNode->endMark=true;
}


void Travers(Node * root){
  if(root->endMark==true) return;
  for(int i=0;i<26;i++){
      if(root->next[i]) {
        printf("%c",'a'+i);
       Travers(root->next[i]);
      }
  }
}
 
int main() {
  root=new Node();
  char c[20];
  scanf("%s",c);
  Insert(c);
  Travers(root);


}