#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, M, Q;
vector<vector<ll>> G;

vector<vector<ll>> floyd_warshall() {
	vector<vector<ll>> dist = G;
	for (int i = 0; i < N; ++i) dist[i][i] = min(dist[i][i], 0LL);
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
					dist[i][j] = min(dist[i][j], max(LLONG_MIN, dist[i][k]+dist[k][j]));
				}
			}
		}
	}
	for (int k = 0; k < N; ++k) {
		if (dist[k][k] >= 0) {
			continue;
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
					dist[i][j] = -LLONG_MIN;
				}
			}
		}
	}
	return dist;
}

int main() {
	ll a, b, c;
	cin >> N >> M >> Q;
	G.assign(N, vector<ll>(N, LLONG_MAX));
	for (int i = 0 ; i < M; ++i) {
		cin >> a >> b >> c;
		--a; --b;
		G[a][b] = min(G[a][b], c);
		G[b][a] = min(G[b][a], c);
	}

	vector<vector<ll>> dist = floyd_warshall();

	for (int i = 0; i < Q; ++i) {
		cin >> a >> b;
		cout << (dist[--a][--b] >= LLONG_MAX ? -1 : dist[a][b]) << "\n";
	}
	return 0;
}
