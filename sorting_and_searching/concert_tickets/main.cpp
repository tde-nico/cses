#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M, tmp;
	cin >> N >> M;
	multiset<int> H;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		H.insert(tmp);
	}
	vector<int> T(M);
	for (int i = 0; i < M; ++i)
		cin >> T[i];

	int ticket, curr;
	multiset<int>::iterator it;
	for (int i = 0; i < M; ++i) {
		curr = T[i];
		it = H.lower_bound(curr);
		if (*it == curr) {
			ticket = *it;
			H.erase(it);
		} else if (it == H.begin()) {
			ticket = -1;
		} else {
			it = prev(it);
			ticket = *it;
			H.erase(it);
		}
		cout << ticket << "\n";
	}

	return 0;
}
