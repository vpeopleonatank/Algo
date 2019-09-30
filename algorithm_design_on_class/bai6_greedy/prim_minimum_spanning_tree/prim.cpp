#include <bits/stdc++.h>
#define MAX 10

using namespace std;

void PrintMST(int root[], int graph[][MAX], int V) {
  cout << "Canh     Trong so\n";
  for (int i = 1; i < V; i++) {
    cout << root[i] << " - " << i << "    " << graph[i][root[i]] << endl;
  }
}

int GetMinIndex(int key[], bool MSTset[], int V) {
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++) {
    if (MSTset[v] == false && key[v] < min) {
      min = key[v];
      min_index = v;
    }
  }

  return min_index;
}

void Prim(int graph[][MAX], int V) {
  int root[V];
  // array to store label at current state
  int key[V];
  bool MSTset[V];

  for (int i = 0; i < V; i++) {
    key[i] = INT_MAX;
    MSTset[i] = false;
    root[i] = 0;
  }

  key[0] = 0;
  root[0] = -1;

  for (int count = 0; count < V - 1; count++) {
    int min_index = GetMinIndex(key, MSTset, V);
    MSTset[min_index] = true;

    for (int v = 0; v < V; v++) {
      if (graph[min_index][v] && MSTset[v] == false && graph[min_index][v] < key[v]) {
        root[v] = min_index;
        key[v] = graph[min_index][v];
      }
    }
  }

  PrintMST(root, graph, V);
}

int main() {
  freopen("in.prim", "r", stdin);
  freopen("out.prim", "w", stdout);

  int test_case;
  cin >> test_case;
  while(test_case--) {
    int V;
    cin >> V;
    int graph[MAX][MAX];

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        cin >> graph[i][j];
      }
    }
    Prim(graph, V);
  }
}

