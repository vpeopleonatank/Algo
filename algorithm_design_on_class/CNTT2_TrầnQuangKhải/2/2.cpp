#include <iostream>
#include <algorithm>

using namespace std;

struct Activity {
  int pos, start, finish;
};

bool CompareActivity(Activity a1, Activity a2) {
  return (a1.finish) < (a2.finish);
}

void SelectActivity(Activity act[], int num_of_activities) {

  // sắp xếp các hoạt động theo thời gian kết thúc
  sort(act, act+num_of_activities, CompareActivity);

  int i = 0;
  cout << act[i].pos << " ";

  for (int j = 1; j < num_of_activities; j++) {
    if (act[j].start > act[i].finish) {
      cout << act[j].pos << " ";
      i = j;
    }
  }
  cout << endl;
}

int main() {
  freopen("in.2", "r", stdin);
  freopen("out.2", "w", stdout);  

  int test_case;
  cin >> test_case;
  while(test_case--) {
    int num_of_activities;
    cin >> num_of_activities;
    Activity act[num_of_activities];
    for(int i = 0; i < num_of_activities; i++) {
      cin >> act[i].start >> act[i].finish;
      act[i].pos = i;
    }
    SelectActivity(act, num_of_activities);
  }
}

