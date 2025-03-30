#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
	int N, X, coin;
	cin >> N >> X;
	vector<int> dp(X+1, 0);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		cin >> coin;
		for (int j = 0; j <= X-coin; ++j) {
			dp[j+coin] = (dp[j+coin] + dp[j]) % MOD;
		}
	}
	cout << dp[X] << "\n";
	return 0;
}
