#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100003];
bool visited[100003];
int nodes;

void DFS(int n)
{

    nodes++;
    //cout<<nodes<<endl;
    visited[n] = true;
    for(int i=0;i<adj[n].size();i++)
    {   
        int temp=adj[n][i];
       
        if(!visited[temp])
            DFS(temp);
    }
}

void Initilization(){
    memset(visited,false,sizeof(visited));
    memset(adj,0,sizeof(adj));
}

int main()
{
        int T;cin>>T;
        while(T--) {
            Initilization();
        int N,M,a,b;
        long X,Y;
        cin >> N >> M >> X >> Y;

        for(int i = 0 ; i < M ; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
       
       long cost=0;

        for(int i = 1 ; i <= N ; i++)
        {
            if(!visited[i])
            {
                nodes = 0;
                DFS(i);
                
                cost = cost + X;
               // cout<<cost<<endl;
               
                if(X > Y)
                    cost = cost + (Y*(nodes-1));
                else
                    cost = cost + (X*(nodes-1));
                
               // cout<<cost<<" ";
            }
        }

        cout << cost << endl;


        }

    return 0;
}

/*
 6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6
*/