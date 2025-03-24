#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> X(N);
	stack<int> smalls;
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
		while (!smalls.empty() && X[smalls.top()] >= X[i]) {
			smalls.pop();
		}
		if (smalls.empty()) {
			cout << "0 ";
		} else {
			cout << smalls.top() + 1 << " ";
		}
		smalls.push(i);
	}

	return 0;
}
