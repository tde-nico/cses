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

bool intersect(P p1, P p2, P p3, P p4) {
	if ((p2 - p1).cross(p4 - p3) == 0) {
		if (p1.cross(p2, p3)) {
			return false;
		}
		for (int i = 0; i < 2; ++i) {
			if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
				return false;
			}
			swap(p1, p3);
			swap(p2, p4);
		}
		return true;
	}

	for (int i = 0; i < 2; ++i) {
		ll sign1 = p1.cross(p2, p3);
		ll sign2 = p1.cross(p2, p4);
		if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
			return false;
		}
		swap(p1, p3);
		swap(p2, p4);
	}
	return true;
}

bool segment_contains(P a, P b, P c) {
	if (a.cross(b, c)) {
		return false;
	}
	return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
		min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<P> poly(N);
	for (int i = 0; i < N; ++i) {
		poly[i].read();
	}
	for (int _ = 0; _ < M; ++_) {
		P p; p.read();
		P out(p.x + 1, 3000000001LL);
		bool is_on_boundary = false;
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			int j = (i==N-1 ? 0 : i+1);
			if (segment_contains(poly[i], poly[j], p)) {
				is_on_boundary = true;
				break;
			}
			if (intersect(p, out, poly[i], poly[j])) {
				cnt++;
			}
		}
		if (is_on_boundary) {
			cout << "BOUNDARY\n";
		} else if (cnt % 2) {
			cout << "INSIDE\n";
		} else {
			cout << "OUTSIDE\n";
		}
	}
}
