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

int main() {
    TrieNode *root=getNode();

    int n;cin>>n;
    for(int i=0;i<n;i++) {
    string s;cin>>s;
    insert(root,s);
    }
    
    if(search(root,"Hello")) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;


}