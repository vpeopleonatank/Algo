#include <bits/stdc++.h>
#define MAX 10

using namespace std;

// Hàm in giá trị MST được xây dựng lưu trong mảng root
void PrintMST(int root[], int graph[][MAX], int V) {
  cout << "Duong cap     Chi phi\n";
  int sum = 0;
  for (int i = 1; i < V; i++) {
    sum += graph[i][root[i]];
    cout << root[i] << " - " << i << "          " << graph[i][root[i]] << endl;
  }
  cout << "tong chi phi xay dung he thong cap la " << sum << endl;
}

// Hàm tìm đỉnh với giá trị nhỏ nhất, từ tập các đỉnh không thuộc MST
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

// Hàm dựng và in MST cho dữ liệu lưu dưới dạng 
// ma trận kề
void Prim(int graph[][MAX], int V) {
  // mảng lưu giá trị MST được xây dựng
  int root[V];
  // mảng lưu nhãn tại trạng thái hiện tại 
  int key[V];
  // mảng kiểm tra đỉnh i đã được thêm vào MST chưa
  bool MSTset[V];

  for (int i = 0; i < V; i++) {
    // khởi tạo các khóa giá trị vô cùng lớn
    key[i] = INT_MAX;
    MSTset[i] = false;
    root[i] = 0;
  }

  // thêm đỉnh đầu vào MST
  key[0] = 0;
  root[0] = -1;

  // MST có V đỉnh
  for (int count = 0; count < V - 1; count++) {
    // chọn đỉnh có giá trị khóa nhỏ nhất mà chưa nằm trong MST
    int min_index = GetMinIndex(key, MSTset, V);
    // thêm đỉnh đã được chọn vào MST
    MSTset[min_index] = true;

    // cập nhật giá trị khóa và chỉ số cha của các đỉnh kề của đỉnh được chọn
    // chỉ xét những đỉnh chưa thuộc MST
    for (int v = 0; v < V; v++) {
      // graph[u][v] ko là 0 chỉ đối với đỉnh kề của min_index 
      // MSTset[v] là sai đối với các đỉnh chưa thuộc MST
      // Cập nhật khóa chỉ khi graph[u][v] nhỏ hơn key[v]
      if (graph[min_index][v] && MSTset[v] == false && graph[min_index][v] < key[v]) {
        root[v] = min_index;
        key[v] = graph[min_index][v];
      }
    }
  }

  PrintMST(root, graph, V);
}

int main() {
  freopen("in.1", "r", stdin);
  freopen("out.1", "w", stdout);

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

