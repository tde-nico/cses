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
		t.assign(2*n, Line{0, -INF});
	}

	void add(Line line, ll i=1, ll l=0, ll r=-1) {
		if (r == -1) r = n;
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

	void add_segment(ll i, ll l, ll r, ll ql, ll qr, Line line) {
		if (qr <= l || r <= ql) return;
		if (ql <= l && r <= qr) {
			add(line, i, l, r);
			return;
		}

		ll m = (l + r) / 2;
		add_segment(i*2, l, m, ql, qr, line);
		add_segment(i*2+1, m, r, ql, qr, line);
	}

	void add_segment(Line line, ll l, ll r) { add_segment(1, 0, n, l, r, line); }

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
		ll t;
		cin >> t;
		if (t == 1) {
			ll a, b, l, r;
			cin >> a >> b >> l >> r;
			lc.add_segment({a, b}, l, r+1);
		} else {
			ll x;
			cin >> x;
			ll q = lc.query(x);
			if (q == -INF) cout << "NO\n";
			else cout << q << "\n";
		}
	}
}
