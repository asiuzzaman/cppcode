
// Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1337

#include<iostream>
using namespace std;

char Graph[505][505];
bool visited[505][505];

int M,N,Q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int x,int y){
    return (x>=1 and x<=M and y>=1 and y<=N and Graph[x][y]!='#' and visited[x][y]==false );
}

int ans;
int  DFS(int x,int y){
     
     visited[x][y]=true;
    if(Graph[x][y]=='C') ans++;

     for(int i=0;i<4;i++){
         int u1=x+dx[i];
         int u2=y+dy[i];
         if(valid(u1,u2) )
         {
             DFS(u1,u2);

        }
     }
     return ans;
}

int main(){
    
    ios_base::sync_with_stdio(false);
      cin.tie(NULL);
    int test;
    //cin>>test;
    scanf("%d",&test);

    for(int tc=1;tc<=test;tc++){

    //cin>>M>>N>>Q;
    scanf("%d%d%d",&M,&N,&Q);
    
     for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>Graph[i][j];
          
        }
            
    }
     
    // cout<<"Case "<<tc<<":"<<endl;
      printf("Case %d:\n",tc);
     for(int i=0;i<Q;i++){
        int x,y;cin>>x>>y;
         
         for(int p=1;p<=M;p++){
             for(int q=1;q<=N;q++){
                 visited[p][q]=false;
             }
         }
         

         ans=0;
      //  cout<<DFS(x,y)<<endl;
        printf("%d\n",DFS(x,y));

     }
    
    }
}
/*
14
3 2 1
..
##
CC
1 1

2 2 1
..
..
1 1

5 5 3
#####
#.CC#
#C.C#
#CC.#
#####
4 4
2 2
3 3

5 5 3
#####
#.C.#
#C.C#
#.C.#
#####
4 4
2 2
3 3

5 13 2
#############
#.C.C.C.C.C.#
######.######
#.C.C.C.C.C.#
#############
2 6
4 2

15 30 1
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............C...............
..............................
..............................
..............................
..............................
..............................
..............................
..............................
1 1

5 4 1
C..C
..CC
...C
..C.
CCCC
3 2


8 8 1
C..CCCC.
......CC
C....#.C
.CCC.CCC
.C..C.C.
CC.#C...
..CC....
CCC.C.C.
4 1

6 2 5
##
..
##
##
.#
.#
2 2
5 1
6 1
5 1
5 1
8 8 8
CCC#CC..
CCC.C..C
#....CC.
.CC..#C.
#C.....C
C.CC..CC
.CC....#
CCC##CC.
6 5
4 4
6 5
6 6
6 2
8 8
2 6
6 5
2 4 7
.##C
#.#.
2 2
2 2
1 1
2 2
1 1
2 4
2 2
8 8 8
CCC#CC..
CCC.C..C
#....CC.
.CC..#C.
#C.....C
C.CC..CC
.CC....#
CCC##CC.
6 5
4 4
6 5
6 6
6 2
8 8
2 6
6 5

5 4 1
C..C
..CC
...C
..C.
CCCC
3 2
4 5 3
..#..
.C#C.
##..#
..C#C
4 1
1 1
4 2

 */