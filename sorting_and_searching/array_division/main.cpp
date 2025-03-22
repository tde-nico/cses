#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool F(vector<ll> &X, ll K, ll mid) {
	ll sum = 0, k = 1;
	for (int i = 0; i < X.size(); ++i) {
		sum += X[i];
		if (sum > mid) {
			k++;
			sum = X[i];
		}
	}
	return k > K;
}

int main() {
	ll N, K, l = 0;
	cin >> N >> K;
	vector<ll> X(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
		l = max(l, X[i]);
	}
	ll mid, r = 1e18;
	while (l <= r) {
		mid = (l + r) / 2;
		if (F(X, K, mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << l << "\n";
	return 0;
}
