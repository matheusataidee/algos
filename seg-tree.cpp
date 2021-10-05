#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)
#define MAXN 100100

typedef long long ll;

class SegTree {
private:
	int n;
	vector<ll> tree;
	
	void _update(int root, int l, int r, int p, int val) {
		if (p > r || p < l || l > r) return;
		if (l == r) {
			tree[root] = val;
		} else {
			int mid = (l + r) / 2;
			update(left(root), l, mid, p, val);
			update(right(root), mid + 1, r, p, val);
			tree[root] = max(tree[left(root)], tree[right(root)]);
		}
	}

	ll _get(int root, int l, int r, int a, int b) {
		if (a > r || b < l) return 0;
		if (l == a && r == b) {
			return tree[root];
		} else {
			int mid = (l + r) / 2;
			return max(_get(left(root), l, mid, a, min(mid, b)), _get(right(root), mid + 1, r, max(mid+1, a), b));
		}
	}
	
public:
	SegTree(int n) : n(n) {
		tree.assign(4 * n, 0);
	}
	
	void update(int p, int val) {
		_update(0, 0, n - 1, p, val);
	}
	
	int get(int a, int b) {
		return _get(0, 0, n - 1, a, b);
	}
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Lazy propagation */

#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)
#define MAXN 100100

typedef long long ll;

ll tree[4 * MAXN];
ll lazy[4 * MAXN];

void prop(int root, int l, int r) {
    tree[root] += lazy[root] * (r - l + 1);
    if (l != r) {
        lazy[left(root)] += lazy[root];
        lazy[right(root)] += lazy[root];
    }
    lazy[root] = 0;
}

void update(int root, int l, int r, int a, int b, ll val) {
    prop(root, l, r);
    if (a > r || b < l) return;
    if (l == a && r == b) {
        lazy[root] += val;
        prop(root, l, r);
    } else {
        int mid = (l + r) / 2;
        update(left(root), l, mid, a, min(mid, b), val);
        update(right(root), mid + 1, r, max(mid + 1, a), b, val);
        tree[root] = tree[left(root)] + tree[right(root)];
    }
}

ll getSum(int root, int l, int r, int a, int b) {
    prop(root, l, r);
    if (a > r || b < l) return 0;
    if (l == a && r == b) {
        return tree[root];
    } else {
        int mid = (l + r) / 2;
        return getSum(left(root), l, mid, a, min(mid, b)) + getSum(right(root), mid + 1, r, max(mid + 1, a), b);
    }
}
