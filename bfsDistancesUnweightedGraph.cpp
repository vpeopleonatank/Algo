std::vector<int> bfsDistancesUnweightedGraph(std::vector<std::vector<bool>> matrix, int startVertex)
{
	std::queue<int> Q ;
	Q.push(startVertex);
	std::vector<int> visit(matrix.size(), -1);
	visit[startVertex] = 0;
	while(Q.size()) {
		int u = Q.front(); Q.pop();
		for(int v = 0; v < matrix.size(); v++) {
			if(matrix[u][v] && visit[v] == -1) {
				visit[v] = visit[u] + 1;
				Q.push(v);
			}
		}
	}
	
	return visit;
}
