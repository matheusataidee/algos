#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

ll toNum(vector<ll>& v) {
	ll ret = 0;
	int n = v.size();
	for (int i = 0; i < n; i++) {
		ret *= 10;
		ret += v[i];
	}
	return ret;
}

ll solve(vector<ll>& v, int k) {
	set<ll> digits;
	ll maxi = -1;
	int n = v.size();
	for (int i = 0; i < n; i++) {
		if ((int)digits.size() == k && !digits.count(v[i])) {
			if (v[i] < maxi) {
				while (!digits.count(v[i])) v[i]++;
				auto it = digits.begin();
				int mini = *it;
				for (int j = i + 1; j < n; j++) v[j] = mini;
				return toNum(v);
			} else {
				v[i-1]++;
				for (int j = i; j < n; j++) v[j] = 0;
				return solve(v, k);
			}
		} else {
			maxi = max(maxi, v[i]);
			digits.insert(v[i]);
		}
	}
	return toNum(v);
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll num, k;
		cin >> num >> k;
		vector<ll> v = getArray(num);
		cout << solve(v, k) << endl;
	}
	
	return 0;
}
