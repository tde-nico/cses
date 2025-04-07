#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<bool> teams;
vector<bool> visited;
bool possible;

void dfs(int curr, int previous=0) {
	int next;
	for (int i = 0; i < G[curr].size(); ++i) {
		next = G[curr][i];
		if (next == previous) {
			continue;
		}

		if (visited[next]) {
			if (teams[next] == teams[curr]) {
				possible = false;
			}
		} else {
			visited[next] = true;
			teams[next] = !teams[curr];
			dfs(next, curr);
		}
	}
}

int main() {
	int N, M, a, b;
	cin >> N >> M;
	G.reserve(N);
	teams.reserve(N);
	visited.reserve(N);
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	possible = true;
	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}

	if (!possible) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for (int i = 0; i < N; ++i) {
		cout << (teams[i] ? 2 : 1) << " ";
	}
	return 0;
}
