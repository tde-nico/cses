#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
	int N, K;
	indexed_set s;
	cin >> N >> K;
	vector<int> X(N);
	for (int i = 0; i < K-1; ++i) {
		cin >> X[i];
		s.insert({X[i], i});
	}
	for (int i = K-1; i < N; ++i) {
		cin >> X[i];
		s.insert({X[i], i});
		cout << s.find_by_order((K-1)/2)->first << " ";
		s.erase({X[i-K+1], i-K+1});
	}
	return 0;
}
