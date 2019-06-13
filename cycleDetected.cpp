#include <iostream>
using namespace std;
int Graph[55][55];
bool visited[55];
int N, E; // size of the matrix...

bool DFS(int x)
{
    if (visited[x])
    {
        return true;
    }
   // cout<<x<<endl;
    visited[x] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (Graph[x][i])
        {
            if (DFS(i))
                return true;
        }
    }
    return false;
}

int main()
{

    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph[x][y] = 1;
    }
       for(int i=1;i<=N;i++) {
        for (int k = 1; k <= N; k++)
        {
            visited[k] = 0;
        }
        if (DFS(i))
            cout << "Detected...." << endl;
        else
            cout << "No" << endl;
       }
}
/*

7 7
1 2
2 3
3 4
4 5
5 1
6 7
6 6


 */