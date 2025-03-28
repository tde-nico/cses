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

void test() {
	P p1, p2, p3, p4;
	p1.read(); p2.read(); p3.read(); p4.read();

	if ((p2 - p1).cross(p4 - p3) == 0) {
		if (p1.cross(p2, p3)) {
			cout << "NO\n";
			return;
		}
		for (int i = 0; i < 2; ++i) {
			if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
				cout << "NO\n";
				return;
			}
			swap(p1, p3);
			swap(p2, p4);
		}
		cout << "YES\n";
		return;
	}

	for (int i = 0; i < 2; ++i) {
		ll sign1 = p1.cross(p2, p3);
		ll sign2 = p1.cross(p2, p4);
		if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
			cout << "NO\n";
			return;
		}
		swap(p1, p3);
		swap(p2, p4);
	}
	cout << "YES\n";
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		test();
	}
	return 0;
}
