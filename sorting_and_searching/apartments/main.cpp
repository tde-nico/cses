#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> n(N);
	for (int i = 0; i < N; ++i)
		cin >> n[i];
	vector<int> m(M);
	for (int i = 0; i < M; ++i)
		cin >> m[i];
	
	sort(n.begin(), n.end());
	sort(m.begin(), m.end());
	int cnt = 0, i = 0, j = 0;
	while (i < N && j < M) {
		if (n[i] < m[j] - K) {
			i++;
		} else if (n[i] <= m[j] + K) {
			cnt++;
			i++;
			j++;
		} else {
			j++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
