#include <bits/stdc++.h>

using namespace std;

int main() {
	unordered_map<char, int> counter;
	string in, out = "";
	cin >> in;
	for (int i = 0; i < in.size(); ++i) {
		if (counter.count(in[i])) {
			counter[in[i]]++;
		} else {
			counter[in[i]] = 1;
		}
	}
	if (in.size() % 2) {
		char odd = '\0';
		for (auto [k,v] : counter) {
			if (v % 2) {
				if (odd != '\0') {
					cout << "NO SOLUTION";
					return 0;
				}
				odd = k;
			}
			out += string(v/2, k);
		}
		string tmp = out;
		reverse(tmp.begin(), tmp.end());
		cout << out << odd << tmp << "\n";
	} else {
		for (auto [k,v] : counter) {
			if (v % 2) {
				cout << "NO SOLUTION";
				return 0;
			}
			out += string(v/2, k);
		}
		string tmp = out;
		reverse(tmp.begin(), tmp.end());
		cout << out << tmp << "\n";
	}
	return 0;
}
