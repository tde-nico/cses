#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll mx = 0, sum = 0, num;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		mx = max(mx, num);
		sum += mx - num;
	}
	cout << sum << "\n";
	return 0;
}
