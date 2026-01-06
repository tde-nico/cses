#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Fenwick {
	vector<ll> ft;
	
	Fenwick(int n) { ft.assign(n+1, 0); }
	
	void add(int p, ll v) {
		for (++p; p < ft.size(); p += p&-p) ft[p] += v;
	}
	
	ll sum(int b) {
		ll res = 0;
		for (++b; b > 0; b -= b&-b) res += ft[b];
		return res;
	}

	ll sum(int a, int b) { return sum(b) - (a?sum(a-1):0); }
};

int main() {
	ll n;
	cin >> n;
	
	vector<array<ll, 4>> v;
	for (ll i = 0; i < n; ++i) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 == y2) {
			v.push_back({y1, 1, x1, x2});
		} else {
			v.push_back({y1, 0, x1, 0});
			v.push_back({y2, 2, x1, 0});
		}
	}

	sort(v.begin(), v.end());

	const ll MAX_POS = 1e6;
	Fenwick f(MAX_POS*2+1);
	ll res = 0;
	for (auto [y, type, x1, x2] : v) {
		x1 += MAX_POS;
		x2 += MAX_POS;
		switch (type) {
		case 0:
			f.add(x1, 1);
			break;
		case 1:
			res += f.sum(x1, x2);
			break;
		case 2:
			f.add(x1, -1);
			break;
		}
	}

	cout << res << "\n";

	return 0;
}
