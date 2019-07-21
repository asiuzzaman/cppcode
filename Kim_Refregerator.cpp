
//. Write a program that, starting at the office,
// finds a (the) shortest path visiting all the customers and returning to his home. 
//Your program only have to report the distance of a (the) shortest path.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int x[20],y[20],n,ans;

int Dis(int i,int j){
    int x1=x[i];
    int y1=y[i];
    int x2=x[j];
    int y2=y[j];
    return abs(x1-x2)+abs(y1-y2);
}

int cnt=0;
void OptimalPath(int x,bool visited[],int nodes,int value){
   
    if(n==nodes) ans=min(ans,value+Dis(x,n+1)); 
       
      for(int i=1;i<=n;i++) {
          //if(visited[i]) cout<<"Visited: i :" <<i<<endl; 
        if(!visited[i]){
            visited[i]=true;
            OptimalPath(i,visited,nodes+1,value+Dis(i,x));
            visited[i]=false;
        }
        
    }
}
 
int main() {
    int t;
    cin>>t;

    for(int cs=1;cs<=t;cs++){
        
        ans=INT_MAX;
        cin>>n;
        cin>>x[n+1]>>y[n+1]>>x[0]>>y[0];
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
        }
        bool visited[n+2];
        for(int i=0;i<n+2;i++) visited[i]=false;
        OptimalPath(0,visited,0,0);
        cout<<"Case "<<cs<<": "<<endl;
        cout<<ans<<endl;

    }
}

/*
1

5 
0 0 100 100
70 40 
30 10
10 5
90 70
50 20

10
39 9 97 61 
35 93
62 64
96 39
36 36
9 59
59 96
61 7
64 43
43 58 
1 36

6
88 81 85 80
19 22 
31 15 
27 29 
30 10 
20 26 
5 14




 */