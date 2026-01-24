#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

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

	void add(Line line, ll i=1, ll l=0, ll r=-1) {
		if (r == -1) r = n;
		while (true) {
			ll m = (l+r) / 2;
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

	void add_segment(Line line, ll i, ll l, ll r, ll ql, ll qr) {
		if (qr <= l || r <= ql) return;
		if (ql <= l && r <= qr) {
			add(line, i, l, r);
			return;
		}

		ll m = (l+r) / 2;
		add_segment(line, i*2, l, m, ql, qr);
		add_segment(line, i*2+1, m, r, ql, qr);
	}

	void add_segment(Line line, ll ql, ll qr) { add_segment(line, 1, 0, n, ql, qr); }

	ll query(ll x) {
		ll res = -INF;
		for (ll i = x+n; i; i >>= 1) res = max(res, t[i](x));
		return res;
	}
};

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (ll &x : v) cin >> x;

	stack<ll> s;
	vector<ll> l(n), r(n);
	for (ll i = 0; i < n; ++i) {
		while (s.size() && v[s.top()] >= v[i]) s.pop();
		l[i] = s.empty() ? 0 : (s.top()+1);
		s.push(i);
	}
	s = {};
	for (ll i = n-1; i >= 0; --i) {
		while (s.size() && v[s.top()] >= v[i]) s.pop();
		r[i] = s.empty() ? n : s.top();
		s.push(i);
	}

	LiChao lc(n+1);
	for (ll i = 0; i < n; ++i) {
		ll m = r[i] - l[i];
		if (m >= k) {
			lc.add_segment({v[i], -v[i]*(l[i]-k)}, l[i]-k, l[i]);
			lc.add_segment({0, v[i]*k}, l[i], r[i]-k);
			lc.add_segment({-v[i], v[i]*r[i]}, r[i]-k, r[i]);
		} else {
			lc.add_segment({v[i], -v[i]*(l[i]-k)}, l[i]-k, r[i]-k);
			lc.add_segment({0, v[i]*m}, r[i]-k, l[i]);
			lc.add_segment({-v[i], v[i]*r[i]}, l[i], r[i]);
		}
	}

	for (ll i = 0; i <= n-k; ++i)
		cout << lc.query(i) << " ";
	cout << "\n";
}
