#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	
	if (n%4 == 1 || n%4 == 2) {
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	cout << n/2 << "\n";
	if (n%4 == 3) {
		for (int i = 2; i <= n/2; i += 2)
			cout << i << " " << n-i << " ";
		cout << n << "\n" << n/2+1 << "\n";
		for (int i = 1; i <= n/2; i += 2)
			cout << i << " " << n-i << " ";
	} else {
		for (int i = 2; i <= n/2; i += 2)
			cout << i << " " << n-i+1 << " ";
		cout << "\n" << n/2 << "\n";
		for (int i = 1; i <= n/2; i += 2)
			cout << i << " " << n-i+1 << " ";
	}
	return 0;
}
