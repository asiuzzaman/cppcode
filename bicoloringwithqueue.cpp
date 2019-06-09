#include<iostream>
using namespace std;
#define SZ 20005
#define Red 1
#define Black 0
int node,edge;
int Graph[SZ][SZ];

struct Node
{
    int data;
    Node *next;
};

    Node *front = NULL;
    Node *rear = NULL;

    void Push(int  p)
    {
        Node *temp = new Node();
        temp->data = p;
        temp->next = NULL;
        if (front == NULL and rear == NULL)
        {
            front = rear = temp;
             return; // ei return na dile choda khaba........
        }
        rear->next = temp;
        rear = temp;
    }

    void Pop()
    {
        Node *temp = new Node();
        temp = front;
        if (front == NULL)
        {
            cout << "The queue is Empty()...." << endl;
        }
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
        free(temp);
    }

    int Top()
    {

        return front->data;
    }


bool BFS(int src){
   
   int vis[SZ];
  for(int i=0;i<SZ;i++){
    vis[i]=-1;
  }
  vis[src]=Red;
//   queue<int>Q;
//   Q.push(src);
    Push(src);

  while(front!=NULL){
    int u=Top();
    Pop();
    if(Graph[u][u]==1) {
      return false;
    }
    for(int v=0;v<node;v++){
      
      if(Graph[u][v] and vis[v]==-1){
        {
          vis[v]=1-vis[u]; ///The Black color...
          Push(v);
        }
      }
      else if(Graph[u][v] and vis[u]==vis[v]) return false;
    }
  }
  return true;
}

int main(){
  while (cin>>node and node!=0){
    cin>>edge;
    for(int i=0;i<SZ;i++){
      for(int j=0;j<SZ;j++){
        Graph[i][j]=0;
      }
    }
    
    for(int i=0;i<edge;i++){
      int x,y;
      cin>>x>>y;
      Graph[x][y]=1;
      Graph[y][x]=1;
    }
    int src=0;;
   BFS(src)?cout<<"BICOLORABLE."<<endl:cout<<"NOT BICOLORABLE."<<endl;
  }

}