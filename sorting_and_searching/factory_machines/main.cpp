#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool F(vector<ll> &K, ll T, ll value) {
	ll sum = 0;
	for (int i = 0; i < K.size(); ++i) {
		sum += value / K[i];
		if (sum >= T) {
			return false;
		}
	}
	return true;
}

int main() {
	ll N, T;
	cin >> N >> T;
	vector<ll> K(N);
	for (int i = 0; i < N; ++i) {
		cin >> K[i];
	}
	ll mid, l = 0, r = 0x7FFFFFFFFFFFFFFFLL;
	while (l <= r) {
		mid = (l + r) / 2;
		if (F(K, T, mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << l << "\n";
	return 0;
}
