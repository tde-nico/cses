#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, digit;
	cin >> N;
	vector<int> dp(N+1, 0x7fffffff);
	dp[0] = 0;
	for (int i = 1; i <= N; ++i) {
		digit = i;
		while (digit > 0) {
			if (digit % 10)
				dp[i] = min(dp[i], dp[i - (digit % 10)]+1);
			digit /= 10;
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
