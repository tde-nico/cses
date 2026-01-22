#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll &x : v) cin >> x;

	stack<ll> s;
	vector<ll> l(n), r(n);
	for (ll i = 0; i < n; ++i) {
		while (s.size() && v[s.top()] >= v[i]) s.pop();
		l[i] = s.empty() ? -1 : s.top();
		s.push(i);
	}
	s = {};
	for (ll i = n-1; i >= 0; --i) {
		while (s.size() && v[s.top()] >= v[i]) s.pop();
		r[i] = s.empty() ? n : s.top();
		s.push(i);
	}

	ll res = 0;
	for (ll i = 0; i < n; ++i)
		res = max(res, v[i] * (r[i] - l[i] - 1));
	cout << res << "\n";
}
