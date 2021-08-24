#include <bits/stdc++.h>

using namespace std;

#define left(i) ((2 * i) + 1)
#define right(i) ((2 * i) + 2)

typedef long long ll;

const ll INF = 1e18L + 5;

class SegTree {
	int n;
	vector<ll> tree;
	vector<ll> lazy;
	
	void prop(int root, int l, int r) {
		tree[root] += lazy[root];
		if (l != r) {
			lazy[left(root)] += lazy[root];
			lazy[right(root)] += lazy[root];
		}
		lazy[root] = 0;
	}
	
	void _add(int root, int l, int r, int a, int b, ll val) {
		prop(root, l, r);
		if (a > r || b < l) return;
		if (l == a && b == r) {
			lazy[root] += val;
			prop(root, l, r);
		} else {
			int mid = (l + r) / 2;
			_add(left(root), l, mid, a, min(mid, b), val);
			_add(right(root), mid+1, r, max(mid+1, a), b, val);
			tree[root] = max(tree[left(root)], tree[right(root)]);
		}
	}
	
	ll _get(int root, int l, int r, int a, int b) {
		prop(root, l, r);
		if (a > r || b < l) return -INF;
		if (a == l && r == b) {
			return tree[root];
		}
		int mid = (l + r) / 2;
		return max(_get(left(root), l, mid, a, min(mid, b)),
				   _get(right(root), mid + 1, r, max(mid+1, a), b));
	}
	
public:
	SegTree(int n) : n(n) {
		tree.assign(4 * n, -INF);
		lazy.assign(4 * n, 0);
	}
	
	void add(int a, int b, ll val) {
		_add(0, 0, n - 1, a, b, val);
	}
	
	ll get(int a, int b) {
		return _get(0, 0, n - 1, a, b);
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	SegTree tree(n+2);
	vector<vector<pair<ll, ll>>> intervals(n+1);
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		intervals[b].push_back({a, c});
	}
	tree.add(0, 1, INF);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (pair<ll, ll>& p : intervals[i]) {
			tree.add(p.first, i, p.second);
		}
		ans = tree.get(0, n);
		tree.add(i+1, i+1, ans + INF);
	}
	cout << ans << endl;
	
	return 0;
}
