#include <bits/stdc++.h>

using namespace std;

#define MAX_INT 0x7fffffff

int main() {
	int N, X;
	cin >> N >> X;
	vector<int> coins(N);
	for (int i = 0; i < N; ++i) {
		cin >> coins[i];
	}

	vector<int> dp(X+1, MAX_INT);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= X-coins[i]; ++j) {
			if (dp[j] == MAX_INT)
				continue;
			dp[j+coins[i]] = min(dp[j+coins[i]], dp[j]+1);
		}
	}
	if (dp[X] == MAX_INT) {
		cout << "-1\n";
	} else {
		cout << dp[X] << "\n";
	}
	return 0;
}
