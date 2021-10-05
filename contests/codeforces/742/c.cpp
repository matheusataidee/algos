#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string num;
		cin >> num;
		
		int n = num.size();
		ll a, b;
		a = b = 0;
		
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				a *= 10;
				a += num[i] - '0';
			} else {
				b *= 10;
				b += num[i] - '0';
			}
		}
		cout << (a + 1) * (b + 1) - 2 << endl;
	}
	return 0;
}
