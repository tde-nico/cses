#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n = 0;

	cin >> n;
	cout << n;
	while (n > 1) {
		if (n % 2) {
			n = n * 3 + 1;
		} else {
			n /= 2;
		}
		cout << " " << n;
	}
	cout << "\n";
	return 0;
}

