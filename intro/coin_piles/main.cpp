#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int a, b;
		cin >> a >> b;
		if ((a+b)%3 != 0 || a > 2*b || b > 2*a) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
	return 0;
}
