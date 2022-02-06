#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)
#define ASCENDING 1

class SegTree {
public:
	SegTree(const vector<int>& v, int x) {
		n = v.size();
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
		pending.assign(4 * n, false);
		for (int i = 0; i < n; i++) {
			if (v[i] < x) {
				update(0, 0, n - 1, i, i, 0);
			} else {
				update(0, 0, n - 1, i, i, 1);
			}
			
			if (v[i] == x) {
				position = i;
			}
		}
	}
	
	void runQuery(int a, int b, int type) {
		int size = b - a + 1;
		int ones = get(0, 0, n - 1, a, b);
		int zeros = size - ones;
		if (zeros) {
			if (type == ASCENDING) {
				update(0, 0, n - 1, a, a + zeros - 1, 0);
			} else {
				update(0, 0, n - 1, b - zeros + 1, b, 0);
			}
		}
		if (ones) {
			if (type == ASCENDING) {
				update(0, 0, n - 1, b - ones + 1, b, 1);
			} else {
				update(0, 0, n - 1, a, a + ones - 1, 1);
			}
		}
		if (position >= a && position <= b) {
			if (type == ASCENDING) {
				position = a + zeros;
			} else {
				position = a + ones - 1;
			}
		}
	}
	
	int getPosition() {
		return position;
	}
private:
	vector<ll> tree;
	vector<ll> lazy;
	vector<bool> pending;
	int n, position;
	
	void prop(int root, int l, int r) {
		if (!pending[root]) return;
		tree[root] = lazy[root] * (r - l + 1);
		if (l != r) {
			lazy[left(root)] = lazy[right(root)] = lazy[root];
			pending[left(root)] = pending[right(root)] = true;
		}
		lazy[root] = 0;
		pending[root] = false;
	}
	
	void update(int root, int l, int r, int a, int b, int val) {
		prop(root, l, r);
		if (a > r || b < l) return;
		if (a == l && b == r) {
			lazy[root] = val;
			pending[root] = true;
			prop(root, l, r);
		} else {
			int mid = (l + r) / 2;
			update(left(root), l, mid, a, min(mid, b), val);
			update(right(root), mid + 1, r, max(mid+1, a), b, val);
			tree[root] = tree[left(root)] + tree[right(root)];
		}
	}
	
	ll get(int root, int l, int r, int a, int b) {
		prop(root, l, r);
		if (a > r || b < l) return 0;
		if (l == a && r == b) {
			return tree[root];
		} else {
			int mid = (l + r) / 2;
			return get(left(root), l, mid, a, min(b, mid)) +
				   get(right(root), mid + 1, r, max(a, mid+1), b);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n, q, x;
	cin >> n >> q >> x;
	
	vector<int> v(n);
	for (int& val : v) cin >> val;
	
	SegTree seg(v, x);
	
	for (int i = 0; i < q; i++) {
		int type, a, b;
		cin >> type >> a >> b;
		seg.runQuery(a-1, b-1, type);
		
	}
	cout << seg.getPosition() + 1 << endl;
	
	
	
	return 0;
}
