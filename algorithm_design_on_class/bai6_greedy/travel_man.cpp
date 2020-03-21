#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;

int TravelMan(int a[][10], int n, int tour[MAX], int dinhDau) {
  int v,    // Dinh dang xet
      k,    // DUyet qua n dinh de chon
      w;    // Dinh duoc chon trong moi buoc
  int mini; // Chon min cac canh(cung) trong moi buoc
  int COST; // Trong so nho nhat cua chu trinh
  int daxet[MAX];

  for (k = 0; k < n; k++) {
    daxet[k] = 0; // Chua dinh nao duoc xet
  }
  COST = 0; // Luc dau, gia tri COST == 0

  int i;       // Bien dem, dem tim du n dinh thi dung
  v = dinhDau; // Chon dinh xuat phat la dinhDau
  i = 1;
  tour[i] = v;  // Dua v vao chu trinh
  daxet[v] = 1; // Dinh v da duoc xet
  while (i < n) {
    mini = 32147;
    for (k = 0; k < n; k++) {
      if (!daxet[k])
        if (mini > a[v][k]) {
          mini = a[v][k];
          w = k;
        }
    }
    v = w;
    i++;
    tour[i] = v;
    daxet[v] = 1;
    COST += mini;
  }
  COST += a[v][dinhDau];
  return COST;
}

int main() {
  freopen("in.travelman", "r", stdin);
  // freopen("out.travelman", "w", stdout);

  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    int a[MAX][MAX];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    int tour[MAX];
    cout << TravelMan(a, m, tour, 0) << endl;
    for (int i = 1; i <= m; i++) {
      cout << tour[i] << " ";
    }
  }
}
