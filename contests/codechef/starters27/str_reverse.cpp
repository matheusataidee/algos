#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s, r;
		cin >> s;
		
		r = s;
		reverse(all(r));
		int ok = 0;
		for (int i = 0; i < len(s); i++) {
			if (s[i] == r[ok]) {
				ok++;
			}
		}
		cout << len(s) - ok << endl;
	}
	
	return 0;
}
