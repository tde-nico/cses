#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (ll &x : v) cin >> x;

	map<ll, ll> m;
	for (ll i = 0; i < n; ++i) {
		m[v[i]]++;

		if (i >= k) {
			m[v[i-k]]--;
			if (m[v[i-k]] == 0)
				m.erase(v[i-k]);
		}
		
		if (i >= k-1)
			cout << m.size() << " ";
	}
	cout << "\n";
}
