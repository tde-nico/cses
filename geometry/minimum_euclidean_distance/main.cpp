#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define tie(a, b) pair<int, int>{a, b}

#define P Point
class Point {
public:
	ll x, y;
	P(ll x=0, ll y=0): x(x), y(y) {}
	void read() {cin >> x >> y;}
	bool operator<(P p) const {return tie(x, y) < tie(p.x, p.y);}
	bool operator==(P p) const {return tie(x, y) == tie(p.x, p.y);}
	P operator+(P p) const {return P(x+p.x, y+p.y);}
	P operator-(P p) const {return P(x-p.x, y-p.y);}
	P operator-() const {return P(-x, -y);}
	P operator*(ll d) const {return P(x*d, y*d);}
	P operator/(ll d) const {return P(x/d, y/d);}
	ll cross(P p) const {return x*p.y - y*p.x;}
	ll cross(P a, P b) const {return (a-*this).cross(b-*this);}
};

ll N;

#define DIST(a, b) ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))

ll sweep_line(vector<P> &points) {
	ll minDist = LLONG_MAX;
	set<pair<ll, ll>> activePoints = {{points[0].y, points[0].x}};
	ll j = 0;
	for (ll i = 1; i < N; ++i) {
		auto it = activePoints.begin();
		ll dd = ceil(sqrt(minDist));
		while (j < i && points[j].x < points[i].x - dd) {
			activePoints.erase({points[j].y, points[j].x});
			++j;
		}
		auto lowerBound = activePoints.lower_bound({points[i].y - dd, 0});
		auto upperBound = activePoints.upper_bound({points[i].y + dd, 0});
		for (auto it = lowerBound; it != upperBound; ++it) {
			minDist = min(minDist, DIST(P(it->second, it->first), points[i]));
		}
		activePoints.insert({points[i].y, points[i].x});
	}
	return minDist;
}

int main() {
	cin >> N;
	vector<P> points(N);
	for (int i = 0; i < N; ++i) {
		points[i].read();
	}

	sort(points.begin(), points.end(), [](P a, P b){
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	});
	cout << sweep_line(points) << "\n";
	return 0;
}
