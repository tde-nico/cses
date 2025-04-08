#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF LLONG_MAX

ll N, M;
vector<array<ll, 3>> E;

vector<ll> bellman_ford(ll src) {
	vector<ll> dist(N, INF);
	dist[src] = 0LL;
	bool relaxed = true;
	for (int i = 0; i < N-1 && relaxed; ++i) {
		relaxed = false;
		for (auto [start, end, wg] : E) {
			if (dist[start] != INF && dist[start] + wg < dist[end]) {
				dist[end] = dist[start] + wg;
				relaxed = true;
			}
		}
	}
	
	vector<bool> in_cycle(N, false);
	for (int i = 0; i < N; ++i) {
		for (auto [start, end, wg] : E) {
			if (dist[start] != INF && dist[start] + wg < dist[end]) {
				dist[end] = -INF;
				in_cycle[end] = true;
			}
			if (in_cycle[start]) {
				in_cycle[end] = true;
				dist[end] = -INF;
			}
		}
	}
	return dist;
}

int main() {
	ll a, b, c;
	cin >> N >> M;
	E.resize(M);
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		a--; b--; c = -c;
		E[i] = {a, b, c};
	}

	vector<ll> dist = bellman_ford(0);

	cout << (dist[N-1] <= -INF ? -1 : -dist[N-1]) << "\n";
	return 0;
}
