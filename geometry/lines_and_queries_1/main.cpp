#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const ll MAX = 2 * 1e5 + 1;

struct Line {
	ll a, b;
	ll operator()(ll x) { return a * x + b; }
};

struct LiChao {
	ll n;
	vector<Line> t;

	LiChao(ll N) {
		n = 1;
		while (n < N) n <<= 1;
		t.assign(2*n, {0, -INF});
	}

	void add(Line line) {
		ll i = 1;
		ll l = 0, r = n;
		while (true) {
			ll m = (l + r) / 2;
			bool left = line(l) > t[i](l);
			bool mid = line(m) > t[i](m);
			if (mid) swap(t[i], line);
			if (r-l <= 1) break;
			if (left != mid) {
				r = m;
				i = i*2;
			} else {
				l = m;
				i = i*2+1;
			}
		}
	}

	ll query(ll x) {
		ll res = -INF;
		for (ll i = x+n; i; i >>= 1) res = max(res, t[i](x));
		return res;
	}
};

int main() {
	ll n;
	cin >> n;
	LiChao lc(MAX);
	for (ll i = 0; i < n; ++i) {
		ll op;
		cin >> op;
		if (op == 1) {
			ll a, b;
			cin >> a >> b;
			lc.add({a, b});
		} else {
			ll x;
			cin >> x;
			cout << lc.query(x) << "\n";
		}
	}
}

