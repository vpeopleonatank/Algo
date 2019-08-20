#include <iostream>

using namespace std;

string Scoretostring(char str[100]) {
    int i = 0, lnum = 0;
    int a[100];
    while (str[i] != '.') {
      lnum++;
      a[i] = str[i] - 48;
    }

}

int main() {
  string a[10] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    //freopen("3.in", "r", stdin);
    //freopen("3.out", "w", stdout);
    float num;
    cin >> num;
    char str[100];
    //sprintf(str, "%f", num);
    //cout << Scoretostring(str);
    cout << a[0];
}

