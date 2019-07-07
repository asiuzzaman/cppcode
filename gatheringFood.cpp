#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool visited[15][15];
char Grid[15][15];
char Copy[15][15];
int N;
int sum=0;
struct Point
{
    int x,y;
    Point(){};
    Point(int p,int q){
        x=p;
        y=q;
    }
};


vector<Point>v;

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

bool valid(int x,int y,int desx,int desy){
    return(x>=0 and x<N and y>=0 and y<N and !visited[x][y] and Grid[x][y]=='.' or (!visited[x][y] and Grid[x][y]>='A' and Grid[x][y]<='Z'));
}


int BFS(int sx,int sy,int desx,int desy){
    
    visited[sx][sy]=1;
    queue<Point>Q;
    Q.push({sx,sy});
    
    while(!Q.empty()){
        Point temp;
        temp=Q.front();
        Q.pop();
        int u1=temp.x;
        int u2=temp.y;
        for(int i=0;i<4;i++){
            int v1=u1+dx[i];
            int v2=u2+dy[i];
            if(valid(v1,v2,desx,desy)){
                sum++;
                if(desx==v1 and desy==v2) return sum;
                visited[v1][v2]=1;
               // cout<<v1<<" "<<v2<<endl;
                Q.push({v1,v2});
            }

        }
    }
    return 0;
}

int main() {

   
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char x;
            cin>>x;
            Grid[i][j]=x;
            Copy[i][j]=x;
            visited[i][j]=0;
        }
    }

    for(char x='A';x!='Z';x++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(x==Grid[i][j]) v.push_back({i,j});
            }
        }
    }
   int ans;
   int flag=0;
   for(int p=1;p<v.size();p++) {
   int sx=v[p-1].x;
   int sy=v[p-1].y;
   int desx=v[p].x;
   int desy=v[p].y;
   for(int i=0;i<N;i++){
       for(int j=0;j<N;j++){
           if((i==desx and j==desy) or(i==sx and j==sy)) {continue;}
           else if(Grid[i][j]>='A' and Grid[i][j]<='Z') { Grid[i][j]='#'; }
       }
   }
   
   cout<<"The grid"<<endl;
   for(int i=0;i<N;i++){
       for(int j=0;j<N;j++){
           cout<<Grid[i][j]<<" ";
       }
       cout<<endl;
   }
   
   int res=BFS(sx,sy,desx,desy);
      ans=0;
    if(res==0) {
        flag=1;
    }
    else ans+=res;
  
    
   for(int i=0;i<N;i++){
       for(int j=0;j<N;j++){
           Grid[i][j]=Copy[i][j];
       }
   }

   }
  
   if(flag) cout<<"Impossible"<<endl;
   else
   cout<<ans<<endl;
   
    

}

/*

5

A....

####.

..B..

.####

C.DE.

*/