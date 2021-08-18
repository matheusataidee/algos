#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll> > pots;

vector<ll> getArray(ll num) {
	vector<ll> ret;
	while (num) {
		ret.push_back(num % 10);
		num /= 10;
	}
	int sz = ret.size();
	for (int i = 0; i < sz / 2; i++) {
		swap(ret[i], ret[sz-1-i]);
	}
	return ret;
}

void prepare() {
	ll pot = 1;
	pots.push_back(vector<ll>{pot});
	for (int i = 0; i < 62; i++) {
		pot *= 2;
		pots.push_back(getArray(pot));
	}
}

ll solve(vector<ll>& v, vector<ll>& target) {
	int ret = 0;
	int p = 0, i;
	int nt = (int)target.size(), nv = (int)v.size();
	for (i = 0; p < nt && i < nv; i++) {
		if (v[i] == target[p]) {
			p++;
		} else {
			ret++;
		}
	}
	ret += (nt - p) + (nv - i);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	prepare();
	int t;
	cin >> t;
	while (t--) {
		ll num;
		cin >> num;
		vector<ll> numArray = getArray(num);
		ll ans = 20;
		for (int i = 0; i < (int)pots.size(); i++) {
			ans = min(ans, solve(numArray, pots[i]));
		}
		cout << ans << endl;
	}
	return 0;
}
