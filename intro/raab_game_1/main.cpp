#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	size_t n, a, b;
	cin >> n >> a >> b;

	if (a+b > n) {
		cout << "NO\n";
		return;
	}

	vector<size_t> p1, p2(n);
	for (size_t i = 0; i < n; ++i) {
		p2[i] = i+1;
	}

	size_t j = 0;
	for (size_t i = b+1; i <= b+a; ++i) {
		p1.push_back(i);
		if (p1[j] <= p2[j]) {
			cout << "NO\n";
			return;
		}
		j++;
	}

	for (size_t i = 1; i <= b; ++i) {
		p1.push_back(i);
		if (p1[j] >= p2[j]) {
			cout << "NO\n";
			return;
		}
		j++;
	}

	for (size_t i = a+b+1; i <= n; ++i) {
		p1.push_back(i);
		if (p1[j] != p2[j]) {
			cout << "NO\n";
			return;
		}
		j++;
	}

	cout << "YES\n";
	for (size_t i = 0; i < p1.size(); ++i) {
		cout << p1[i] << " ";
	}
	cout << "\n";
	for (size_t i = 0; i < p2.size(); ++i) {
		cout << p2[i] << " ";
	}
	cout << "\n";
}

int main() {
	ll T;
	cin >> T;
	for (ll t = 0; t < T; ++t) {
		solve();
	}
	return 0;
}
