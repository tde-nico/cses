#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll N, M;
vector<vector<ll>> dp;

void fill_column(ll col, ll idx, ll curr_mask, ll next_mask) {
	if (idx == N) {
		dp[col+1][next_mask] = (dp[col+1][next_mask] + dp[col][curr_mask]) % MOD;
		return;
	}
	if (curr_mask & (1 << idx)) {
		fill_column(col, idx+1, curr_mask, next_mask);
	} else {
		fill_column(col, idx+1, curr_mask, next_mask | (1 << idx));
		if (idx+1 < N && !(curr_mask & (1 << (idx+1)))) {
			fill_column(col, idx+2, curr_mask, next_mask);
		}
	}
}

int main() {
	cin >> N >> M;

	dp.assign(M+1, vector<ll>(1 << N, 0));
	dp[0][0] = 1;
	for (ll i = 0; i < M; ++i) {
		for (ll mask = 0; mask < (1 << N); ++mask) {
			if (dp[i][mask] > 0) {
				fill_column(i, 0, mask, 0);
			}
		}
	}

	cout << dp[M][0] << "\n";
	return 0;
}
