#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n+1);
	map<pair<int, int>, int> andd;
	map<pair<int, int>, int> orr;
	ll sum = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = i + 1; j <= 3; j++) {
			cout << "and " << i << " " << j << endl;
			ll x;
			cin >> x;
			sum += x;
			andd[{i, j}] = x;
			
			cout << "or " << i << " " << j << endl;
			cin >> x;
			sum += x;
			orr[{i, j}] = x;
		}
	}
	sum /= 2;
	v[1] = {sum - (orr[{2, 3}] + andd[{2, 3}]), 1};
	v[2] = {sum - (orr[{1, 3}] + andd[{1, 3}]), 2};
	v[3] = {sum - (orr[{1, 2}] + andd[{1, 2}]), 3};
	
	
	for (int i = 4; i <= n; i++) {
		ll a, b;
		cout << "and " << i-1 << " " << i << endl;
		cin >> a;
		cout << "or " << i-1 << " " << i << endl;
		cin >> b;
		v[i] = {(b - v[i-1].first) + a, i};
	}
	sort(begin(v+1), end(v));
	cout << "finish " << v[k].first << endl;
	
	return 0;
}
