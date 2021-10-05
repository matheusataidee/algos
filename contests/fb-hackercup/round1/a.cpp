#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		int n;
		string s;
		cin >> n >> s;
		int hand = 0;
		int ans = 0;
		for (char c : s) {
			if (c == 'F') continue;
			if (c == 'O') {
				if (hand == 2) ans++;	
				hand = 1;
			} else if (c == 'X') {
				if (hand == 1) ans++;
				hand = 2;
			}
		}
		cout << "Case #" << z << ": " << ans << endl;
	}
	return 0;
}
