#include <bits/stdc++.h>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	vector<vector<int>> dp(A+1, vector<int>(B+1, 0x7fffffff));

	for (int i = 0; i <= A; ++i) {
		dp[i][0] = i;
	}
	for (int i = 1; i <= B; ++i) {
		dp[0][i] = i;
	}
	for (int i = 0; i <= min(A, B); ++i) {
		dp[i][i] = 0;
	}

	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			for (int k = 1; k < j; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
			}
			for (int k = 1; k < i; ++k) {
				dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
			}
		}
	}

	// for (int i = 0; i <= A; ++i) {
	// 	for (int j = 0; j <= B; ++j) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << dp[A][B] << "\n";
	return 0;
}
