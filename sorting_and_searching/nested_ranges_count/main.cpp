#include <bits/stdc++.h>

using namespace std;

typedef struct s_FenwickTree {
	vector<int> ft;

	s_FenwickTree(int n) { ft.assign(n+1, 0); }

	void add(int p, int v) {
		for (++p; p < ft.size(); p += p&-p)
			ft[p] += v;
	}

	int sum(int b) {
		int res = 0;
		for (++b; b > 0; b -= b&-b)
			res += ft[b];
		return res;
	}

} FenwickTree;

typedef struct s_range {
	int start;
	int end;
	int idx;
} range;

int main() {
	int N;
	cin >> N;

	vector<range> ranges(N);
	set<int> ends;
	for (int i = 0; i < N; ++i) {
		cin >> ranges[i].start >> ranges[i].end;
		ranges[i].idx = i;
		ends.insert(ranges[i].end);
	}

	sort(ranges.begin(), ranges.end(), [](range a, range b){
		return (a.start == b.start ? a.end > b.end : a.start < b.start);
	});

	int idx = 0;
	map<int, int> sorted_ends;
	for (auto end : ends)
		sorted_ends[end] = ++idx;

	vector<int> contains(N, 0), contained(N, 0);
	int end_idx;
	
	FenwickTree ft(N);
	for (int i = N-1; i >= 0; --i) {
		end_idx = sorted_ends[ranges[i].end];
		idx = ranges[i].idx;
		contains[idx] = ft.sum(end_idx);
		ft.add(end_idx, 1);
	}
	cout << "\n";

	FenwickTree ft2(N);
	for (int i = 0; i < N; ++i) {
		end_idx = sorted_ends[ranges[i].end];
		idx = ranges[i].idx;
		contained[idx] = i - ft2.sum(end_idx - 1);
		ft2.add(end_idx, 1);
	}
	cout << "\n";

	for (int i = 0; i < N; ++i)
		cout << contains[i] << " ";
	cout << "\n";
	for (int i = 0; i < N; ++i)
		cout << contained[i] << " ";
	cout << "\n";

	return 0;
}
