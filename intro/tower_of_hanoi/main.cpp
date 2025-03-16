#include <bits/stdc++.h>

using namespace std;

void step(int from, int to, int depth) {
	if (depth == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	int next = 6 - from - to;
	step(from, next, depth - 1);
	cout << from << " " << to << "\n";
	step(next, to, depth - 1);
}

int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	step(1, 3, n);
	return 0;
}
