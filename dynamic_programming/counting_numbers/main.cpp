#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[20][10][2][2];

ll mem(string s, ll curr, ll prev_digit, ll leading_zero, ll tight) {
	if (!curr) {
		return 1;
	}

	if (dp[curr][prev_digit][leading_zero][tight] != -1) {
		return dp[curr][prev_digit][leading_zero][tight];
	}

	ll limit = tight ? s[s.size()-curr]-48 : 9;
	ll new_leading_zero, new_tight, cnt = 0;
	for (ll curr_digit = 0; curr_digit <= limit; ++curr_digit) {
		if (!leading_zero && (curr_digit == prev_digit)) {
			continue;
		}
		new_leading_zero = (leading_zero && !curr_digit) ? 1 : 0;
		new_tight = (curr_digit == limit && tight) ? 1 : 0;
		cnt += mem(s, curr-1, curr_digit, new_leading_zero, new_tight);
	}

	dp[curr][prev_digit][leading_zero][tight] = cnt;
	return cnt;
}

int main() {
	ll A, B, cnt1 = 0, cnt2 = 0;
	string s1, s2;
	cin >> A >> B;

	memset(dp, -1, sizeof(dp));
	s1 = to_string(A-1);
	if (A) {
		cnt1 = mem(s1, s1.size(), -1, 1, 1);
	}

	memset(dp, -1, sizeof(dp));
	s2 = to_string(B);
	cnt2 = mem(s2, s2.size(), -1, 1, 1);

	cout << cnt2 - cnt1 << "\n";
	return 0;
}
