#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k, x, a, b, c;
	cin >> n >> k >> x >> a >> b >> c;

	vector<ll> v(n), prefix(n), suffix(n);

	v[0] = x;
	for (ll i = 1; i < n; ++i) {
		v[i] = (a * v[i-1] + b) % c;
	}
	for (ll i = 0; i < n; ++i) {
		if (i % k == 0) prefix[i] = v[i];
		else prefix[i] = prefix[i-1] | v[i];
	}
	suffix[n-1] = v[n-1];
	for (ll i = n-2; i >= 0; --i) {
		if (i % k == k - 1) suffix[i] = v[i];
		else suffix[i] = suffix[i+1] | v[i];
	}

	ll res = 0;
	ll l = 0, r = k-1;
	while (r < n) {
		if (r % k == k - 1) res ^= prefix[r];
		else res ^= (suffix[l] | prefix[r]);
		l++; r++;
	}

	cout << res << "\n";
}
