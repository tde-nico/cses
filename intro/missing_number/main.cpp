#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	bitset<200001> nums;
	int n, num;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		nums[num - 1] = true;
	}
	for (int i = 0; i < n; ++i) {
		if (!nums[i]) {
			cout << i + 1 << "\n";
			break;
		}
	}
	return 0;
}
