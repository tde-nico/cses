#include <bits/stdc++.h>

using namespace std;

#define SIZE 100001

int main() {
	bitset<SIZE> bs;
	int N, x;
	cin >> N;
	bs[0] = true;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		bs |= bs << x;
	}
	cout << bs.count()-1 << "\n";
	for (int i = 1; i < SIZE; ++i) {
		if (bs[i]) {
			cout << i << " ";
		}
	}
}
