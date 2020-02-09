// Solution to https://www.spoj.com/problems/LCASQ/

#include <bits/stdc++.h>

using namespace std;

#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)

class LCA {
	private:
		vector<int> euler, height, first, segtree;
		int n;
		
		void dfs(int p, int h, vector<vector<int> >& g) {
			height[p] = h;
			first[p] = euler.size();
			euler.push_back(p);
			for (int to : g[p]) {
				dfs(to, h + 1, g);
				euler.push_back(p);
			}
		}
		
		void add(int root, int l, int r, int p, int who) {
			if (l == r) {
				segtree[root] = who;
			} else {
				int mid = (l + r) / 2;
				if (p <= mid) {
					add(left(root), l, mid, p, who);
				} else {
					add(right(root), mid + 1, r, p, who);
				}
				if (height[segtree[left(root)]] < height[segtree[right(root)]]) {
					segtree[root] = segtree[left(root)];
				} else {
					segtree[root] = segtree[right(root)];
				}
			}	
		}
		
		int query(int root, int l, int r, int a, int b) {
			if (l == a && r == b) return segtree[root];
			if (a > r || b < l) return -1;
			int mid = (l + r) / 2;
			int rl = query(left(root), l, mid, a, min(b, mid));
			int rr = query(right(root), mid + 1, r, max(a, mid+1), b);
			if (rl == -1) return rr;
			if (rr == -1) return rl;
			return (height[rl] < height[rr]) ? rl : rr;
		}
		
	public:
		LCA(vector<vector<int> >& g, int root) {
			int n = g.size();
			height.resize(n);
			first.resize(n);
			euler.clear();
			dfs(root, 0, g);
			int m = euler.size();
			segtree.resize(4 * m);
			for (int i = 0; i < m; i++) {
				add(0, 0, m - 1, i, euler[i]);
			}
		}
		
		int get(int a, int b) {
			int mini = min(first[a], first[b]);
			int maxi = max(first[a], first[b]);
			return query(0, 0, (int)euler.size() - 1, mini, maxi);
		}
};

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int> > g(n);
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		g[i].resize(m);
		for (int &to : g[i]) cin >> to;
	}
	
	LCA lca(g, 0);
	
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca.get(a, b) << endl;
	}
	return 0;
}
