#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
	ll x, y;
	bool operator<(Point& other) {
		return x < other.x;
	}
};

bool possible(ll k, vector<Point>& v) {
	int n = v.size();
	vector<ll> mini(n), maxi(n);
	mini[n-1] = maxi[n-1] = v[n-1].y;
	for (int i = n - 2; i >= 0; i--) {
		mini[i] = min(mini[i+1], v[i].y);
		maxi[i] = max(maxi[i+1], v[i].y);
	}
	
	int p = 0;
	for (int i = 0; p < n && i < n; i++) {
		while (p < n && abs(v[i].x - v[p].x) < k) p++;
		if (p == n) break;
		if (abs(v[i].y - mini[p]) >= k || abs(v[i].y - maxi[p]) >= k) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<Point> v(n);
	for (Point& p : v) cin >> p.x >> p.y;
	sort(begin(v), end(v));
	ll b = 1, e = 1e9 + 1;
	while (b < e) {
		ll mid = (b + e) / 2;
		if (!possible(mid, v)) {
			e = mid;
		} else {
			b = mid + 1;
		}
	}
	cout << b - 1 << endl;
	
	return 0;
}
