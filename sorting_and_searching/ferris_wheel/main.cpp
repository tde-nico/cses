#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	vector<int> wgs(N);
	for (int i = 0; i < N; ++i)
		cin >> wgs[i];
	
	int r, l = 0, cnt = 0;
	sort(wgs.begin(), wgs.end());
	for (r = N-1; r >= l; --r) {
		if (wgs[l] + wgs[r] <= X)
			++l;
		++cnt;
	}
	cout << cnt << "\n";
	return 0;
}
