#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k, x, a, b, c;
	cin >> n >> k;
	cin >> x >> a >> b >> c;

	ll res = 0;
	deque<ll> q, nums;
	for (ll i = 0; i < n; ++i) {
		while (!q.empty() && q.back() > x)
			q.pop_back();
		
		q.push_back(x);
		nums.push_back(x);
		
		if (i >= k && q.front() == nums.front())
			q.pop_front();
		if (nums.size() > k)
			nums.pop_front();
		
		if (i >= k-1)
			res ^= q.front();
		x = (a * x + b) % c;
	}

	cout << res << "\n";
}
