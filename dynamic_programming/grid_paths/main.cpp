#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
	int N;
	cin >> N;
	vector<vector<char>> grid(N+1, vector<char>(N+1, '\0'));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> grid[i][j];
		}
	}
	
	vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
	dp[1][1] = (grid[1][1] == '.');
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (grid[i][j] != '.')
				continue;
			dp[i][j] += dp[i-1][j] + dp[i][j-1];
			dp[i][j] %= MOD;
		}
	}

	cout << dp[N][N] << "\n";
	return 0;
}
