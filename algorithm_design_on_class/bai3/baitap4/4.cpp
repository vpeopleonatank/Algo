#include <iostream>

using namespace std;

void ReadMatrix(int n, int a[][100]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
}

void WriteMatrix(int n, int a[][100]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

void MulMatrix(int n, int a[][100], int b[][100], int c[][100]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = 0;
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

int main() {
  freopen("4.in", "r", stdin);
  freopen("4.out", "w", stdout);

  int n;
  cin >> n;
  int a[n][100], b[n][100], c[n][100];
  ReadMatrix(n, a);
  ReadMatrix(n, b);
  MulMatrix(n, a, b, c);
  WriteMatrix(n, c);
}
