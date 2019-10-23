#include<bits/stdc++.h>
using namespace std;

char Name[26+1];
struct Node{

  Node * next[26+1];
  static int counter[26];
  int cnt;
  Node():cnt(0){
   
    for(int i=0;i<26;i++) next[i]=NULL;

  }

  void Insert(const char * s){
    Node * temp=this;
    for(int i=0;i<strlen(s);i++){
      int id=s[i]-'a';
      if(temp->next[i]==NULL) temp->next[i]=new Node();
      temp=temp->next[i];
      temp->cnt++;
    }
  }
  void PrifixCount(int idx){
    counter[idx]+=cnt;
    if(cnt>1) {
      for(int i=0;i<26;i++){
        if(next[i]) next[i]->PrifixCount(i);
      }
    }
  }
  ~Node(){
    for(int i=0;i<26;i++){
      delete next[i];
    }
  }

};



int main() {
int T;
scanf("%d",&T);
while(T--)
{
  int n;
  cin>>n;
  Node *root=new Node();
  while(n--){
  scanf("%s",Name);
  root->Insert(Name);
  }

  for(int i=0;i<26;i++){
    if(root->next[i]) root->next[i]->PrifixCount(i);

  }
   int ctr=0;
  for(int i=0;i<26;i++){
    ctr+=Node::counter[i];
  }
  printf("%d \n",ctr);
  delete root;

}

}