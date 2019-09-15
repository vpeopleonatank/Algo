#include <iostream>

using namespace std;

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    
    float a, b, c, d, e, f, x, y;
    cin >> a >> b >> c >> d >> e >> f;
    
    y = (f - (d*c)/a)/(e-(d*b)/a);
    x = c- b*y/a;
    cout << "y: " << y << endl;
    cout << "x: " << x << endl;

}
