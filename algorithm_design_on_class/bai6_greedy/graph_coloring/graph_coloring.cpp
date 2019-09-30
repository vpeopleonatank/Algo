#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int num_of_edges, num_of_vertices, i, j;

// adjacency list
vector<vector<int>> graph;
vector<int> color;
bool vis[100011];

void ColorGraph() {
  color[0] = 0;
  for (i = 1; i < num_of_vertices; i++)
    color[i] = -1;

  bool unused[num_of_vertices];

  for (i = 0; i < num_of_vertices; i++)
    unused[i] = true;

  for (i = 1; i < num_of_vertices; i++) {
    for (j = 0; j < graph[i].size(); j++) {
      if (color[graph[i][j]] != -1)
        unused[color[graph[i][j]]] = false;
    }
    int cr;
    for (cr = 0; cr < num_of_vertices; cr++) {
      if (unused[cr] == true)
        break;
    }

    color[i] = cr;

    for (j = 0; j < graph[i].size(); j++) {
      if (color[graph[i][j]] != -1)
        unused[color[graph[i][j]]] = true;
    }
  }
}

int main() {
  freopen("in.graph_coloring", "r", stdin);
  freopen("out.graph_coloring", "w", stdout);

  int test_case;
  cin >> test_case;
  while (test_case--) {
    cin >> num_of_vertices >> num_of_edges;
    graph.resize(num_of_vertices);
    color.resize(num_of_vertices);
    memset(vis, 0, sizeof(vis));

    for (i = 0; i < num_of_edges; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }

    ColorGraph();

    for (i = 0; i < num_of_vertices; i++) {
      cout << "Vertex " << i << " is colored " << color[i] << endl;
    }
    cout << endl;
  }
}
