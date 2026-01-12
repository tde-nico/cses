#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;

	dp.resize(n+1, vector<int>(m+1, 0));
	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < m+1; ++j) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	vector<int> res;
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (a[i-1] == b[j-1]) {
			res.push_back(a[i-1]);
			i--; j--;
		} else if (dp[i-1][j] > dp[i][j-1]) {
			i--;
		} else {
			j--;
		}
	}
	reverse(res.begin(), res.end());

	cout << res.size() << "\n";
	for (int x : res) cout << x << " ";
	cout << "\n";
}
