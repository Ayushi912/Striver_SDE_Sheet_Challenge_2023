void solve(int r, int &d1, int &d2, int &col, vector<int> &v, int &n, vector<vector<int>> &ans)
{
    if(r == n)
    {
        ans.push_back(v);
        return;
    }

    for(int c = 0; c < n; c++)
    {
        bool fl1 = col & (1 << c);
        bool fl2 = d1 & (1 << (r + c));
        bool fl3 = d2 & (1 << (r - c + n - 1));
        if(!fl1 && !fl2 && !fl3)
        {
            col |= (1 << c);
            d1 |= (1 << (r + c));
            d2 |= (1 << (r - c + n - 1));
            v[r * n + c] = 1;
            solve(r + 1, d1, d2, col, v, n, ans);
            v[r * n + c] = 0;
            col &= ~(1 << c);
            d1 &= ~(1 << (r + c));
            d2 &= ~(1 << (r - c + n - 1));
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<int> v(n * n);
    vector<vector<int>> ans;
    int d1 = 0, d2 = 0, col = 0;
    solve(0, d1, d2, col, v, n, ans);
    return ans;
}
