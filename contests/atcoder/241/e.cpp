#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

struct History {
	ll t;
	ll acc;
	
	History(ll t_, ll acc_) : t(t_), acc(acc_) { }
};

const History unused(-1, -1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	vector<History> history(n, unused);
	for (ll& val : v) cin >> val;
	
	ll acc = 0;
	ll t = 0;
	while (t < k) {
		ll cur = acc % n;
		if (history[cur].acc != unused.acc) {
			ll diff = acc - history[cur].acc;
			ll cycle_sz = t - history[cur].t;
			
			ll rem = k - t;
			ll qnt = rem / cycle_sz;
			acc += diff * qnt;
			t += cycle_sz * qnt;
			
			history.assign(n, unused);
			
		} else {
			history[cur].t = t;
			history[cur].acc = acc;
			
			acc += v[cur];
			t++;
		}
	}
	cout << acc << endl;
	return 0;
}
