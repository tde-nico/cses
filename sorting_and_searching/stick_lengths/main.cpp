#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int N;
	ll median = 0, cnt = 0;
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	
	sort(P.begin(), P.end());
	median = P[(N-1) /2];
	for (int i = 0; i < N; ++i) {
		cnt += abs(P[i] - median);
	}
	cout << cnt << "\n";
	
	return 0;
}
