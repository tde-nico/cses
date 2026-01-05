#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const char chars[4] = {'A','B','C','D'};


int main() {
	ll n, m;
	cin >> n >> m;
	
	vector<vector<char>> g(n, vector<char>(m));
	for (auto &row : g) {
		for (auto &col : row) {
			cin >> col;
		}
	}

	for (ll y = 0; y < n; ++y) {
		for (ll x = 0; x < m; ++x) {
			set<char> s = {g[y][x]};
			if (y) s.insert(g[y-1][x]); 
			if (x) s.insert(g[y][x-1]); 

			bool possible = false;
			for (char c : chars) {
				if (!s.count(c)) {
					possible = true;
					g[y][x] = c;
					break;
				}
			}

			if (!possible) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}

	for (auto row : g) {
		for (auto col : row) {
			cout << col;
		}
		cout << "\n";
	}

	return 0;
}
