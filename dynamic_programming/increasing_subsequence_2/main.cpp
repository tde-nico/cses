#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

struct Fenwick {
	vector<ll> ft;
	Fenwick(ll n): ft(n*2+1, 0) {}
	void add (ll p, ll val) {
		for (; p < (ll)ft.size(); p+=p&-p)
			ft[p] = (ft[p] + val) % MOD;
	}
	ll sum(ll b) {
		ll res = 0;
		for (; b > 0; b-=b&-b)
			res = (res + ft[b]) % MOD;
		return res;
	}
};

int main() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	map<ll, ll> m;
	for (ll &x : v) {
		cin >> x;
		m[x]++;
	}

	ll i = 0;
	for (auto &c : m) c.second = ++i;
	for (ll &x : v) x = m[x];

	ll res = 0;
	Fenwick f(n);
	for (auto x : v) {
		ll s = 1 + f.sum(x-1);
		f.add(x, s);
		res = (res + s) % MOD;
	}

	cout << res << "\n";
}
