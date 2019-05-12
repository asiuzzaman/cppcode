/*
LIght oJ: 1009: Back to underworld.......
Logic: Parent and child are color with different color using the implementation of simple BFS approach.
 Than count the maximum different color
*/


#include<bits/stdc++.h>
using namespace std;
#define SZ 20005

vector<int>graph[SZ];
int color[SZ];

int main(){
    int tc;cin>>tc;
    for(int cs=1;cs<=tc;cs++)
    {
     
        memset(color,0,sizeof(color));
        for(int i=0;i<SZ;i++){
            graph[i].clear();
        }

        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
          int mx=0;
        for(int i=0;i<SZ;i++){
            if(!graph[i].empty() and color[i]==0){
                
              int  black=0,red=0;
                queue<int>Q;
                Q.push(i);
                color[i]=1;
                black++;

                while (!Q.empty())    
                {
                    int parent=Q.front();
                    Q.pop();

                    for(int j=0;j<graph[parent].size();j++){

                        int child=graph[parent][j];
                        if(color[child]==0){
                             Q.push(child);

                             if(color[parent]==1){
                                 color[child]=2;
                                 red++;
                             }
                             else {
                                 color[child]=1;
                                 black++;
                             }
                        }
                       
                    }
                }
            mx+=max(red,black);
                

            }
        }
        
        cout<<"Case "<<cs<<":"<<" ";
        cout<<mx<<endl;

    }
    
}