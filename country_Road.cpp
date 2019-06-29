#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node
{
    int u, w;
    Node(int p, int q)
    {
        u = p;
        w = q;
    }
    bool operator<(const Node &p) const
    {
        return p.w < w;
    }
};

vector<int> Graph[505];
vector<int> Cost[505];
int node, edge;
int dist[505];

void DJ(int src)
{
    for (int i = 0; i < 505; i++)
    {
        dist[i] = 20005;
    }
    priority_queue<Node> Q;
    Q.push(Node(src, 0));
    dist[src] = 0;
    while (!Q.empty())
    {
        Node T = Q.top();
        Q.pop();
        int u = T.u;
        for (int i = 0; i < Graph[u].size(); i++)
        {
            int v = Graph[u][i];
            int temp = max(dist[u], Cost[u][i]);
            if (temp < dist[v])
            {
                dist[v] = temp;
                Q.push(Node(v, dist[v]));
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i <<":"<< endl;
        cin >> node >> edge;
        for (int i = 0; i < edge; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            Graph[x].push_back(y);
            Graph[y].push_back(x);
            Cost[x].push_back(w);
            Cost[y].push_back(w);
        }
        int src;
        cin >> src;
        DJ(src);
        for (int i = 0; i < node; i++)
        {
            if (dist[i] == 20005)
                cout << "Impossible" << endl;
            else
                cout << dist[i] << endl;
        }
        for (int i = 0; i < node; i++)
        {
            Graph[i].clear();
            Cost[i].clear();
        }
    }
}
/*

5 6
0 1 5
0 1 4
2 1 3
3 0 7
3 4 6
3 1 8

*/