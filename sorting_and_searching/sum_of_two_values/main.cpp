#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, X, tmp;
	map<int, int> others;
	cin >> N >> X;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		if (others.count(tmp)) {
			cout << others[tmp]+1 << " " << i+1 << "\n";
			return 0;
		}
		others[X-tmp] = i;
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
