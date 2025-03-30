#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> X(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
	}

	vector<vector<ll>> dp(N+1, vector<ll>(M+1));
	if (X[0]) {
		dp[1][X[0]] = 1;
	} else {
		dp[1].assign(M+1, 1);
	}

	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = dp[i-1][j];
			if (j != 1)
				dp[i][j] += dp[i-1][j-1];
			if (j != M)
				dp[i][j] += dp[i-1][j+1];
			dp[i][j] %= MOD;
		}

		if (X[i-1]) {
			for (int j = 0; j <= M; ++j) {
				if (j != X[i-1]) {
					dp[i][j] = 0;
				}
			}
		}
	}

	// for (int i = 0; i <= N; ++i) {
	// 	for (int j = 0; j <= M; ++j) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	ll res = 0;
	for (int i = 1; i <= M; ++i) {
		res = (res + dp[N][i]) % MOD;
	}

	cout << res << "\n";
	return 0;
}
