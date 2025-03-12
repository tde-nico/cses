#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll out = 1;
	for (int i = 0; i < n; ++i)
		out = (out << 1) % 1000000007;
	cout << out << "\n";
	return 0;
}
