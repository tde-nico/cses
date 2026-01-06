#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const pair<ll, ll> dirs[] = {
	{-2, -1},
	{-2, 1},
	{-1, -2},
	{-1, 2},
	{1, -2},
	{1, 2},
	{2, -1},
	{2, 1},
};

int main() {
	ll n;
	cin >> n;
	vector<vector<ll>> g(n, vector<ll>(n, -1));

	queue<array<ll, 3>> q;
	q.push({0, 0, 0});
	while (q.size()) {
		auto [y, x, dist] = q.front();
		q.pop();

		if (g[y][x] != -1) {
			continue;
		}
		g[y][x] = dist;

		for (auto [diry, dirx] : dirs) {
			ll dy = y + diry;
			ll dx = x + dirx;
			
			if (dy < 0 || dy >= n || dx < 0 || dx >= n) {
				continue;
			}

			q.push({dy, dx, dist+1});
		}
	}

	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
