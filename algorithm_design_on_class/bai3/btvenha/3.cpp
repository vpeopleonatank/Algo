#include <iostream>
#include <string>

using namespace std;


string a[10] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};

void Scoretostring(string num, int roundingTill) {
  int j = 0;
  bool isAfterDot = false;
  for (int i = 0; i < num.length(); i++) {
    if (num[i] == '.') {
      cout << "phay ";
      isAfterDot = true;
      continue;
    }
    if (!isAfterDot) {
      if (num[i] == '1' && num[i+1] == '0') {
        cout << "muoi" << " ";
        i++;
        continue;
      }  
      cout << a[num[i] - 48] << " ";
    } else {
      if (j < roundingTill) {
      cout << a[num[i] - 48] << " ";
      j++;
      }
    }
  }
}

int main() {
  freopen("3.in", "r", stdin);
  freopen("3.out", "w", stdout);
  string num;
  cin >> num;
  Scoretostring(num, 1);

}

