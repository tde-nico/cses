#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int N;
	cin >> N;
	vector<pair<ll, ll>> T(N);
	for (int i = 0; i < N; ++i) {
		cin >> T[i].first >> T[i].second;
	}
	sort(T.begin(), T.end());
	ll time = 0, reward = 0;
	for (int i = 0; i < N; ++i) {
		time += T[i].first;
		reward += T[i].second - time;
	}
	cout << reward << "\n";
	return 0;
}
