#include <bits/stdc++.h>

using namespace std;

struct Movie {
	int time;
	int idx;
	int type;
};

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<Movie> movies(N*2);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> movies[i*2+1].time;
		movies[i*2].time = A[i];
		movies[i*2].idx = i;
		movies[i*2+1].idx = i;
		movies[i*2].type = 0;
		movies[i*2+1].type = 1;
	}

	sort(movies.begin(), movies.end(), [](Movie m1, Movie m2){
		return m1.time == m2.time ? m1.idx < m2.idx : m1.time < m2.time;
	});

	map<int, int> ids;
	for (int i = 0; i < N*2; ++i)
		ids[movies[i].time] = i+1;

	vector<int> dp(N*2+1);
	dp[0] = 0;
	for (int i = 1; i < N*2+1; ++i) {
		if (movies[i-1].type)
			dp[i] = max(dp[ids[A[movies[i-1].idx]]]+1, dp[i-1]);
		else
			dp[i] = dp[i-1];
	}

	cout << dp[N*2] << "\n";

	return 0;
}
