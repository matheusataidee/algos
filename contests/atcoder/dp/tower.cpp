#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxw = 2.1 * 1e4;

struct Item {
	ll w, s, v;
	bool operator<(Item& other) {
		return w + s < other.w + other.s;
	}
};

vector<Item> v;
vector<ll> dp;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	v.resize(n);
	dp.assign(maxw, 0);
	for (Item& item : v) cin >> item.w >> item.s >> item.v;
	sort(begin(v), end(v));
	for (Item& item : v) {
		for (int j = maxw - 1; j >= 0; j--) {
			if (j - item.w < 0) break;
			dp[j] = max(dp[j], dp[min(j - item.w, item.s)] + item.v);
		}
	}
	cout << dp[maxw-1] << endl;
	return 0;
}
