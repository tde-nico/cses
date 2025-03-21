#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int N;
	cin >> N;
	vector<ll> X(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
	}
	
	sort(X.begin(), X.end());
	ll coin = 1;
	for (int i = 0; i < N && X[i] <= coin; ++i) {
		coin += X[i];
	}
	cout << coin << "\n";
	return 0;
}
