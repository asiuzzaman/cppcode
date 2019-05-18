#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>

int fx[]={1,-1,0,0}; 
int fy[]={0,0,1,-1};

int visited[1005][1005];    
int grid[1005][1005];
int level[1005][1005];

void initialization(){
    for(int i=0;i<1005;i++){
        for(int j=0;j<1005;j++){
            grid[i][j]=0;
            visited[i][j]=0;
            level[i][j]=0;
        }
    }
}    

int main(){
    int row,col;
   while( cin>>row>>col and !(row==0 and col==0)) {
   
    initialization();

    int no_of_row;
    cin>>no_of_row;
    int rows[no_of_row];
    int no_of_col_per_row[no_of_row];
    int col_per_row;
   
    
    for (int i = 0; i < no_of_row; i++)
    {
        cin>>rows[i]>>no_of_col_per_row[i];
        for(int j=0;j<no_of_col_per_row[i];j++){
            cin>>col_per_row;
            grid[rows[i]][col_per_row]=1;
            visited[rows[i]][col_per_row]=1;
            
        }
    }

    int starting_row,starting_col,ending_row,ending_col;
    cin>>starting_row>>starting_col>>ending_row>>ending_col;
    visited[starting_row][starting_col]=1;
    level[starting_row][starting_col]=0;

    queue<pii>Q;
    Q.push(pii(starting_row,starting_col));

    while(!Q.empty()) {
    pii top=Q.front();
    Q.pop();
    
    for(int k=0;k<4;k++){
        int tx=top.first+fx[k];
        int ty=top.second+fy[k];

        if(tx>=0 and tx<row and ty>=0 and ty<col and visited[tx][ty]==0){
            visited[tx][ty]=1;
            level[tx][ty]=level[top.first][top.second]+1;
            Q.push(pii(tx,ty));
        }
    
    }

    }
    
 cout<<level[ending_row][ending_col]<<endl;
    

    
 }
}
/*
10 10
9
0 1 2
1 1 2
2 2 2 9
3 2 1 7
5 3 3 6 9
6 4 0 1 2 7
7 3 0 3 8
8 2 7 9
9 3 2 3 4
0 0
9 9
0 0
*/