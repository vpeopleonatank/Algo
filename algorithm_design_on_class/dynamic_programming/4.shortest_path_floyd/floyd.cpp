#include <bits/stdc++.h>

using namespace std;

#define MAX 30

int a[MAX][MAX], n, p[MAX][MAX], d[MAX][MAX], s, e;
void floyd() {
  int i, j, k;
  // init matrix d and p
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      if(a[i][j] < INT_MAX) {
        d[i][j] = a[i][j];
        p[i][j] = 0;
      }
    }
  }

  for(k = 1; k <= n; k++) { // calculate matrix d and p at k step
    for(i = 1; i <= n; i++) {
      if(d[i][k] > 0 && d[i][k] < INT_MAX) {
        for(j = 1; j <= n; j++) {
          if(d[k][j] > 0 && d[k][j] < INT_MAX) {
            if(d[i][k] + d[k][j] < d[i][j]) {
              d[i][j] = d[i][k] + d[k][j];
              p[i][j] = k;
            }
          }
        }
      }
    }
  }

  cout << endl;
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  cout << endl;
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      cout << p[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  stack <int>path;
  // trace back
  path.push(e);
  while (1) {
    if(p[s][e] == 0) {
      //cout << e;
      path.push(s);
      break;
    }
    //cout << p[s][e] << " ";
    path.push(p[s][e]);
    e = p[s][e];
  }
  while(!path.empty()) {
    cout << path.top() << " ";
    path.pop();
  }
  cout << endl;
  
}

int main() {
  freopen("in.floyd", "r", stdin);
  freopen("out.floyd", "w", stdout);

  int test_case;
  cin >> test_case;
  while(test_case--) {
    cin >> n >> s >> e;
    //cout << s << " " << e << endl;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }

    floyd();
  }
}

