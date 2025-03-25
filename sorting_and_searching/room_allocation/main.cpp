#include <bits/stdc++.h>

using namespace std;

typedef struct s_triple {
	int start;
	int end;
	int idx;
} triple;

int main() {
	int N;
	cin >> N;
	vector<triple> customers(N);
	for (int i = 0; i < N; ++i) {
		cin >> customers[i].start >> customers[i].end;
		customers[i].idx = i;
	}

	sort(customers.begin(), customers.end(), [](triple a, triple b){
		return a.start == b.start ? a.end < b.end : a.start < b.start;
	});
	set<pair<int, int>> room_traking;
	vector<int> rooms(N);
	int max_room = 0, room = 0;

	for (int i = 0; i < N; ++i) {
		triple curr = customers[i];
		auto it = room_traking.lower_bound({curr.start, 0});
		if (it != room_traking.begin()) {
			it = prev(it);
			room_traking.erase(it);
			room = it->second;
		} else {
			room = ++max_room;
		}
		rooms[curr.idx] = room;
		room_traking.insert({curr.end, room});
	}

	cout << room_traking.size() << "\n";
	for (int i = 0; i < N; ++i) {
		cout << rooms[i] << " ";
	}

	return 0;
}
