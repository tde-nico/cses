#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	for (auto &y : grid) for (char &x : y) cin >> x;

	string res;
	res.reserve(2*n - 1);
	res.push_back(grid[0][0]);

	vector<pair<int, int>> curr, next;
	curr.push_back({0, 0});
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	visited[0][0] = true;

	for (int i = 1; i < 2*n-1; ++i) {
		char best = 'Z'+1;
		next.clear();

		for (auto [y, x] : curr) {
			if (y+1 < n) best = min(best, grid[y+1][x]);
			if (x+1 < n) best = min(best, grid[y][x+1]);
		}

		for (auto [y, x] : curr) {
			if (y+1 < n && grid[y+1][x] == best && !visited[y+1][x]) {
				visited[y+1][x] = true;
				next.push_back({y+1, x});
			}
			if (x+1 < n && grid[y][x+1] == best && !visited[y][x+1]) {
				visited[y][x+1] = true;
				next.push_back({y, x+1});
			}
		}

		res.push_back(best);
		curr.swap(next);
	}

	cout << res << "\n";
}
