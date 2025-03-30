#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll costs[1001], pages[1001];
ll dp[100001] = {0};

int main() {
	ll N, X;
	cin >> N >> X;
	for (int i = 0; i < N; ++i) {
		cin >> costs[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> pages[i];
	}

	ll val, wg;
	for (int i = 0; i < N; ++i) {
		val = pages[i];
		wg = costs[i];
		for (int j = X; j > 0; --j) {
			if (wg > j) {
				continue;
			}
			dp[j] = max(dp[j], dp[j-wg] + val);
		}
	}
	cout << dp[X] << "\n";
	return 0;
}
