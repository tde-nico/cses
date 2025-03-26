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

	sort(A.begin(), A.end());
	int l, r, val, tmp;
	for (int i = 0; i < N; ++i) {
		tmp = X - A[i].first;
		for (int j = i+1; j < N; ++j) {
			val = tmp - A[j].first;
			r = N-1;
			for (l = j+1; l < r; ++l) {
				while (l+1 < r && A[l].first + A[r].first > val)
					--r;
				if (A[l].first + A[r].first == val) {
					cout << A[i].second << " " << A[j].second << " " << A[l].second << " " << A[r].second << "\n";
					return 0;
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
