#include <iostream>
#include <algorithm>

using namespace std;

struct Activity {
  int start, finish;
};

bool CompareActivity(Activity a1, Activity a2) {
  return (a1.finish-a1.start) < (a2.finish-a2.start);
}

void SelectActivity(Activity act[], int num_of_activities) {
  sort(act, act+num_of_activities, CompareActivity);

  int i = 0;
  cout << i << " ";

  for (int j = 1; j < num_of_activities; j++) {
    if (act[j].start > act[i].finish) {
      cout << j << " ";
      i = j;
    }
  }
  cout << endl;
}

int main() {
  freopen("in.xeplich", "r", stdin);
  freopen("out.xeplich3", "w", stdout);  

  int test_case;
  cin >> test_case;
  while(test_case--) {
    int num_of_activities;
    cin >> num_of_activities;
    Activity act[num_of_activities];
    SelectActivity(act, num_of_activities);
  }
}

