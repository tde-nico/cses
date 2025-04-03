#include <bits/stdc++.h>

using namespace std;

int main() {
	string A, B;
	cin >> A;
	cin >> B;
	int N = A.size();
	int M = B.size();
	
	vector<vector<int>> dp(N+1, vector<int>(M+1, 0x7fffffff));
	for (int i = 0; i <= N; ++i) {
		dp[i][0] = i;
	}
	for (int i = 1; i <= M; ++i) {
		dp[0][i] = i;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i-1][j-1] + (A[i-1] != B[j-1]));
		}
	}

	// for (int i = 0; i <= N; ++i) {
	// 	for (int j = 0; j <= M; ++j) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << dp[N][M] << "\n";
	return 0;
}
