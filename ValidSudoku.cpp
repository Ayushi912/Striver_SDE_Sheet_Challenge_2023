#include <vector>
bool solve(int r, int c, vector<int> &row, vector<int> &col, vector<int> &sub, int mat[9][9])
{
    if(r == 9)
        return true;
    if(c == 9)
        return solve(r + 1, 0, row, col, sub, mat);
    if(mat[r][c] > 0)
        return solve(r, c + 1, row, col, sub, mat);
    bool ans = false;
    for(int i = 1; i <= 9; i++)
    {
        bool fl1 = row[r] & (1 << i);
        bool fl2 = col[c] & (1 << i);
        int pos = (r / 3) * 3 + (c / 3);
        bool fl3 = sub[pos] & (1 << i);
        if(!fl1 && !fl2 && !fl3)
        {
            row[r] |= (1 << i);
            col[c] |= (1 << i);
            sub[pos] |= (1 << i);
            mat[r][c] = i;
            ans = ans || solve(r, c + 1, row, col, sub, mat);
            mat[r][c] = 0;
            row[r] &= ~(1 << i);
            col[c] &= ~(1 << i);
            sub[pos] &= ~(1 << i);
        }
    }
    return ans;
}

bool isItSudoku(int mat[9][9]) {
    // Write your code here.
    vector<int> row(9), col(9), sub(9);
    for(int r = 0; r < 9; r++)
    {
        for(int c = 0; c < 9; c++)
        {
            if(mat[r][c] > 0)
            {
                row[r] |= (1 << mat[r][c]);
                col[c] |= (1 << mat[r][c]);
                int pos = (r / 3) * 3 + (c / 3);
                sub[pos] |= (1 << mat[r][c]);
            }
        }
    }
    return solve(0, 0, row, col, sub, mat);
}
