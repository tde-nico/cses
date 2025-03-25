#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> K(N);
	for (int i = 0; i < N; ++i) {
		cin >> K[i];
	}

	map<int, int> sequences;
	int k, l = 1, longest = 0;
	for (int r = 1; r <= N; ++r) {
		k = K[r-1];
		if (sequences[k]) {
			longest = max(longest, r-l);
			l = max(l, sequences[k]+1);
		} else {
			longest = max(longest, r-l+1);
		}
		sequences[k] = r;
	}

	longest = max(longest, N-l+1);
	cout << longest << "\n";

	return 0;
}
