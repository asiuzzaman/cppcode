#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 8
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int mat[N][N];

void _init()
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat[i][j] = -1;
        }
    }
}

bool valid(int x, int y)
{
    return (x >= 0 and x < N and y >= 0 and y < N and mat[x][y] == -1);
}

void PrintSol()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int call = 0;
bool SolveUtil(int x, int y, int movei)
{

    if (movei == N * N)
        return true;
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (valid(xx, yy))
        {

            mat[xx][yy] = movei;
            // PrintSol();
            if (SolveUtil(xx, yy, movei + 1))
                return true;
            else
                mat[xx][yy] = -1;
        }
    }
    return false;
}

int main()
{
    _init();
    mat[0][0] = 0;

    SolveUtil(0, 0, 1);
    PrintSol();
}