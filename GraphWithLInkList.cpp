#include<iostream>
using namespace std;
#define N 100
int node,edge;
struct Node{
    int dest,weight;
    Node * next;
};
struct Graph{
    Node * head[N];
};

void PrintGraph(Graph *graph){
    
        Node * temp=new Node();
        temp=graph->head[2];
        while(temp!=NULL){
            cout<<2<<"->"<<temp->dest<<"w:"<<temp->weight<<endl;
            temp=temp->next;
        }
    
}
int main(){
    
   cin>>node>>edge;
   Graph * graph= new Graph();
   for(int i=0;i<node;i++){
       graph->head[i]=NULL;
   }
   for(int i=0;i<edge;i++){
       int x,y,w;
       cin>>x>>y>>w;
       
       Node * newNode=new Node();
       newNode->dest=y;
       newNode->weight=w;
       newNode->next=graph->head[x];
       graph->head[x]=newNode;
   }
 //  struct Graph * graph=createGraph(edges,edge);
   PrintGraph(graph);
}

/*

6 6
0 1 6
1 2 7
2 1 4
3 2 10
4 5 1
2 0 5

 */