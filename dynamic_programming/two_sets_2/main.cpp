#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int main() {
	ll N;
	cin >> N;
	
	ll sum = (N * (N + 1LL)) / 2LL;
	if (sum % 2) {
		cout << "0\n";
		return 0;
	}
	
	sum = sum / 2;
	vector<ll> dp(sum+1, 0);
	dp[0] = 1;
	for (ll i = 1; i < N; ++i) {
		for (ll j = sum; j >= i; --j) {
			dp[j] += dp[j - i];
			dp[j] %= MOD;
		}
	}

	cout << dp[sum] << "\n";
	return 0;
}
