#include <bits/stdc++.h>

using namespace std;

unordered_set<int> reserved;
int queen_count = 0;

bool isSafe(vector<vector<bool>> &board, int row, int col) {
	if (reserved.count(row * 8 + col))
		return false;
	
	for (int x = 0; x < col; ++x)
		if (board[row][x])
			return false;
	
	for (int y = row, x = col; y >= 0 && x >= 0; --y, --x)
		if (board[y][x])
			return false;
	
	for (int y = row, x = col; y < 8 && x >= 0; ++y, --x)
		if (board[y][x])
			return false;

	return true;
}

void solve(vector<vector<bool>> &board, int col) {
	if (col == 8) {
		queen_count++;
		return;
	}

	for (int row = 0; row < 8; ++row) {
		if (isSafe(board, row, col)) {
			board[row][col] = true;
			solve(board, col + 1);
			board[row][col] = false;
		}
	}
}

int main() {
	char curr;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> curr;
			if (curr == '*') {
				reserved.insert(i * 8 + j);
			}
		}
	}
	
	vector<vector<bool>> board(8, vector<bool>(8, false));
	solve(board, 0);
	cout << queen_count << "\n";
	return 0;
}
