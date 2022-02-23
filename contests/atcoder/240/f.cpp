#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<ll> x(n), y(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
		ll acc = 0, cur = 0;
		ll ans = x[0];
		
		for (int i = 0; i < n; i++) {
			if (cur > 0 && (cur + x[i] * y[i]) < 0) {
				ll qnt = cur / abs(x[i]);
				ll tmp = acc + qnt * cur;
				tmp += x[i] * ((qnt * (qnt+1)) / 2);
				ans = max(ans, tmp);
			}
			acc += y[i] * cur;
			acc += x[i] * ((y[i] * (y[i]+1)) / 2);
			cur += x[i] * y[i];
			
			ans = max(ans, acc);
		}
		cout << ans << endl;
	}
	
	return 0;
}
