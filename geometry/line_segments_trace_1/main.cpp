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
		while (n < N) n *= 2;
		t.assign(2*n, Line{0, -INF});
	}

	void add(Line line) {
		ll v = 1;
		ll l = 0, r = n;
		while (true) {
			ll m = (l + r) / 2;
			bool left = line(l) > t[v](l);
			bool mid = line(m) > t[v](m);

			if (mid) swap(t[v], line);
			if (r-l <= 1) break;

			if (left != mid) {
				v = v*2;
				r = m;
			} else {
				v = v*2 + 1;
				l = m;
			}
		}
	}

	ll query(ll x) {
		ll res = -INF;
		for (ll v = x+n; v; v >>= 1) res = max(res, t[v](x));
		return res;
	}
};

int main() {
	ll n, m;
	cin >> n >> m;
	LiChao lc(m);
	for (ll i = 0; i < n; ++i) {
		ll y1, y2;
		cin >> y1 >> y2;
		lc.add({(y2-y1)/m, y1});
	}

	for (ll i = 0; i <= m; ++i) {
		cout << lc.query(i) << " ";
	}
	cout << "\n";
}
