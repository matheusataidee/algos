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
		for (char& c : s) {
			if (c == 'U') {
				c = 'D';
			} else if (c == 'D') {
				c = 'U';
			}
		}
		cout << s << endl;
	}
	
	return 0;
}
