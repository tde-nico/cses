#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, tmp;
	cin >> N;
	vector<int> X(N+1);
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		X[tmp] = i;
	}
	
	int cnt = 1;
	for (int i = 2; i <= N; ++i) {
		if (X[i-1] > X[i])
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}
