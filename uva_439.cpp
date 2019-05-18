#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>

int fx[]={2,2,1,-1,1,-1,-2,-2}; 
int fy[]={1,-1,2,2,-2,-2,-1,1};

int visited[10][10];    
int level[10][10];

void initialization(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            level[i][j]=0;
            visited[i][j]=0;
        }
    }
}    

int main(){

    string s1,s2;
    while(cin>>s1>>s2) {

    initialization();
    int x1=s1[0]-'a'+1;
    int y1=s1[1]-'0';
    int x2=s2[0]-'a'+1;
    int y2=s2[1]-'0';

   
    level[x1][y1]=0;
    queue<pii>Q;
    Q.push(pii(x1,y1));
    visited[x1][y1]=1;
    
    while(!Q.empty()) {
    pii top=Q.front();
    Q.pop();

    for(int k=0;k<8;k++){
        int tx=top.first+fx[k];
        int ty=top.second+fy[k];
       
       if(tx>0 and tx<=8 and ty>0 and ty<=8 and visited[tx][ty]==0){
          //  cout<<tx<<" "<<ty<<endl;
            level[tx][ty]=level[top.first][top.second]+1;
            Q.push(pii(tx,ty));
            visited[tx][ty]=1;
        }
    
    }

    }
    
    cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<level[x2][y2]<<" knight moves."<<endl;
    
   }
 }

/*
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

*/