#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n, count = 0;
	cin >> n;
	while (n > 0) {
		n /= 5;
		count += n;
	}
	cout << count;
	return 0;
}
