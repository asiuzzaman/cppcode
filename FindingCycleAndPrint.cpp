#include <iostream>
using namespace std;
#define ll long long int

int Node, Edge;
int Grid[100][100];
bool visited[100];
bool recStack[100];
int store[100];
bool check[100];
int p;

bool CycleUtil(int u)
{
    if (!visited[u])
    {
        visited[u] = true;
        recStack[u] = true;

        for (int i = 1; i <= Node; i++)
        {    p=0;
            if (!visited[i] and Grid[u][i] and CycleUtil(i))
            {
                if(!check[i]) {
                    store[p++]=i;
                    check[i]=1;
                }
                return true;
            }
            else if (recStack[i] and Grid[u][i]) {
                if(!check[i]) {
                    store[p++]=i;
                    check[i]=1;
                }
                return true;
            }
        }
    }
    recStack[u] = false;
    return false;
}

bool isCycle()
{
    for (int i = 0; i < Node; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 1; i <= Node; i++)
    {
        if (CycleUtil(i))
            return true;
    }
    return false;
}
int main()
{
    cin >> Node >> Edge;
    for (int i = 0; i < Edge; i++)
    {
        int x, y;
        cin >> x >> y;
        Grid[x][y] = 1;
    }
    // for(int i=1;i<=Node;i++){
    //     for(int j=1;j<=Node;j++){
    //         cout<<Grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if (isCycle())
        cout << "Yes" << endl;
    else
        cout << "No " << endl;
    for(int i=0;i<p;i++){
        for(int j=i+1;j<p;j++){
            if(store[i]>store[j]){
                int t=store[i];
                store[i]=store[j];
                store[j]=t;
            }
        }
    }
    for(int i=0;i<p;i++){
        cout<<store[i]<<" ";
    }
   
}

/*


7 9
3 1
3 6
1 5
5 2
2 7
7 1
5 4
4 5
6 5

4 4 
1 2
2 3
3 4
1 4

6 7
1 2
1 5
2 3
3 4
4 6
6 2
5 3

4 6
3 1
1 2
2 3
1 3
3 4
4 4


 */