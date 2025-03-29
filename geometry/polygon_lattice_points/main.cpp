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
	int N;
	cin >> N;
	vector<P> poly(N);
	for (int i = 0; i < N; ++i) {
		poly[i].read();
	}

	ll boundary = 0;
	for (int i = 0; i < N; ++i) {
		int j = (i+1) % N;
		P diff = poly[j] - poly[i];
		ll g = gcd(abs(diff.x), abs(diff.y));
		boundary += g;
	}

	ll area = 0;
	for (int i = 0; i < N; ++i) {
		area += poly[i].cross(poly[(i+1) % N]);
	}
	area = abs(area);
	ll interior = (area - boundary + 2) / 2;

	cout << interior << " " << boundary << "\n";
}
