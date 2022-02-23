#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool checkAscend(vector<int> v) {
	int sz = v.size();
	for (int i = 1; i < sz; i++) {
		if (v[i] < v[i-1]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> even, odd;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x % 2 == 0) {
				even.push_back(x);
			} else {
				odd.push_back(x);
			}
		}
		bool ok = true;
		ok &= checkAscend(even);
		ok &= checkAscend(odd);
		if (ok) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
