#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 20

int main() {
	ll N, X;
	cin >> N >> X;
	vector<ll> W(N);
	for (ll i = 0; i < N; ++i) {
		cin >> W[i];
	}

	vector<pair<ll, ll>> dp(1 << N);
	dp[0] = {1, 0};
	for (ll mask = 1; mask < (1<<N); ++mask) {
		dp[mask] = {MAXN+1, 0};
		for (ll i = 0; i < N; ++i) {
			if (!(mask & (1 << i))) {
				continue;
			}
			pair<ll, ll> curr = dp[mask ^ (1 << i)];
			if (curr.second + W[i] <= X) {
				curr.second += W[i];
			} else {
				curr.first++;
				curr.second = W[i];
			}
			dp[mask] = min(dp[mask], curr);
		}
	}

	// for (ll i = 0; i < (1 << N); ++i) {
	// 	cout << "[" << dp[i].first << " " << dp[i].second << "] ";
	// }
	// cout << "\n";

	cout << dp[(1 << N) - 1].first << "\n";
	return 0;
}
