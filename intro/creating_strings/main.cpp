#include <bits/stdc++.h>

using namespace std;

int main() {
	set<string> s;
	string in;
	cin >> in;

	sort(in.begin(), in.end());
	s.insert(in);
	while(next_permutation(in.begin(), in.end())) {
		s.insert(in);
	}
	cout << s.size() << "\n";
	for (auto perm : s) {
		cout << perm << "\n";
	}
	return 0;
}
