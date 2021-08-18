#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Interval {
	ll l, r;
};

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<ll, ll> > l(n);
		vector<Interval> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].l >> v[i].r;
			l[i].first = v[i].l;
			l[i].second = i;
		}
		sort(begin(l), end(l));
		int p = 0, i;
		int solved = 0;
		bool ok = true;
		priority_queue<ll, vector<ll>, greater<ll> > heap;
		while (ok && solved < n) {
			if (heap.empty()) {
				i = l[p].first;
			}
			while (i == l[p].first) {
				heap.push(v[l[p].second].r);
				p++;
			}
			if (i > heap.top()) {
				ok = false;
			} else {
				heap.pop();
				solved++;
				i++;
			}
		}
		if (ok) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	
	return 0;
}
