#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll N, A, B;
	cin >> N >> A >> B;
	vector<ll> prefix(N+1);
	prefix[0] = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> prefix[i];
		prefix[i] += prefix[i-1];
	}
	
	multiset<ll> maxs;
	for (int i = A; i <= B; ++i) {
		maxs.insert(prefix[i]);
	}

	ll mx = *maxs.rbegin();
	for (int i = 1; i+A <= N; ++i) {
		maxs.erase(prefix[i+A-1]);
		maxs.insert(prefix[min(i+B, N)]);
		mx = max(mx, *maxs.rbegin() - prefix[i]);
	}
	
	cout << mx << "\n";
	return 0;
}
