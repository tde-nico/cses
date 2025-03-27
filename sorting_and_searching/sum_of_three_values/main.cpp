#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first;
		A[i].second = i + 1;
	}

	int l, r, val;
	sort(A.begin(), A.end());
	for (int i = 0; i < N; ++i) {
		val = X - A[i].first;
		r = N-1;
		for (l = i+1; l < r; ++l) {
			while (l+1 < r && A[l].first + A[r].first > val)
				--r;
			if (A[l].first + A[r].first == val) {
				cout << A[i].second << " " << A[l].second << " " << A[r].second << "\n";
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
