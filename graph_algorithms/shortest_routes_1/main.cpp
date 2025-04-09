#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, M;
vector<vector<pair<ll, ll>>> G;

vector<ll> dijkstra(ll src) {
	vector<ll> dist(N, LLONG_MAX);
	set<pair<ll, ll>> s{{0LL, src}};
	
	dist[src] = 0LL;
	while (s.size()) {
		ll curr = s.begin()->second;
		s.erase(s.begin());
		for (auto [v, d] : G[curr]) {
			if (dist[curr] + d < dist[v]) {
				s.erase({dist[v], v});
				dist[v] = dist[curr] + d;
				s.insert({dist[v], v});
			}
		}
	}

	return dist;
}

int main() {
	ll a, b, c;
	cin >> N >> M;
	G.reserve(N);
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		--a; --b;
		G[a].push_back({b, c});
	}
	vector<ll> dist = dijkstra(0);
	for (int i = 0; i < N; ++i) {
		cout << dist[i] << " ";
	}
	return 0;
}
