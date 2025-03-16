#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n;
	ll perms, triangle = 0;
	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		perms = (i * i * ((i * i) - 1)) / 2;
		if (i > 2)
			triangle += i-2;
		perms -= 8 * triangle;
		cout << perms << "\n";
	}
	return 0;
}
