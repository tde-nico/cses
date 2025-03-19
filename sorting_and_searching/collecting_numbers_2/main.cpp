#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> X(N+2), Y(N+2);
	for (int i = 1; i <= N; ++i) {
		cin >> Y[i];
		X[Y[i]] = i;
	}
	X[N+1] = N+1;
	
	ll cnt = 1;
	for (int i = 2; i <= N; ++i) {
		if (X[i-1] > X[i])
			cnt++;
	}

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;

		if (X[Y[a]-1] <= X[Y[a]] && b < X[Y[a]-1] ||
			X[Y[a]+1] >= X[Y[a]] && b > X[Y[a]+1])
			cnt++;
		if (X[Y[a]-1] > X[Y[a]] && b >= X[Y[a]-1] ||
			X[Y[a]+1] < X[Y[a]] && b <= X[Y[a]+1])
			cnt--;
		X[Y[a]] = b;
			
		if (X[Y[b]-1] <= X[Y[b]] && a < X[Y[b]-1] ||
			X[Y[b]+1] >= X[Y[b]] && a > X[Y[b]+1])
			cnt++;
		if (X[Y[b]-1] > X[Y[b]] && a >= X[Y[b]-1] ||
			X[Y[b]+1] < X[Y[b]] && a <= X[Y[b]+1])
			cnt--;
		X[Y[b]] = a;
		
		swap(Y[a], Y[b]);

		cout << cnt << "\n";
	}

	return 0;
}
