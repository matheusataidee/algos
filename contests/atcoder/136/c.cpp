#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> v(n);
	for (ll& x : v) cin >> x;
	ll maxi = INT_MIN, acc = 0;
	for (int i = 0; i < n; i++) {
		maxi = max(maxi, v[i]);
		acc += abs(v[(i+1) % n] - v[i]);
	}
	cout << max(maxi, acc / 2) << endl;
	return 0;
}
