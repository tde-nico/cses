#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll N, X, num, sum = 0, cnt = 0;
	map<ll, ll> prefix_sums;
	cin >> N >> X;
	prefix_sums[0] = 1;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		sum += num;
		cnt += prefix_sums[sum - X];
		prefix_sums[sum]++;
	}
	cout << cnt << "\n";
	return 0;
}
