#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX 2*1e5+1

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (ll &x : v) cin >> x;

	set<ll> s;
	for (ll i = 0; i <= MAX; ++i) s.insert(i);

	map<ll, ll> m;
	for (ll i = 0; i < n; ++i) {
		ll x = v[i];
		m[x]++;
		if (m[x] == 1) s.erase(x);

		if (i >= k) {
			ll y = v[i-k];
			m[y]--;
			if (m[y] == 0) s.insert(y);
		}

		if (i >= k-1)
			cout << *s.begin() << " ";
	}
	cout << "\n";
}
