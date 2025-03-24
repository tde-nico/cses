#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> M(N);
	for (int i = 0; i < N; ++i) {
		cin >> M[i].second >> M[i].first;
	}

	sort(M.begin(), M.end());
	
	multiset<int> ends;
	for (int i = 0; i < K; ++i) {
		ends.insert(0);
	}

	int cnt = 0;
	multiset<int>::iterator it;
	for (int i = 0; i < N; ++i) {
		it = ends.upper_bound(M[i].second);
		if (it == ends.begin()) {
			continue;
		}
		ends.erase(prev(it));
		ends.insert(M[i].first);
		cnt++;
	}

	cout << cnt << "\n";
	return 0;
}
