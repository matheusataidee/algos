#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector<int> acc(n+1, 0);
		for (int i = 0; i < (int)s.size(); i++) {
			int c = (i % 2 == 0) ? 1 : -1;
			acc[i+1] = acc[i];
			if (s[i] == '+') acc[i+1] += c;
			else acc[i+1] -= c;
		}
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			if (acc[r] - acc[l-1] == 0) {
				cout << "0" << endl;
			} else if ((r - l + 1) % 2 == 0) {
				cout << "2" << endl;
			} else {
				cout << "1" << endl;
			}
		}
	}
	return 0;
}
