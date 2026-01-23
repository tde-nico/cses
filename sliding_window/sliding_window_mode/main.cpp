#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (ll &x : v) cin >> x;

	set<pair<ll, ll>> s;
	map<ll, ll> m;
	for (ll i = 0; i < n; ++i) {
		ll x = v[i];
		ll cnt = m[x];
		s.erase({-cnt, x});
		s.insert({-(cnt+1), x});
		m[x]++;

		if (i >= k) {
			ll y = v[i-k];
			ll cnt = m[y];
			s.erase({-cnt, y});
			s.insert({-(cnt-1), y});
			m[y]--;
		}

		if (i >= k-1)
			cout << s.begin()->second << " ";
	}
	cout << " ";
}
