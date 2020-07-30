#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

bool sudokuChecking(std::vector<std::vector<char>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        vector<bool> m(9);
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[j][i] != '.')
            {
                if (m[(int)grid[j][i] - '1'])
                    return false;
                m[(int)grid[j][i] - '1'] = true;
            }
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {
        vector<bool> m(9);
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[i][j] != '.')
            {
                if (m[(int)grid[i][j] - '1'])
                {
                    return false;
                }
                m[(int)grid[i][j] - '1'] = true;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        vector<bool> m(9);
        for (int j = i / 3 * 3; j < i / 3 * 3 + 3; j++)
        {
            for (int k = i % 3 * 3; k < i % 3 * 3 + 3; k++)
            {
                // deb2(i, j);
                deb(grid[j][k]);
                if (grid[j][k] != '.')
                {
                    if (m[(int)grid[j][k] - '1'])
                    {
                        return false;
                    }

                    m[(int)grid[j][k] - '1'] = true;
                }
            }
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j;
    vector<vector<char>> a = {{'.', '.', '.', '1', '4', '.', '.', '2', '.'},
                              {'.', '.', '6', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '1', '.', '.', '.', '.', '.', '.'},
                              {'.', '6', '7', '.', '.', '.', '.', '.', '9'},
                              {'.', '.', '.', '.', '.', '.', '8', '1', '.'},
                              {'.', '3', '.', '.', '.', '.', '.', '.', '6'},
                              {'.', '.', '.', '.', '.', '7', '.', '.', '.'},
                              {'.', '.', '.', '5', '.', '.', '.', '7', '.'}};

    cout << sudokuChecking(a);

    return 0;
}
