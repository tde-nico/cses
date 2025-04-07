#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<char>> grid;
set<int> visited;
pair<int, int> directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int y, int x) {
	int dx, dy;
	visited.insert(y * M + x);
	for (int i = 0; i < 4; ++i) {
		dx = x + directions[i].first;
		dy = y + directions[i].second;
		
		if (!(0 <= dx && dx < M && 0 <= dy && dy < N)) {
			continue;
		}

		if (grid[dy][dx] != '.' || visited.count(dy * M + dx)) {
			continue;
		}

		dfs(dy, dx);
	}
}

int main() {
	cin >> N >> M;
	grid.assign(N, vector<char>(M, '\0'));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> grid[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (grid[i][j] != '.') {
				continue;
			}

			if (visited.count(i * M + j)) {
				continue;
			}

			dfs(i, j);
			cnt++;
		}
	}

	cout << cnt << "\n";
	return 0;
}
