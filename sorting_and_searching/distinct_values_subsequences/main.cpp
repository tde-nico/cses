#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
	ll n, x;
	map<ll, ll> freq;
	cin >> n;
	while (n--) {
		cin >> x;
		freq[x]++;
	}

	ll count = 1;
	for (auto [_, f] : freq) {
		count = (count * (f+1)) % MOD;
	}

	cout << count - 1 << "\n";

	return 0;
}
