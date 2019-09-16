#include <iostream>
#include <limits.h>

#define MAX 10

using namespace std;

void PrintPath(int dist[], int V) {
  for (int v = 0; v < V; v++) {
    cout << dist[v] << " ";
  }
}

int GetMinDistance(int dist[], bool Sset[], int V) {
  int min = 99999, min_index;

  for (int v = 0; v < V; v++) {
    if (Sset[v] == false && dist[v] <= min) {
      min = dist[v];
      min_index = v;
    }
  }

  return min_index;
}

void Dijkstra(int graph[][10], int start, int V) {
  int dist[V];

  bool Sset[V];
  int path[V];

  for (int i = 0; i < V; i++) {
    dist[i] = 99999;
    Sset[i] = false;
  }
  dist[start] = 0;
  path[0] = start;

  for (int count = 0; count < V - 1; count++) {
    int min_index = GetMinDistance(dist, Sset, V);
    Sset[min_index] = true;

    for (int v = 0; v < V; v++) {
      if (!Sset[min_index] && graph[min_index][v] && dist[min_index] != 99999
          && dist[min_index] + graph[min_index][v] < dist[v])
        dist[v] = dist[min_index] + graph[min_index][v];
    }
  }
  PrintPath(dist, V);
}

int main() {
  freopen("in.shortestpath", "r", stdin);
  freopen("out.shortestpath", "w", stdout);
  int num_test;
  cin >> num_test;
  while(num_test--) {
    int V;
    cin >> V;
    int graph[MAX][MAX];
    for (int i = 0; i < V; i++) {
      cin >> graph[i][i];
    }
    Dijkstra(graph, 0, V);
  }
}
