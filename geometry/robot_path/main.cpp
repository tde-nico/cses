#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define TIE(a, b) pair<int, int>{a, b}

#define P Point
struct Point {
	ll x, y;
	P(ll x=0, ll y=0): x(x), y(y) {}
	bool operator<(P p) const {return TIE(x, y) < TIE(p.x, p.y);}
	P operator+(P p) const {return P(x+p.x, y+p.y);}
	P operator-(P p) const {return P(x-p.x, y-p.y);}
	P operator*(ll d) const {return P(x*d, y*d);}
};

struct Segment {
	ll x1, y1, x2, y2;
};

enum EventType {
	ADD,
	QUERY,
	REMOVE,
};

struct Event {
	ll x, y1, y2;
	EventType t;
	bool operator<(const Event &e) {
		if (x != e.x) return x < e.x;
		if (t != e.t) return t < e.t;
		return y1 < e.y1;
	}
};

char flip[128];
Point dirs[128];

optional<Point> line_sweep(const vector<Segment> &s, ll len) {
	vector<Event> events;
	for (ll i = 0; i < len; ++i) {
		auto [x1, y1, x2, y2] = s[i];

		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
 
		if (x1 == x2) {
			events.push_back({x1, y1, y2, QUERY});
		} else {
			events.push_back({x1, y1, y2, ADD});
			events.push_back({x2, y1, y2, REMOVE});
		}
	}

	sort(events.begin(), events.end());

	set<ll> active;
	for (ll i = 0; i < (ll)events.size(); ++i) {
		auto [x, y1, y2, t] = events[i];

		switch (t) {
			case ADD: {
				auto [_, ok] = active.insert(y1);
				if (!ok) return Point{x, y1};
				break;
			}
			case QUERY: {
				if (i > 0 && events[i-1].x == x &&
					events[i-1].t == QUERY &&
					events[i-1].y2 >= y1) {
					if (y1 <= events[i-1].y1) return Point{x, events[i-1].y1};
					else return Point{x, events[i-1].y2};
				}
				auto it1 = active.lower_bound(y1);
				auto it2 = active.upper_bound(y2);
				if (it1 != it2) return Point{x, *it1};
				break;
			}
			case REMOVE: {
				active.erase(y1);
				break;
			}
		}
	}

	return nullopt;
}

bool on_segment(Point a, Point b, Point c) {
	Point da = {c.x - a.x, c.y - a.y};
	Point db = {c.x - b.x, c.y - b.y};
	ll cross = da.x * db.y - da.y * db.x;
	ll dot = da.x * db.x + da.y * db.y;
	return cross == 0 && dot <= 0;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	flip['U'] = 'D';
	flip['D'] = 'U';
	flip['L'] = 'R';
	flip['R'] = 'L';
	dirs['U'] = {0, 1};
	dirs['D'] = {0, -1};
	dirs['L'] = {-1, 0};
	dirs['R'] = {1, 0};

	ll n;
	cin >> n;
	vector<pair<char, ll>> cmds(n);
	for (auto &[d, x] : cmds) cin >> d >> x;

	ll bad_idx = n;
	for (ll i = 1; i < n; ++i) {
		if (cmds[i].first == flip[cmds[i-1].first]) {
			bad_idx = i;
			break;
		}
	}
	cmds.erase(cmds.begin()+bad_idx, cmds.end());

	vector<ll> X, Y;
	Point curr = {0, 0};
	X.push_back(0);
	Y.push_back(0);
	for (auto [d, x] : cmds) {
		curr = curr + (dirs[d] * x);
		X.push_back(curr.x);
		Y.push_back(curr.y);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	auto compress = [&X, &Y](Point a) -> Point {
		ll x = lower_bound(X.begin(), X.end(), a.x) - X.begin();
		ll y = lower_bound(Y.begin(), Y.end(), a.y) - Y.begin();
		return {x, y};
	};

	curr = {0, 0};
	Point cstart = compress(curr);
	Point ccurr = cstart;

	vector<pair<char, ll>> ccmds = cmds;
	for (auto &[d, x] : ccmds) {
		curr = curr + (dirs[d] * x);
		Point cnext = compress(curr);
		x = abs(cnext.x - ccurr.x) + abs(cnext.y - ccurr.y);
		ccurr = cnext;
	}

	curr = cstart;
	bool first = true;
	vector<Segment> segments;
	segments.reserve(ccmds.size());
	for (auto [d, x] : ccmds) {
		Point start = curr + (first ? 0 : dirs[d]);
		Point next = curr + dirs[d] * x;
		segments.push_back({start.x, start.y, next.x, next.y});
		curr = next;
		first = false;
	}

	ll l = 0, r = segments.size() + 1; // NOTE: I have absolutely no idea why this +1 is needed to make the code work
	while (r - l > 1) {
		ll mid = (l + r - 1) / 2;
		if (line_sweep(segments, mid)) r = mid + 1;
		else l = mid + 1;
	}

	optional<Point> intersection = line_sweep(segments, l);
	ll res = 0;
	if (!intersection) {
		for (auto [d, x] : cmds)
		res += x; 
	} else {
		Point cstop = *intersection;
		Point stop {X[cstop.x], Y[cstop.y]};
		curr = {0, 0};
		bool first = true, encountered = false;
		for (auto [d, x] : cmds) {
			Point start = curr + (first ? 0 : dirs[d]);
			Point next = curr + dirs[d] * x;

			if (on_segment(start, next, stop)) {
				if (!encountered) {
					encountered = true;
				} else {
					res += abs(stop.x - curr.x) + abs(stop.y - curr.y);
					break;
				}
			}

			res += x;
			curr = next;
			first = false;
		}
	}

	cout << res << "\n";
}