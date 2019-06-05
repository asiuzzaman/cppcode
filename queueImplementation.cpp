#include<iostream>
using namespace std;

struct Node
{
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
    rear=temp; // eita na dile khobor asse......... memory overflow hobe mathai rakhis....
}

void Pop(){
    Node *temp=new Node();
    temp=front;
    if(front==NULL) {
        cout<<"Queue is empty.."<<endl;
        return;
    }
    
    if(front==rear){   /// Just contain one element 
        front=rear=NULL;
    } 
    else {
        front=front->next;
    }


    free(temp);
}

int Front(){
    
    if(front==NULL) {
        cout<<"Queue is Empty..."<<endl;
    }
    return front->data;
}
void Print(){
    Node *temp=new Node();
    temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    cout<<"my main starts....."<<endl;
  //  Print();
    Push(4);
    Push(44);
    Print();
    Push(11);
    Print();
    Pop();
    Print();
    cout<<Front()<<endl;
}