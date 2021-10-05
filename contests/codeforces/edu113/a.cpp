#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		bool cond = false;
		for (int i = 0; !cond && i < n - 1; i++) {
			if (s[i] != s[i+1]) {
				cout << i + 1 << " " << i + 2 << endl;
				cond = true;
			}
		}
		if (!cond) {
			cout << "-1 -1" << endl;
		}
	}
	return 0;
}
