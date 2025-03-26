#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll N, num, sum = 0, cnt = 0;
	map<ll, ll> prefix_sums;
	cin >> N;
	prefix_sums[0] = 1;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		sum = ((sum + num) % N + N) % N;
		cnt += prefix_sums[sum];
		prefix_sums[sum]++;
	}
	cout << cnt << "\n";
	return 0;
}
