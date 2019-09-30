#include <iostream>
#include <climits>

#define MAX 10

using namespace std;

void PrintShortestPathValue(int dist[], int V) {
  for (int v = 0; v < V; v++) {
    cout << dist[v] << " ";
  }
  cout << endl;
}

void PrintPath(int path[], int V) {
  for (int v = 0; v < V; v++) {
    cout << path[v] << " ";
  }
  cout << endl;
}

// Function to find minimum value from the set of vertices not yet
// included in shortest path tree
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
  // array to store label
  int dist[V];

  bool Sset[V];
  int path[V];

  for (int i = 0; i < V; i++) {
    dist[i] = 99999;
    Sset[i] = false;
  }
  dist[start] = 0;

  int current_position = 0;
  for (int count = 0; count < V - 1; count++) {
    int min_index = GetMinDistance(dist, Sset, V);
    Sset[min_index] = true;
    path[current_position] = min_index;
    current_position++;

    for (int v = 0; v < V; v++) {
      if (!Sset[v] && graph[min_index][v] != 0 && dist[min_index] != 99999
          && dist[min_index] + graph[min_index][v] < dist[v])
        dist[v] = dist[min_index] + graph[min_index][v];
    }
  }
  path[current_position] = GetMinDistance(dist, Sset, V);
  PrintPath(path, V);
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
      for (int j = 0; j < V; j++) {
        cin >> graph[i][j];
      }
    }

    Dijkstra(graph, 0, V);
  }
}
