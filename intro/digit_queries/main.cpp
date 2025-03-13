#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow10(int n) {
	ll p = 1;
	while (n--)
		p *= 10;
	return p;
}

int main() {
	int T;
	ll k;
	int len;
	string s;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> k;
		--k;
		len = 1;
		while (9 * pow10(len-1) * len < k)
			k -= 9 * pow10(len-1) * len++;
		s = to_string(pow10(len - 1) + k / len);
		cout << (int)(s[k % len] - '0') << "\n";
	}
	return 0;
}
