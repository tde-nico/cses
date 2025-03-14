#include <bits/stdc++.h>

using namespace std;

#define IS_VALID(y, x) (1 <= y && y <= 7 && 1 <= x && x <= 7)

string grid;
int cnt = 0;
bool visited[8][8];

void dfs(int y, int x, int i) {
	if (i == 48 || (y == 7 && x == 1)) {
		cnt += (i == 48 && (y == 7 && x == 1));
		return;
	}

	if ((
		(!IS_VALID(y+1, x) || visited[y+1][x]) &&
		(!IS_VALID(y-1, x) || visited[y-1][x]) &&
		(IS_VALID(y, x+1) && !visited[y][x+1]) &&
		(IS_VALID(y, x-1) && !visited[y][x-1])
	) || (
		(!IS_VALID(y, x+1) || visited[y][x+1]) &&
		(!IS_VALID(y, x-1) || visited[y][x-1]) &&
		(IS_VALID(y+1, x) && !visited[y+1][x]) &&
		(IS_VALID(y-1, x) && !visited[y-1][x])
	))
		return;
	
	visited[y][x] = true;
	if ((grid[i] == 'D' || grid[i] == '?') && (IS_VALID(y+1, x) && !visited[y+1][x]))
		dfs(y+1, x, i+1);
	if ((grid[i] == 'U' || grid[i] == '?') && (IS_VALID(y-1, x) && !visited[y-1][x]))
		dfs(y-1, x, i+1);
	if ((grid[i] == 'R' || grid[i] == '?') && (IS_VALID(y, x+1) && !visited[y][x+1]))
		dfs(y, x+1, i+1);
	if ((grid[i] == 'L' || grid[i] == '?') && (IS_VALID(y, x-1) && !visited[y][x-1]))
		dfs(y, x-1, i+1);
	visited[y][x] = false;
}

int main() {
	cin >> grid;
	dfs(1, 1, 0);
	cout << cnt << "\n";
	return 0;
}
