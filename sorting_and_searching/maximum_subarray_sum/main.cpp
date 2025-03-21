#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int N;
	cin >> N;
	ll tmp, sum = 0, mx = -9223372036854775808;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		sum = max(tmp, sum+tmp);
		mx = max(mx, sum);
	}
	cout << mx << "\n";
	return 0;
}
