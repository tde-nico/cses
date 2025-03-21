#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
	int N, K, i;
	cin >> N >> K;
	indexed_set s;
	for (i = 1; i <= N; ++i)
		s.insert(i);
	i = K;
	while (s.size()) {
		i %= s.size();
		int curr = *s.find_by_order(i);
		s.erase(curr);
		cout << curr << " ";
		i += K;
	}

	return 0;
}
