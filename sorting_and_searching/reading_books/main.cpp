#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int N;
	cin >> N;
	ll tmp, mx = 0, sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		mx = max(mx, tmp);
		sum += tmp;
	}
	cout << max(2*mx, sum) << "\n";
	return 0;
}
