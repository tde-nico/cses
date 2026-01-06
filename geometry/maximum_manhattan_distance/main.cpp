#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll t;
	cin >> t;

	ll mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX;
	while (t--) {
		ll x, y;
		cin >> x >> y;

		mx1 = max(mx1, x+y);
		mx2 = max(mx2, x-y);
		mn1 = min(mn1, x+y);
		mn2 = min(mn2, x-y);

		cout << max(mx1-mn1, mx2-mn2) << "\n";
	}

	return 0;
}
