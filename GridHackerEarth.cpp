//Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/robot-in-grid-b7d391f7/description/

#include <iostream>
using namespace std;
#define ll long long int
#define MX 1005
char Grid[MX][MX];
int N, M, q;
bool visited[MX][MX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int sum;
int Level[MX][MX];

struct Point{
    int x,y;
};

struct Node
{
    Point data;
    Node *next;
};

Node * front=NULL;
Node * rear=NULL;

void Push(Point p){
    Node * temp=new Node();
    temp->data.x=p.x;
    temp->data.y=p.y;
    temp->next=NULL;
    if(front==NULL and rear==NULL) {
        front=rear=temp;
    }
    else {
        rear->next=temp;
       // temp=rear;
       rear=temp;
    }
}
void Pop(){
    // Node * temp=new Node();
    // temp=front;
    if(front==rear) front=rear=NULL;
    else {
    front=front->next;
    }
    //free(temp);
}

Point Front(){
    return front->data;
}

void Print(){
    Node *temp=front;
    while(temp!=NULL){
        cout<<temp->data.x<<" "<<temp->data.y<<endl;
        temp=temp->next;
    }
}

void PrintMat(int Level[][MX]){
       cout<<"Matrix......"<<endl;
      for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<Level[i][j];
        }
        cout<<endl;
    }
   
}
bool valid(int x, int y)
{
    return (x > 0 and x <= N and y > 0 and y <= M and !visited[x][y] and Grid[x][y] == 'O');
}

int BFS(int s1, int s2)
{
    visited[s1][s2] = true;
    //queue<Point>Q;
    Push({s1,s2});
    Level[s1][s2]=0;

    while(front!=NULL) {
        int u1=Front().x;
        int u2=Front().y;
        Pop();
        for(int i=0;i<4;i++){
            int v1=u1+dx[i];
            int v2=u2+dy[i];
            if(valid(v1,v2)){
                Push({v1,v2});
                visited[v1][v2]=1;
                Level[v1][v2]=Level[u1][u2]+1;
               // PrintMat(Level);

            }
        }
    }
   
}

int main()
{
    cin >> N >> M >> q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            char x;
             cin >> x;
            Grid[i][j] = x;
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            Level[i][j]=-1;
        }
    }
    int s1, s2;
    cin >> s1 >> s2;
    BFS(s1, s2);
    for (int i = 0; i < q; i++)
    {
        int d1, d2;
        cin >> d1 >> d2;
        cout<<Level[d1][d2]<<endl;
        
    }

   // Push(3);
    //Print();
    // Push({4,9});
    // Push({44,99});
    // Print();
    // Pop();
    // Print();
    // cout<<Front().x<<" "<<Front().y<<endl;

  
}

/*

3 3 2
O*O
OOO
*OO
2 2
1 1
1 2

*/