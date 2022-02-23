#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
	int y;
	int x;
	Point(int y_, int x_) : y(y_), x(x_) { }
};

const ll mod = 998244353;
const int maxq = 200200;

ll mypow(ll base, ll expo) {
	if (expo == 0) {
		return 1;
	}
	if (expo % 2 == 0) {
		ll root = mypow(base, expo / 2);
		return (root * root) % mod;
	}
	return (mypow(base, expo - 1) * base) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);
	unordered_set<int> col, row, diffs;
	map<int, int> vertical, horizontal;
	vector<Point> v(maxq, Point(0, 0));
	while (t--) {
		int n, m, k, q;
		scanf("%d %d %d %d", &n, &m, &k, &q);
		col.clear();
		row.clear();
		diffs.clear();
		vertical.clear();
		horizontal.clear();
		for (int i = 0; i < q; i++) {
			scanf("%d %d", &v[i].y, &v[i].x);
		}
		int first = q - 1;
		while (first > 0) {
			row.insert(v[first].y);
			col.insert(v[first].x);
			if ((int)row.size() == n || (int)col.size() == m) {
				break;
			}
			first--;
		}
		
		for (int i = first; i < q; i++) {
			vertical[v[i].y] = i;
			horizontal[v[i].x] = i;
		}
		
		for (auto it : vertical) {
			diffs.insert(it.second);
		}
		for (auto it : horizontal) {
			diffs.insert(it.second);
		}
		/*for (int i = 1; i <= n; i++) {
			if (vertical[i] != -1) {
				diffs.insert(vertical[i]);
			}
		}
		for (int i = 1; i <= m; i++) {
			if (horizontal[i] != -1) {
				diffs.insert(horizontal[i]);
			}
		}*/
		printf("%lld\n", mypow(k, diffs.size()));
	}
	return 0;
}
