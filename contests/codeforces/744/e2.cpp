#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)

class SegTree {
	
	int n;
	vector<ll> tree;

	void _update(int root, int l, int r, int p) {
		if (p > r || p < l || l > r) return;
		if (l == r) {
			tree[root]++;
		} else {
			int mid = (l + r) / 2;
			_update(left(root), l, mid, p);
			_update(right(root), mid + 1, r, p);
			tree[root] = tree[left(root)] + tree[right(root)];
		}
	}

	ll _getSum(int root, int l, int r, int a, int b) {
		if (a > r || b < l) return 0;
		if (l == a && r == b) {
			return tree[root];
		} else {
			int mid = (l + r) / 2;
			return _getSum(left(root), l, mid, a, min(mid, b)) + _getSum(right(root), mid + 1, r, max(mid+1, a), b);
		}
	}
public:
	SegTree(int _n) {
		n = _n;
		tree.assign(4 * n, 0);
	}
	
	void update(int p) {
		_update(0, 0, n-1, p);
	}
	
	ll get(int l, int r) {
		if (r < l) return 0;
		return _getSum(0, 0, n - 1, l, r);
	}
};

void convert(vector<int>& v) {
	map<int, int> freq;
	map<int, int> conv;
	
	for (int val : v) freq[val]++;
	
	int k = 0;
	for (auto it : freq) {
		conv[it.first] = k++;
	}
	
	for (int& val : v) {
		val = conv[val];
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		vector<int> v(n);
		for (int& val : v) cin >> val;
		
		convert(v);
		
		SegTree seg(n);
		
		
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += min(seg.get(0, v[i]-1), seg.get(v[i]+1, n - 1));
			
			seg.update(v[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
