#include <bits/stdc++.h>

using namespace std;

#define MAX 1002

int N, M;
queue<pair<int, int>> q;
int paths[MAX][MAX];
pair<int, int> from[MAX][MAX];
pair<int, int> A;
bool possible;
string solve;

void gen_solve(pair<int, int> curr) {
	pair<int, int> previous = from[curr.first][curr.second];
	if (previous == pair<int, int>(0,0))
		return;
	if (previous.first == curr.first+1)
		solve.push_back('U');
	else if (previous.first == curr.first-1)
		solve.push_back('D');
	else if (previous.second == curr.second+1)
		solve.push_back('L');
	else if (previous.second == curr.second-1)
		solve.push_back('R');
	gen_solve(previous);
}

void check(pair<int, int> curr, pair<int, int> next) {
	int curr_path = paths[curr.first][curr.second];
	if (curr_path+1 >= paths[next.first][next.second]) {
		return;
	}

	paths[next.first][next.second] = curr_path + 1;
	q.push(next);
	from[next.first][next.second] = curr;
}

void bfs(bool walk) {
	pair<int, int> curr;
	while (q.size()) {
		curr = q.front(); q.pop();
		check(curr, {curr.first+1, curr.second});
		check(curr, {curr.first-1, curr.second});
		check(curr, {curr.first, curr.second+1});
		check(curr, {curr.first, curr.second-1});
		if (!walk) {
			continue;
		}

		if (curr.first == 1 || curr.second == 1 || curr.first == N || curr.second == M) {
			cout << "YES\n";
			cout << paths[curr.first][curr.second] << "\n";
			gen_solve(curr);
			possible = true;
			return;
		}
	}
}

int main() {
	string s;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> s;
		for (int j = 1; j <= M; ++j) {
			paths[i][j] = INT_MAX;
			if (s[j-1] == '#') {
				paths[i][j] = 0;
			} else if (s[j-1] == 'M') {
				paths[i][j] = 0;
				q.push({i, j});
			} else if (s[j-1] == 'A') {
				A = {i, j};
			}
		}
	}

	possible = false;
	bfs(false);
	from[A.first][A.second] = {0, 0};
	paths[A.first][A.second] = 0;
	q.push(A);
	bfs(true);
	if (!possible) {
		cout << "NO\n";
		return 0;
	}

	reverse(solve.begin(), solve.end());
	cout << solve << "\n";
	return 0;
}
