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

bool findPath(std::vector<std::vector<int>> matrix)
{
  int c = 1, n = matrix.size(), m = matrix[0].size(), i = 0, j = 0;
  for(int w = 0; w < n; w++) {
    bool done = false;
    for(int e = 0; e < m; e++) {
      if(matrix[w][e] == 1) {
        i = w, j = e;
        done = true;
        break;
      }
    }
    if(done) break;
  }
  vector<vector<bool>> d(n, vector<bool>(m));
  d[0][0] = true;
  vector<int> dx = {-1, 1};
  while (c != n * m)
  {
    bool s = false;
    for (int k = 0; k < dx.size(); k++)
    {
      if (j + dx[k] >= 0 && j + dx[k] < m && matrix[i][j + dx[k]] == c + 1)
      {
        s = true;
        j = j + dx[k];
        break;
      }
      if (i + dx[k] >= 0 && i + dx[k] < n && matrix[i + dx[k]][j] == c + 1)
      {
        s = true;
        i = i + dx[k];
        break;
      }
    }

    if (s)
    {
      c += 1;
    }
    else
    {
      return false;
    }
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int i, j;
  vector<vector<int>> a = {{5,4,3,2,1}};

  cout << findPath(a);

  return 0;
}
