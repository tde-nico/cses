#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k, x, a, b, c;
	cin >> n >> k >> x >> a >> b >> c;
	
	ll l = x;
	ll tmp = 0;
	for (ll i = 0; i < k; ++i) {
		tmp ^= x;
		x = (a * x + b) % c;
	}
	ll r = x;
	
	ll res = tmp;
	for (ll i = k; i < n; ++i) {
		tmp ^= l ^ r;
		l = (a * l + b) % c;
		r = (a * r + b) % c;
		res ^= tmp;
		x = (a * x + b) % c;
	}

	cout << res << "\n";
}
