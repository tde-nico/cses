#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e18

ll N, M;
vector<array<ll, 3>> E;

void bellman_ford(ll src) {
	vector<ll> dist(N+1, INF);
	vector<ll> prevs(N+1, INF);
	dist[src] = 0LL;
	ll relaxed = -1;
	for (ll i = 0; i < N && relaxed; ++i) {
		relaxed = 0;
		for (auto [start, end, wg] : E) {
			if (dist[start] + wg < dist[end]) {
				dist[end] = dist[start] + wg;
				prevs[end] = start;
				relaxed = end;
			}
		}
	}

	if (!relaxed) {
		cout << "NO\n";
		return;
	} else {
		cout << "YES\n";
	}

	for (ll i = 0; i < N; ++i) {
		relaxed = prevs[relaxed];
	}

	vector<ll> cycle;
	for (ll curr = relaxed; ; curr = prevs[curr]) {
		cycle.push_back(curr);
		if (curr == relaxed && cycle.size() > 1) {
			break ;
		}
	}
	for (ll i = cycle.size()-1; i >= 0; --i) {
		cout << cycle[i] << " ";
	}
}

int main() {
	ll a, b, c;
	cin >> N >> M;
	E.reserve(M);
	for (ll i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		E.push_back({a, b, c});
	}
	bellman_ford(1LL);
	return 0;
}
