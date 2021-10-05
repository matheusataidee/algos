#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int offset;
vector<int> acc;
vector<vector<int>> posi;

int solve(int l, int r) {
	int diff = acc[r] - acc[l-1];
	int target;
	if (diff > 0) {
		target = acc[l-1] + (diff + 1) / 2;
	} else {
		target = acc[l-1] + (diff - 1) / 2;
	}
	int lo = 0, hi = posi[offset + target].size();
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (posi[offset + target][mid] >= l) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return posi[offset + target][lo];
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		acc = vector<int>(n+1, 0);
		offset = n + 1;
		posi = vector<vector<int>>(2 * offset, vector<int>());
		for (int i = 0; i < (int)s.size(); i++) {
			int c = (i % 2 == 0) ? 1 : -1;
			acc[i+1] = acc[i];
			if (s[i] == '+') acc[i+1] += c;
			else acc[i+1] -= c;
			
			posi[offset + acc[i+1]].push_back(i+1);
		}
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			if (acc[r] - acc[l-1] == 0) {
				cout << "0" << endl;
			} else if ((r - l + 1) % 2 == 0) {
				cout << "2" << endl;
				cout << l << " " << solve(l+1, r) << endl;
			} else {
				cout << "1" << endl;
				cout << solve(l, r) << endl;
			}
		}
	}
	return 0;
}
