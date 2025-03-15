#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int mx = 0, count;
	string line;
	cin >> line;
	for (size_t i = 0; i < line.size(); ++i) {
		count = 1;
		while (line[i] == line[i+1] && i+1 < line.size()) {
			++i;
			++count;
		}
		mx = max(mx, count);
	}
	cout << mx << "\n";
	return 0;
}
