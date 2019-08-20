#include <iostream>

using namespace std;

string Scoretostring1(char str[100]) {
    int i = 0;
    int a[100];
    while (str[i] != '.') {
        a[i] = str[i] - 48;
    }

}

int main() {
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
    float num;
    cin >> num;
    char str[100];
    sprintf(str, "%f", num);
    cout << Scoretostring1(num);
}
