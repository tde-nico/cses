#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct s_project {
	ll time;
	int id;
	bool type;
} project;

int main() {
	ll N;
	cin >> N;
	vector<ll> A(N+1);
	vector<ll> B(N+1);
	vector<ll> P(N+1);
	vector<project> projects(2*(N+1));
	for (int i = 1; i <= N; ++i) {
		cin >> A[i] >> B[i] >> P[i];
		projects[2*i] = {A[i], i, false};
		projects[2*i+1] = {B[i], i, true};
	}

	
	sort(next(next(projects.begin())), projects.end(), [](project a, project b){
		return a.time == b.time ? a.id < b.id : a.time < b.time;
	});
	
	map<ll, ll> time_to_index;
	for (int i = 2; i < projects.size(); ++i) {
		if (!time_to_index[projects[i].time]) {
			time_to_index[projects[i].time] = i;
		}
	}

	vector<ll> dp(2*N+2, 0);
	for (int i = 2; i < 2*N+2; ++i) {
		if (projects[i].type) {
			dp[i] = max(dp[i-1], dp[time_to_index[A[projects[i].id]]-1] + P[projects[i].id]);
		} else {
			dp[i] = dp[i-1];
		}
	}

	// for (int i = 0; i < 2*N+2; ++i) {
	// 	cout << dp[i] << " ";
	// }
	// cout << "\n";

	cout << dp[2*N+1] << "\n";
	return 0;
}
