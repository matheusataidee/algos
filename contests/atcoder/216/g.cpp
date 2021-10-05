#include <bits/stdc++.h>

#define left(i) ((2 * i) + 1)
#define right(i) ((2 * i) + 2)

using namespace std;

typedef long long ll;

class SegTree {
	int n;
	vector<int> tree;

	void _add(int root, int l, int r, int p, int val) {
		if (l == r) {
			tree[root] += val;
		} else {
			int mid = (l + r) / 2;
			if (p <= mid) {
				_add(left(root), l, mid, p, val);
			} else {
				_add(right(root), mid+1, r, p, val);
			}
			tree[root] = tree[left(root)] + tree[right(root)];
		}
	}
	
	int _get(int root, int l, int r, int a, int b) {
		if (a > r || b < l) return 0;
		if (l == a && r == b) return tree[root];
		int mid = (l + r) / 2;
		return _get(left(root), l, mid, a, min(b, mid)) +
			   _get(right(root), mid + 1, r, max(a, mid + 1), b);
	}

public:
	SegTree(int n) : n(n) {
		tree = vector<int>(4 * n);
	}
	
	void add(int p, int val) {
		_add(0, 0, n - 1, p, val);
	}
	
	int get(int a, int b) {
		return _get(0, 0, n - 1, a, b);
	}
};

struct Interval {
	int l, r, x;
	bool operator<(Interval& other) {
		return r < other.r;
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	SegTree seg(n);
	vector<Interval> v(m);
	for (Interval& interval : v) {
		cin >> interval.l >> interval.r >> interval.x;
		interval.l--;	interval.r--;
	}
	
	sort(begin(v), end(v));
	set<int, greater<int>> avail;
	for (int i = 0; i < n; i++) {
		avail.insert(i);
	}
	
	for (Interval& interval : v) {
		int now = seg.get(interval.l, interval.r);
		if (now < interval.x) {
			int diff = interval.x - now;
			while (diff--) {
				auto it = avail.lower_bound(interval.r);
				int p = *it;
				seg.add(p, 1);
				avail.erase(p);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << seg.get(i, i);
	}
	cout << endl;
	return 0;
}
