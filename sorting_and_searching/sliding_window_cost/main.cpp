#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll N, K, sum1 = 0, sum2 = 0;
	cin >> N >> K;
	vector<ll> X(N);
	multiset<int> lower, upper;
	ll max_lower, min_upper, median;
	for (int i = 0; i < N; ++i) {
		cin >> X[i];

		if (i >= K) {
			if (lower.count(X[i-K])) {
				lower.erase(lower.find(X[i-K]));
				sum1 -= X[i-K];
			} else {
				upper.erase(upper.find(X[i-K]));
				sum2 -= X[i-K];
			}
		}
		
		if (lower.size() <= upper.size()) {
			lower.insert(X[i]);
			sum1 += X[i];
		} else {
			upper.insert(X[i]);
			sum2 += X[i];
		}

		if (lower.size() > 0 && upper.size() > 0) {
			max_lower = *lower.rbegin();
			min_upper = *upper.begin();
			if (max_lower > min_upper) {
				lower.erase(prev(lower.end()));
				upper.erase(upper.begin());
				lower.insert(min_upper);
				upper.insert(max_lower);
				sum1 += min_upper - max_lower;
				sum2 += max_lower - min_upper;
			}
		}

		if (i >= K-1) {
			cout << (lower.size() * *lower.rbegin() - sum1) + (sum2 - upper.size() * *lower.rbegin()) << " ";
		}
	}
	return 0;
}
