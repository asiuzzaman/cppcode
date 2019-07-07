#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 4
int mat[N][N];
int vis[N][N];


bool valid(int x,int y){
    return (x>=0 and x<N and y>=0 and y<N and mat[x][y]);
}

void PrintSol(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool SolveUtil(int x,int y){
    //Base Case ....
    if(x==0 and y==N-1) {
        vis[x][y]=1;
        return true;
    }
    if(valid(x,y)){
        vis[x][y]=1;
        cout<<x<<" "<<y<<endl;
        if(SolveUtil(x+1,y)) return true;
       if(SolveUtil(x,y+1)) return true;
        vis[x][y]=0;
        return false;
    }
    return false;
}

int main() {
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>mat[i][j];
            //cout<<vis[i][j]<<" ";
        }
    }
    if(SolveUtil(0,0)) {
        PrintSol();
    }
    else cout<<"Solution Does not exits....."<<endl;


}

/*

1 1 0 1
1 1 0 0
0 1 0 0
1 1 1 1 

*/