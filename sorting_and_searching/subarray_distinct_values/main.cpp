#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll N, K;
	cin >> N >> K;
	vector<ll> X(N+1);
	for (int i = 1; i <= N; ++i) {
		cin >> X[i];
	}
	
	map<ll, ll> uniques;
	ll cnt = 0, unique = 0, r = 0;
	for (ll l = 1; l <= N; ++l) {
		while (r < N && (uniques[X[r+1]] >= 1 || unique < K)) {
			if (++uniques[X[++r]] == 1) {
				unique++;
			}
		}		
		cnt += (r - l + 1);
		if (!(--uniques[X[l]]))
			unique--;
	}
	cout << cnt << "\n";
	return 0;
}
