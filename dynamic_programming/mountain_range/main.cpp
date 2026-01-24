#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	
	vector<pair<ll, ll>> hs(n);
	for (ll i = 0; i < n; ++i) {
		cin >> hs[i].first;
		hs[i].second = i+1;
	}

	sort(hs.rbegin(), hs.rend());

	vector<ll> dp(n+1, 0);
	set<ll> s;
	vector<ll> same;
	ll last = INT_MIN;
	for (auto [h, idx] : hs) {
		if (h != last) {
			for (auto x : same) s.insert(x);
			same.clear();
		}

		auto left = s.lower_bound(idx);
		auto right = s.upper_bound(idx);
		ll l = (left == s.begin() ? 0 : *prev(left));
		ll r = (right == s.end() ? 0 : *right);
		dp[idx] = max(dp[l], dp[r]) + 1;

		same.push_back(idx);
		last = h;
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";
}
