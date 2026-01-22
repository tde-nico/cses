#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	ll x, a, b, c;
	cin >> x >> a >> b >> c;

	ll l = x, r;

	ll sum = 0;
	for (ll i = 0; i < k; ++i) {
		sum += x;
		x = (a * x + b) % c;
	}
	r = x;

	ll res = sum;
	for (ll i = k; i < n; ++i) {
		sum += (r - l);
		l = (a * l + b) % c;
		r = (a * r + b) % c;
		res ^= sum;
	}

	cout << res << "\n";
}
