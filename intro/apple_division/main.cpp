#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	ll a, b, best = 0x7fffffffffffffff;
	for (int i = 0; i < (1 << n); ++i) {
		a = 0, b = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j))
				a += p[j];
			else
				b += p[j];
		}
		best = min(best, abs(a-b));
	}
	cout << best << "\n";

	return 0;
}
