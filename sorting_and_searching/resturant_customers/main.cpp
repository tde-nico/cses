#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> actions(N*2);
	for (int i = 0; i < N; ++i) {
		cin >> actions[i*2].first >> actions[i*2+1].first;
		actions[i*2].second = +1;
		actions[i*2+1].second = -1;
	}

	sort(actions.begin(), actions.end());

	ll mx = 0, curr = 0;
	for (int i = 0; i < N*2; ++i) {
		auto action = actions[i];
		curr += action.second;
		mx = max(mx, curr);
	}

	cout << mx << "\n";
	
	return 0;
}
