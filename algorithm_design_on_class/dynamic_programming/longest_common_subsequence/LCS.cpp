#include <bits/stdc++.h>

using namespace std;

int lcs(string &a, string &b) {
  int m = a.size(), n = b.size();

  a = ' ' + a;
  b = ' ' + b;

  vector< vector<int> > f(m+1, vector<int>(n+1, 0));


  for (int i=1; i<=m; i++) {
    for (int j=1; j<=n; j++) {
      if (a[i] == b[j]) {
        f[i][j] = f[i-1][j-1] + 1;
      } else {
        f[i][j] = max(f[i-1][j], f[i][j-1]);
      }  
    }
  }
  cout << endl;
  for(int i=1;i<=m;i++) {
    for(int j=1;j<=n;j++) {
      cout << f[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  int index = f[m][n];
  char lcs[index+1];
  lcs[index] = '\0';

  int i = m, j = n;
  while(i > 0 && j > 0) {
    if(a[i] == b[j]) {
      lcs[index-1] = a[i];
      i--; j--;
      index--;
    } else if(f[i-1][j] > f[i][j-1]) {
      i--;
    } else {
      j--;
    }
  }

  cout << lcs << endl;

  return f[m][n];
}

int main() {
  freopen("in.lcs", "r", stdin);
  freopen("out.lcs", "w", stdout);

  int test_case;
  cin >> test_case;
  while(test_case--) {
    string a, b;
    cin.ignore();
    getline(cin, a);
    cin.ignore();
    getline(cin, b);
    cout << endl << a << endl << b << endl;
    //cin >> a;
    //cin >> b;
    cout << lcs(a, b) << endl;
    
  }
}

