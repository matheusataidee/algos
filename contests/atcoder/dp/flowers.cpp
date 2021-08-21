#include <bits/stdc++.h>

using namespace std;

#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)

typedef long long ll;

class SegTree{
	int n;
	vector<ll> tree;
	
	void _update(int root, int l, int r, int p, ll val) {
		if (l == r) {
			tree[root] = val;
		} else {
			int mid = (l + r) / 2;
			if (p <= mid) {
				_update(left(root), l, mid, p, val);
			} else {
				_update(right(root), mid + 1, r, p, val);
			}
			tree[root] = max(tree[left(root)], tree[right(root)]);
		}
	}
	
	ll _get(int root, int l, int r, int a, int b) {
		if (l == a && r == b) return tree[root];
		if ( a > r || b < l) return 0;
		int mid = (l + r) / 2;
		return max(_get(left(root), l, mid, a, min(mid, b)),
				   _get(right(root), mid+1, r, max(mid+1, a), b));
	}
public:
	SegTree(int n_) : n(n_ + 1) {
		tree = vector<ll>(4 * n);
	}
	
	void update(int p, ll val) {
		_update(0, 0, n - 1, p, val);
	}
	
	ll get(int a, int b) {
		return _get(0, 0, n - 1, a, b);
	}
};

struct Flower {
	ll h, beauty;
};

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<Flower> v(n);
	SegTree tree(n);
	for (Flower& flower : v) cin >> flower.h;
	for (Flower& flower : v) cin >> flower.beauty;
	map<int, int> position;
	for (int i = 0; i < n; i++) {
		tree.update(v[i].h, v[i].beauty + tree.get(0, v[i].h - 1));
	}
	cout << tree.get(1, n) << endl;
	return 0;
}
