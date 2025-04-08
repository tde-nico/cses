#include <bits/stdc++.h>

using namespace std;

#define DIRECTIONS "UDLR"

int N, M;
char grid[1001][1001];
int previous[1001][1001];
bool visited[1001][1001];
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool bfs(int y, int x) {
	int dy, dx;
	queue<pair<int, int>> q;
	pair<int, int> curr;
	q.push({y, x});
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		y = curr.first;
		x = curr.second;
		if (visited[y][x]) {
			continue;
		}
		visited[y][x] = true;
		if (grid[y][x] == 'B') {
			return true;
		}

		for (int i = 0; i < 4; ++i) {
				dy = y + directions[i].first;
				dx = x + directions[i].second;
				if (dx < 0 || dx >= M || dy < 0 || dy >= N) {
				continue;
			}
			
			if (visited[dy][dx] || grid[dy][dx] == '#') {
				continue;
			}

			previous[dy][dx] = i;
			q.push({dy, dx});
		}
	}
	return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> grid[i];
	}

	pair<int, int> begin = {0, 0}, end = {0, 0};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (grid[i][j] == 'A') {
				begin.first = i;
				begin.second = j;
			} else if (grid[i][j] == 'B') {
				end.first = i;
				end.second = j;
			}
		}
	}

	if (bfs(begin.first, begin.second)) {
		cout << "YES\n";
		string solve = "";
		while (end != begin) {
			int p = previous[end.first][end.second];
			solve.push_back(DIRECTIONS[p]);
			end = {end.first - directions[p].first, end.second - directions[p].second};
		}
		reverse(solve.begin(), solve.end());
		cout << solve.size() << "\n";
		cout << solve << "\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
