#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M, a, b;
	cin >> N >> M;
	vector<vector<int>> G(N+1);
	vector<bool> V(N+1, false);
	vector<int> dists(N+1, 0);
	vector<int> previous(N+1, 0);
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	queue<int> q;
	q.push(0);
	V[0] = true;
	while (q.size()) {
		int curr = q.front(); q.pop();
		for (int i = 0; i < G[curr].size(); ++i) {
			int nxt = G[curr][i];
			if (V[nxt]) {
				continue;
			}
			V[nxt] = true;
			dists[nxt] = dists[curr] + 1;
			previous[nxt] = curr;
			q.push(nxt);
		} 
	}

	if (!V[N-1]) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	int curr = N-1;
	int dist = dists[N-1];
	vector<int> res(dist+1);
	for (int i = dist; i >= 0; --i) {
		res[i] = curr;
		curr = previous[curr];
	}

	cout << dist+1 << "\n";
	for (int i = 0; i <= dist; ++i) {
		cout << res[i] + 1 << " ";
	}
	cout << "\n";
	return 0;
}
