#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
	vector<int> parent, rank, sz;
	int num_components;
	DSU(int N): parent(N,-1), rank(N,0), sz(N,1), num_components(N) {}
	int find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = find(parent[x]);
	}
	bool merge(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (rank[a] > rank[b]) swap(a, b);
		parent[a] = b;
		sz[b] += sz[a];
		if (rank[a] == rank[b]) rank[b]++;
		num_components--;
		return true;
	}
	bool same(int a, int b) {return find(a) == find(b);}
	int size(int x) {return sz[find(x)];}
};

int main() {
	int N, M, a, b;
	cin >> N >> M;
	DSU d(N);
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		d.merge(a-1, b-1);
	}

	vector<pair<int, int>> res;
	for (int i = 1; i < N; ++i) {
		if (d.merge(i-1, i)) {
			res.push_back({i, i+1});
		}
	}

	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].first << " " << res[i].second << "\n";
	}
	return 0;
}
