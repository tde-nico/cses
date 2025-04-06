#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> X;
vector<ll> prefix;
vector<vector<ll>> dp;
vector<vector<bool>> visited;

void fill(ll i, ll j) {
	if (visited[i][j]) {
		return;
	}
	visited[i][j] = true;
	fill(i+1, j);
	fill(i, j-1);
	dp[i][j] = max(X[i-1] + prefix[j] - prefix[i] - dp[i+1][j], X[j-1] + prefix[j-1] - prefix[i-1] - dp[i][j-1]);
}

int main() {
	ll N;
	cin >> N;
	X.reserve(N);
	prefix.assign(N+1, 0);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
		prefix[i+1] = prefix[i] + X[i];
	}

	dp.assign(N+1, vector<ll>(N+1, 0));
	visited.assign(N+1, vector<bool>(N+1, false));
	visited[0][0] = true;
	for (int i = 1; i <= N; ++i) {
		visited[i][i] = true;
		dp[i][i] = X[i-1];
	}
	fill(1LL, N);

	// for (int i = 0; i <= N; ++i) {
	// 	for (int j = 0; j <= N; ++j) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << dp[1][N] << "\n";
	return 0;
}
