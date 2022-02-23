#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void markHas(char c, string& s, vector<bool>& has) {
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == c) {
			for (int j = i; j < (int)s.size(); j++) {
				has[j] = true;
			}
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		string s;
		cin >> s;
		vector<bool> hasD(s.size(), false);
		vector<bool> hasR(s.size(), false);
		markHas('D', s, hasD);
		markHas('R', s, hasR);
		
		if (!hasD.back() || !hasR.back()) {
			cout << n << endl;
			continue;
		}
		ll y = 0, x = 0;
		for (char c : s) {
			if (c == 'D') {
				y++;
			} else {
				x++;
			}
		}
		ll ans = (n - y) * (n - x);
		ll max_y = n - y - 1;
		ll max_x = n - x - 1;
		s = "0" + s;
		for (int i = (int)s.size() - 2; i >= 0; i--) {
			if (s[i+1] == 'D') {
				if (hasR[i]) {
					ans += 1 + min(max_x, (n - x - 1));
				} else {
					ans += y;
					break;
				}
				y--;
			} else {
				if (hasD[i]) {
					ans += 1 + min(max_y, (n - y - 1));
				} else {
					ans += x;
					break;
				}
				x--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
