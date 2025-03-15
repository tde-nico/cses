#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll x, y, v;
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> y >> x;
		v = max(x, y) - 1;
		if (v & 1) {
			if (x < y)
				v = v * (v + 2) - x + 2;
			else
				v = v * v + y;
		} else {
			if (x < y)
				v = v * v + x;
			else
				v = v * (v + 2) - y + 2;
		}
		cout << v << "\n";
	}
	return 0;
}
