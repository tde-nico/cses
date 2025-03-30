#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
	int N, X;
	cin >> N >> X;
	vector<int> coins(N);
	for (int i = 0; i < N; ++i) {
		cin >> coins[i];
	}

	vector<int> dp(X+1, 0);
	dp[0] = 1;
	for (int i = 0; i < X; ++i) {
		if (!dp[i])
			continue;
		for (int j = 0; j < N; ++j) {
			if (i+coins[j] > X)
				continue;
			dp[i+coins[j]] = (dp[i+coins[j]] + dp[i]) % MOD;
		}
	}
	cout << dp[X] << "\n";
	return 0;
}
