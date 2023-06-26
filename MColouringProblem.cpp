#include <bits/stdc++.h>

bool dfs(int cur, vector<int> &col, vector<int> &vis,int &m, vector<vector<int>> &mat)
{
    vis[cur] = 1;
    for(int c = 1; c <= m; c++)
    {
        bool ans = true;
        col[cur] = c;
        for(int adj = 0; adj < mat[0].size(); adj++)
        {
            if(mat[cur][adj] == 1)
            {
                if (col[adj] == col[cur]) {
                    ans = false;
                    break;
                }
                if (col[adj] > 0)
                    continue;
                if (!dfs(adj, col, vis, m, mat)) {
                    ans = false;
                    break;
                }
            }
        }
        col[cur] = 0;
        if(ans)
            return true;
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int> col(mat.size()), vis(mat.size());
    for(int i = 0; i < mat.size(); i++)
    {
        if (vis[i] == 0) {
            if (!dfs(i, col, vis, m, mat))
                return "NO";
        }
    }
    return "YES";
}
