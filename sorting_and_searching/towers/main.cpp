#include <bits/stdc++.h>

using namespace std;

int main() {
	multiset<int> s;
	multiset<int>::iterator it;
	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		it = s.upper_bound(tmp);
		if (it != s.end()) {
			s.erase(it);
		}
		s.insert(tmp);
	}
	cout << s.size() << "\n";
	return 0;
}
