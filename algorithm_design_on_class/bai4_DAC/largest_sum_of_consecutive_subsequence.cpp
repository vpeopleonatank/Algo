#include <bits/stdc++.h>

using namespace std;

int GetMax3(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int MaxLeftVector(int a[], int i, int j) {
    int maxSum = -32147;
    int sum = 0;
    for (int k = j; k >= i; k--) {
        sum = sum + a[k];
        maxSum = max(sum, maxSum);
    }

    return maxSum;
}

int MaxRightVector(int a[], int i, int j) {
    int maxSum = -32147;
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum = sum + a[k];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

int s, e;
int MaxSubVector(int a[], int i, int j) {
    if (i == j) return a[i];
    else {
        int m = (i+j)/2;
        int WL = MaxSubVector(a,i,m);
        int WR = MaxSubVector(a,m+1,j);
        int WM = MaxLeftVector(a,i,m) + MaxRightVector(a,m+1,j);
        int max3 = GetMax3(WL, WR, WM);
        if (max3 == WL) {
            s = i;
            e = m;
        } else if (max3 == WR) {
            s = m+1;
            e = j;
        } else if (max3 == WM){
            s = i;
            e = j;
        }
        
        return max3;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    s = -31247;
    e = -32147;
    while (n--) {
        int m;
        cin >> m;
        int a[m];
        for (int i = 0; i <m; i++) {
            cin >> a[i];
        }
        cout << MaxSubVector(a,0,m-1) <<  " " << s << " " << e << endl;
    }
}
