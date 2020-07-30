int componentSize(std::vector<std::vector<bool>> matrix, int vertex)
{
    queue <int> q;
    q.push(vertex);
    int visit[matrix.size()] = {0};
    visit[vertex] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[u][i] && visit[i] == 0) {
                q.push(i), visit[i] = visit[u] + 1;
            }
        }
    }
    int m = 0;
    for(int i = 0; i < matrix.size(); i++) {
			if(visit[i] != 0) m++;
    }
    return m;
}
