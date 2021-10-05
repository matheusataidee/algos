#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll binsearch(ll target, vector<ll>& v) {
	int n = v.size();
	ll left = 0, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (v[mid] >= target) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<ll> vertical(n), horizontal(m);
		for (ll& line : vertical) cin >> line;
		for (ll& line : horizontal) cin >> line;
		
		vector<ll> ysorted;
		vector<ll> xsorted;
		vector<pair<ll, ll>> points;
		map<ll, vector<ll>> ys, xs;
		for (int i = 0; i < k; i++) {
			int y, x;
			cin >> y >> x;
			ysorted.push_back(y);
			xsorted.push_back(x);
			
			if (!ys.count(y)) ys[y] = vector<ll>();
			if (!xs.count(x)) xs[x] = vector<ll>();
			ys[y].push_back(x);
			xs[x].push_back(y);
			
			points.push_back({y, x});
		}
		sort(begin(ysorted), end(ysorted));
		sort(begin(xsorted), end(xsorted));
		for (auto& v : ys) sort(begin(v.second), end(v.second));
		for (auto& v : xs) sort(begin(v.second), end(v.second));
		
		ll ans = 0;
		for (pair<ll, ll> point : points) {
			int y = point.first;
			int x = point.second;
			ll adder = 0;
			
			if (vertical[binsearch(y, vertical)] == y) {
				int up = binsearch(x, horizontal);
				if (up && horizontal[up] != x) {
					int down = up-1;
					
					adder += binsearch(horizontal[up], xsorted) - binsearch(horizontal[down] + 1, xsorted);
					adder -= binsearch(horizontal[up], ys[y]) - binsearch(horizontal[down] + 1, ys[y]);
				}
			} else {
				int up = binsearch(y, vertical);
				if (up && vertical[up] != y) {
					int down = up - 1;
					
					adder += binsearch(vertical[up], ysorted) - binsearch(vertical[down] + 1, ysorted);
					adder -= binsearch(vertical[up], xs[x]) - binsearch(vertical[down] + 1, xs[x]);
				}
			}
			ans += adder;
		}
		cout << ans / 2 << endl;
	}
	
	return 0;
}
