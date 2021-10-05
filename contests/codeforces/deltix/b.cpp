#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> v;
vector<int> counter;
vector<vector<int>> posi;

int solve(int f) {
	vector<int> diff(2);
	int p = 0, q = 0;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (posi[f][p] > i) ret += posi[f][p] - i;
			p++;
		} else {
			if (posi[1-f][q] > i) ret += posi[1-f][q] - i;
			q++;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		v = vector<int>(n);
		counter = vector<int>(2);
		posi = vector<vector<int>>(2);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			v[i] %= 2;
			counter[v[i]]++;
			posi[v[i]].push_back(i);
		}
		if (abs(counter[0] - counter[1]) > 1) {
			cout << "-1" << endl;
			continue;
		}
		if (counter[0] == counter[1]) {
			cout << min(solve(0), solve(1)) << endl;
		} else if (counter[0] > counter[1]) {
			cout << solve(0) << endl;
		} else {
			cout << solve(1) << endl;
		}
	}
	return 0;
}
