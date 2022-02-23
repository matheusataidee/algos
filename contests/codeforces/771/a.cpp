#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void reverse(int l, int r, vector<int>& v) {
	while (l < r) {
		swap(v[l], v[r]);
		l++;
		r--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int& val : v) cin >> val;
		int target = 1;
		int l = 0;
		while (l < n && v[l] == target) {
			l++;
			target++;
		}
		if (l < n) {
			for (int i = l; i < n; i++) {
				if (v[i] == target) {
					reverse(l, i, v);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
