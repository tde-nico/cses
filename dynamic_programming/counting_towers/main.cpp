#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007
#define SIZE 1000001

ll dp[SIZE];

void fill() {
	dp[0] = 0;
	dp[1] = 2;
	dp[2] = 8;
	for (int i = 3; i < SIZE; ++i) {
		dp[i] = ((dp[i-1] * 6 - dp[i-2] * 7) % MOD + MOD) % MOD;
	}
}

int main() {
	fill();
	int T, N;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}
