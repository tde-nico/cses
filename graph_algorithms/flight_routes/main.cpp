#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, M, K;
vector<vector<pair<ll, ll>>> G;

void dijkstra(ll src) {
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
	Q.push({0LL, src});
	vector<ll> cnt(N, 0LL);
	while (Q.size()) {
		ll d = Q.top().first;
		ll u = Q.top().second;
		Q.pop();
		
		cnt[u]++;
		if (u == N-1) {
			cout << d << " ";
			if (cnt[u] == K) {
				return;
			}
		}

		if (cnt[u] <= K) {
			for (auto [v, w] : G[u]) {
				Q.push({d+w, v});

			}
		}
	}
}

int main() {
	ll a, b, c;
	cin >> N >> M >> K;
	G.reserve(N);
	for (ll i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		--a; --b;
		G[a].push_back({b, c});
	}
	dijkstra(0LL);
	return 0;
}
