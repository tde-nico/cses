#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
	int N;
	cin >> N;
	vector<int> dp(N+1);
	dp[0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= 6 && i-j >= 0 ; ++j) {
			dp[i] = (dp[i] + dp[i-j]) % MOD;
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
