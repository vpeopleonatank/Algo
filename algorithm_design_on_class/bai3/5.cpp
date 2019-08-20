// Tinh dinh thuc cua ma tran vuong cap n
#include <iostream>
#include <math.h>

using namespace std;

void ReadMatrix(int n, int  a[][100]) {
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

int determinant( int matrix[][100], int n) {   
   int det = 0;
   int submatrix[100][100];
   if (n == 2)
      return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
            int subi = 0; 
            for (int i = 1; i < n; i++) {
               int subj = 0;
               for (int j = 0; j < n; j++) {
                  if (j == x)
                      continue;
                  submatrix[subi][subj] = matrix[i][j];
                  subj++;
               }
               subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return det;
}

void CalDet(int n, int c[][100]) {
    
}

int main() {
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
    
    int n;
    cin >> n;
    int a[n][100];
    ReadMatrix(n,a);
    //cout << CalDet(n, c);
    cout << determinant(a, n);

}
