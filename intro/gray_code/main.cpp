#include <bits/stdc++.h>

using namespace std;

int N;
bitset<16> bs;

void print() {
	for (int i = N; i > 0; --i) {
		cout << int(bs[i]);
	}
	cout << "\n";
}

int main() {
	int LSB;
	cin >> N;
	print();
	for (int i = 1; i < (1<<N); ++i) {
		LSB = __builtin_ffs(i);
		bs[LSB] = bs[LSB] ^ true;
		print();
	}
	return 0;
}
