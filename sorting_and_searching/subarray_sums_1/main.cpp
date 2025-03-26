#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll N, X, sum = 0, l = 0, cnt = 0;
	cin >> N >> X;
	vector<ll> A(N);
	for (int r = 0; r < N; ++r) {
		cin >> A[r];
		sum += A[r];
		while (sum > X) {
			sum -= A[l++];
		}
		if (sum == X) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
