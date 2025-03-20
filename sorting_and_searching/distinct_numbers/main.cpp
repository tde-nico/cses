#include <bits/stdc++.h>

using namespace std;

int main() {
	set<int> nums;
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		nums.insert(tmp);
	}
	cout << nums.size() << "\n";
}