#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fenwick {
	vector<ll> t;
	Fenwick(ll n): t(n*2+1, 0) {}
	void add(ll p, ll val) {
		for (; p < (ll)t.size(); p+=p&-p) t[p] += val;
	}
	ll sum(ll b) {
		ll res = 0;
		for (; b > 0; b-=b&-b) res += t[b];
		return res;
	}
	ll sum(ll a, ll b) { return sum(b) - (a==0 ? 0 : sum(a-1)); }
};

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	map<ll, ll> m;
	for (ll &x : v) {
		cin >> x;
		m[x]++;
	}

	ll i = 0;
	for (auto &c : m) c.second = ++i;
	for (ll &x : v) x = m[x];

	ll cnt = 0;
	Fenwick f(n);
	for (ll i = 0; i < n; ++i) {
		f.add(v[i], 1);
		cnt += f.sum(v[i]+1, n);
		
		if (i >= k) {
			f.add(v[i-k], -1);
			cnt -= f.sum(0, v[i-k]-1);
		}

		if (i >= k-1)
			cout << cnt << " ";
	}
	cout << "\n";
}
