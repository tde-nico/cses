#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define tie(a, b) pair<int, int>{a, b}

#define P Point
class Point {
public:
	ll x, y;
	P(ll x=0, ll y=0): x(x), y(y) {}
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

vector<P> convex_hull(vector<P> points, bool collinear_edges=false) {
	vector<P> hull;
	sort(points.begin(), points.end());
	for (int i = 0; i < 2; ++i) {
		int sz = hull.size();
		for (P &p : points) {
			if (hull.size() && hull.end()[-1] == p) continue;
			while (hull.size() - sz >= 2) {
				auto x = hull.end()[-2].cross(hull.end()[-1], p);
				if (x < 0 || (collinear_edges && x == 0)) break;
				hull.pop_back();
			}
			hull.push_back(p);
		}
		if (hull.size() == 1) return hull;
		hull.pop_back();
		reverse(points.begin(), points.end());
	}
	// reverse(hull.begin(), hull.end());
	return hull;
}

int main() {
	ll N;
	cin >> N;
	vector<P> points(N);
	for (int i = 0; i < N; ++i) {
		cin >> points[i].x >> points[i].y;
	}
	
	vector<P> hull = convex_hull(points, true);
	cout << hull.size() << "\n";
	for (int i = 0; i < hull.size(); ++i) {
		cout << hull[i].x << " " << hull[i].y << "\n";
	}

	return 0;
}
