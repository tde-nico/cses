#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	
	ll chars[26];
	memset(chars, 0, sizeof(chars));
	for (char c : s) {
		chars[c - 'A'] += 1;
	}

	for (ll cnt : chars) {
		if (cnt > ((n+1)/2)) {
			cout << "-1\n";
			return 0;
		}
	}

	string res;
	char prev = '\0';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (!chars[j]) {
				continue;
			}
			
			char curr = j + 'A';
			if (curr == prev) {
				continue;
			}

			chars[j]--;
			ll mx = *max_element(chars, chars+26);
			if (mx <= (n-i)/2) {
				res += curr;
				prev = curr;
				break;
			}
			chars[j]++;
		}
	}
	cout << res << "\n";
	return 0;
}
