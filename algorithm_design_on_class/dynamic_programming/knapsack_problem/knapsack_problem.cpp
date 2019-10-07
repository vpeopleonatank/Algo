#include <bits/stdc++.h>

using namespace std;

#define MAX 30
int MaxV[MAX][MAX];
int num_of_items, maximum_size_of_bag;
int picked_items[MAX], num_of_picked_items;

struct item {
  int c, w;
};

item items[MAX];

void Pick() {
  int i, j;
  num_of_picked_items = 0;
  for(i = 0; i <= num_of_items; i++) {
    MaxV[i][0] = 0;
  }
  for(i = 0; i < maximum_size_of_bag; i++) {
    MaxV[0][i] = 0;
  }
  for(i = 1; i <= num_of_items; i++) {
    for(j = 1; j <= maximum_size_of_bag; j++) {
      MaxV[i][j] = MaxV[i-1][j];
      
      if((j >= items[i-1].w) && (MaxV[i-1][j-items[i-1].w] + items[i-1].c > MaxV[i-1][j])) {
        MaxV[i][j] = MaxV[i-1][j-items[i-1].w] + items[i-1].c;
      }
    }
  }

  int total_weight = 0;

  int w = maximum_size_of_bag;
  int res = MaxV[num_of_items][maximum_size_of_bag];
  for(i = num_of_items; i > 0 && res > 0; i--) {
    if (res == MaxV[i-1][w]) {
      continue;
    } else {
      total_weight += items[i-1].w;
      picked_items[num_of_picked_items] = i-1;
      num_of_picked_items++;
      res -= items[i-1].c;
      w -= items[i-1].w;
    }
  }

  for(i = num_of_picked_items-1; i >= 0; i--) {
    cout << picked_items[i] << " ";
  }

  cout << endl;
  cout << "Total weight and value " << total_weight << " " << MaxV[num_of_items][maximum_size_of_bag];
  cout << endl;
  for(int i=0;i<= num_of_items; i++) {
    for(int j=0;j<=maximum_size_of_bag; j++) {
      cout << MaxV[i][j] << " ";
    }
    cout << endl;
  }

}

int main() {
  freopen("in.knapsack", "r", stdin);
  freopen("out.knapsack", "w", stdout);

  int test_case;
  cin >> test_case;
  while(test_case--) {
    cin >> num_of_items >> maximum_size_of_bag;
    for(int i = 0; i < num_of_items; i++) {
      cin >> items[i].c >> items[i].w;
    }
    //cout << num_of_items << " " << maximum_size_of_bag;
    //for(int i = 0; i < num_of_items; i++) {
    //  cout << items[i].c << " " << items[i].w<< endl;
    //}
    Pick();
  }
}

