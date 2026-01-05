#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;

	vector<ll> v(n);
	for (auto &x : v) cin >> x;

	set<ll> s;
	ll count = 0;
	for (ll l = 0, r = 0; r < n; ++r) {
		while (s.count(v[r])) {
			s.erase(v[l++]);
		}
		s.insert(v[r]);
		count += r - l + 1;
	}

	cout << count << "\n";
	return 0;
}
