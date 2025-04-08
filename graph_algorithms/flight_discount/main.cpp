#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, M;
vector<vector<pair<ll, ll>>> G;

vector<ll> dijkstra(ll src) {
	vector<ll> dist(N*2, LLONG_MAX);
	set<pair<ll, ll>> s{{0LL, src}};
	dist[src] = 0;
	dist[src+1] = 0;
	while (s.size()) {
		ll curr = s.begin()->second;
		s.erase(s.begin());
		for (auto [v, d] : G[curr]) {
			if (dist[curr*2] + d < dist[v*2]) {
				s.erase({dist[v*2], v});
				dist[v*2] = dist[curr*2] + d;
				s.insert({dist[v*2], v});
			}
			if (dist[curr*2+1] + d < dist[v*2+1]) {
				s.erase({dist[v*2+1], v});
				dist[v*2+1] = dist[curr*2+1] + d;
				s.insert({dist[v*2+1], v});
			}
			if (dist[curr*2] + d/2 < dist[v*2+1]) {
				s.erase({dist[v*2+1], v});
				dist[v*2+1] = dist[curr*2] + d/2;
				s.insert({dist[v*2+1], v});
			}
		}
	}
	return dist;
}

int main() {
	ll a, b, c;
	cin >> N >> M;
	G.reserve(N);
	for (ll i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		--a; --b;
		G[a].push_back({b, c});
	}
	vector<ll> dist = dijkstra(0);
	cout << min(dist[N*2-2], dist[N*2-1]) << "\n";
	return 0;
}
