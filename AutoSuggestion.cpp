#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct TrieNode{
    bool isWordEnd;
    TrieNode * children[26];
};

TrieNode * getNode() {
    TrieNode * pNode=new TrieNode();
    pNode->isWordEnd=false;

    for(int i=0;i<26;i++){
        pNode->children[i]=NULL;
    }

    return pNode;

}

void insert(TrieNode * root, const string key){
    TrieNode *newNode=root;
    int len=key.size();
    for(int i=0;i<len;i++){
        int index=key[i]-'a';
        if(!newNode->children[index]) newNode->children[index]=getNode();
        newNode=newNode->children[index];
    }
    newNode->isWordEnd=true;
}

bool search(TrieNode * root,const string query){
    TrieNode *newNode=root;
    int len=query.size();
    for(int i=0;i<len;i++){
        int index=query[i]-'a';
        if(!newNode->children[index])  return false;
        newNode=newNode->children[index];
    }

    return (newNode->isWordEnd && newNode!=NULL);
}

bool isLastNode(TrieNode *root){
    TrieNode *newNode=root;
    for(int i=0;i<26;i++){
        if(newNode->children[i]) return 0;
    }
    return 1;
}

void suggestionRec(TrieNode * root,string currPrefix){

   // TrieNode * newNode=root;

   // Printing suggestion....
   if(root->isWordEnd) {
       cout<<currPrefix<<endl;
   }
   // Base case likthe hobe
   if(isLastNode(root)) return;
   
   for(int i=0;i<26;i++){
       if(root->children[i]) currPrefix.push_back('a'+i);
       suggestionRec(root->children[i],currPrefix);
   }

}

int printAutoSuggestion(TrieNode * root,const string query){
    TrieNode * newNode=root;
    int len=query.size();

    for(int i=0;i<len;i++){
        int index=query[i]-'a';
        if(!newNode->children[index]) return 0;
        newNode=newNode->children[index];
    }

    bool isWord=(newNode->isWordEnd==true);

    bool isLast=isLastNode(newNode);

    if(isWord && isLast) {
        cout<<query<<endl;
        return -1;
    }
    
    if(!isLast) {
    
    string prefix=query;
    suggestionRec(newNode,prefix);
    return 1;
    }

}

int main() {
    TrieNode *root=getNode();

    int n;cin>>n;
    for(int i=0;i<n;i++) {
    string s;cin>>s;
    insert(root,s);
    }
    
    string s;cin>>s;
     int comp=printAutoSuggestion(root,s);

    // if(comp==0) cout<<"No string Found"<<endl;
    // else if(comp==-1) cout<<"No other string found with this prefix"<<endl;


}