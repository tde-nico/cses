#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	set<ll> ranges;
	multiset<ll> lenghts;

	ll X, N, p;
	cin >> X >> N;

	ranges.insert({0, X});
	lenghts.insert(X);

	set<ll>::iterator it;
	ll start, end;
	for (ll i = 0; i < N; ++i) {
		cin >> p;
		it = ranges.upper_bound(p);
		start = *prev(it);
		end = *it;

		lenghts.erase(lenghts.find(end-start));

		ranges.insert(p);
		lenghts.insert(p - start);
		lenghts.insert(end - p);

		cout << *lenghts.rbegin() << " ";
	}
	return 0;
}
