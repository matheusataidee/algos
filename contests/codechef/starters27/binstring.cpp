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
		int n;
		cin >> n;
		string s;
		cin >> s;
		
		int ans = 1;
		for (int i = 1; i < len(s); i++) {
			if (s[i] != s[i-1]) ans++;
		}
		cout << ans << endl;
		
	}
	return 0;
}
