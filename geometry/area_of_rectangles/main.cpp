#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<array<ll, 4>> events;
vector<ll> Y;

struct SegmentTree {
	vector<ll> seg, cnt;
	SegmentTree(ll n): seg(n+1, 0), cnt(n+1, 0) {}
	ll query() { return seg[1]; }
	void update(ll idx, ll l, ll r, ll update_l, ll update_r, ll val) {
		if (update_r <= l || r <= update_l) return;
		if (update_l <= l && r <= update_r) {
			cnt[idx] += val;
		} else {
			ll mid = (l + r) / 2;
			update(idx*2, l, mid, update_l, update_r, val);
			update(idx*2+1, mid, r, update_l, update_r, val);
		}

		if (cnt[idx] > 0) {
			seg[idx] = Y[r] - Y[l];
		} else if (l + 1 == r) {
			seg[idx] = 0;
		} else {
			seg[idx] = seg[idx*2] + seg[idx*2+1];
		}
	}
};

int main() {
	ll n;
	cin >> n;

	events.reserve(n*2);
	Y.reserve(n*2);

	for (ll i = 0; i < n; ++i) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 1e6; y1 += 1e6; x2 += 1e6; y2 += 1e6;
		events.push_back({x1, y1, y2, +1});
		events.push_back({x2, y1, y2, -1});
		Y.push_back(y1);
		Y.push_back(y2);
	}

	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());

	auto get_y_idx = [](ll y) {
		return lower_bound(Y.begin(), Y.end(), y) - Y.begin();
	};
	for (auto &e : events) {
		e[1] = get_y_idx(e[1]);
		e[2] = get_y_idx(e[2]);
	}

	sort(events.begin(), events.end());

	ll area = 0;
	ll size = Y.size();
	ll prev_x = 0;
	SegmentTree s(size*4);
	for (auto [x, y1, y2, val] : events) {
		area += (x - prev_x) * s.query();
		s.update(1, 0, size-1, y1, y2, val);
		prev_x = x;
	}

	cout << area << "\n";

	return 0;
}
