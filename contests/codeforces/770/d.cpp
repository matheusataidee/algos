#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get(int a, int b, int c) {
	cout << "? " << a << " " << b << " " << c << endl;
	int ret;
	cin >> ret;
	return ret;
}

vector<int> solve(int a, int b, int c, int d) {
	vector<pair<int, int>> complement;
	complement.push_back({get(b, c, d), a});
	complement.push_back({get(a, c, d), b});
	complement.push_back({get(a, b, d), c});
	complement.push_back({get(a, b, c), d});
	sort(begin(complement), end(complement));
	return vector<int>{complement[0].second, complement[1].second};
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> candidates{1, 2};
		for (int i = 3; i <= n - 1; i+=2) {
			candidates = solve(candidates[0], candidates[1], i, i + 1);
		}
		if (n % 2 == 1) {
			int other = 1;
			while (other == candidates[0] || other == candidates[1]) {
				other++;
			}
			candidates = solve(candidates[0], candidates[1], other, n);
		}
		cout << "! " << candidates[0] << " " << candidates[1] << endl;
	}
	return 0;
}
