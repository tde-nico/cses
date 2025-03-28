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

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		P p1, p2, p3;
		p1.read(); p2.read(); p3.read();
		ll cross = p1.cross(p2, p3);
		if (cross > 0) {
			cout << "LEFT\n";
		} else if (cross < 0) {
			cout << "RIGHT\n";
		} else {
			cout << "TOUCH\n";
		}
	}
	return 0;
}
