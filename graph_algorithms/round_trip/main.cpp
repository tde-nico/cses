#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<bool> visited;
vector<int> parent;

void win(int start, int end) {
	vector<int> cycle;
	int curr = start;
	while (curr != end) {
		cycle.push_back(curr);
		curr = parent[curr];
	}
	cycle.push_back(end);
	cycle.push_back(start);
	
	cout << cycle.size() << "\n";
	for (int i = 0; i < cycle.size(); ++i) {
		cout << cycle[i]+1 << " ";
	}
	cout << "\n";
	
	exit(0);
}

void dfs(int curr, int previous=-1) {
	visited[curr] = true;
	parent[curr] = previous;
	int next;
	for (int i = 0; i < G[curr].size(); ++i) {
		next = G[curr][i];
		if (next == previous) {
			continue;
		}
		if (visited[next]) {
			win(curr, next);
		}
		dfs(next, curr);
	}
}

int main() {
	int N, M, a, b;
	cin >> N >> M;
	G.reserve(N);
	visited.reserve(N);
	parent.reserve(N);
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
