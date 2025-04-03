#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, num;
	cin >> N;

	multiset<int> s;
	multiset<int>::iterator it;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		s.insert(num);
		it = next(s.lower_bound(num));
		if (it != s.end()) {
			s.erase(it);
		}
	}

	cout << s.size() << "\n";
	return 0;
}
