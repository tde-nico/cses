#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
	int N, i;
	cin >> N;
	indexed_set s;
	for (i = 1; i <= N; ++i)
		s.insert(i);
	i = 1;
	while (s.size()) {
		i %= s.size();
		int curr = *s.find_by_order(i);
		s.erase(curr);
		cout << curr << " ";
		++i;
	}

	return 0;
}
