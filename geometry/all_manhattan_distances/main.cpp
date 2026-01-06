#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void print_int128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    if (x < 0) {
        cout << '-';
        x = -x;
    }

    string res;
    while (x > 0) {
        res += (x % 10) + '0';
        x /= 10;
    }

    reverse(res.begin(), res.end());

    cout << res << "\n";
}

int main() {
	ll n;
	cin >> n;

	vector<ll> x(n), y(n);
	for (ll i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	__int128 sum = 0;
	ll curr_sum = 0;
	for (ll i = 0; i < n; ++i) {
		sum += (x[i] + y[i]) * i - curr_sum;
		curr_sum += x[i] + y[i];
	}

	print_int128(sum);

	return 0;
}
