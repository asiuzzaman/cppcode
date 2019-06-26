#include<iostream>
using namespace std;

struct Node{
     int data;
     Node *next;
};
Node * front=NULL;
Node * rear=NULL;

void Push(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(front==NULL and rear==NULL){
         front=rear=temp;
         return;
    }
     rear->next=temp;
   //  rear=temp;
}
void Pop(){
     Node *temp=front;
     if(front==rear){
          front=rear=NULL;
     }
     else {
       front=front->next;
     }
     free(temp);
}
int Top(){
     return front->data;
}
void Print(){
     Node * temp=front;
     while(temp!=NULL){
          cout<<temp->data<<" ";
          temp=temp->next;
     }
}
int main(){
     Push(1);
     Push(4);
     Print();
     cout<<"the top is "<<Top()<<endl;
}