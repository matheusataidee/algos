#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		set<char> has;
		bool ok = true;
		for (char c : s) {
			if (c >= 'A' && c <= 'Z') {
				if (!has.count(c - ('A' - 'a'))) {
					ok = false;
				}
			} else {
				has.insert(c);
			}
		}
		if (ok) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
