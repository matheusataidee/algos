#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
int check(int l, int r) {
	l--; r--;
	int ret = 0;
	for (int i = l; i <= r; i++) {
		ret *= 2;
		if (s[i] == '1') ret++;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cin >> s;
		bool cond = false;
		int a, b, c, d;
		for (int i = n/2; !cond && i < n; i++) {
			if (s[i] == '0') {
				a = 1;
				b = i+1;
				c = 1;
				d = i;
				cond = true;
			}
		}
		if (!cond) {
			if (s[n / 2 - 1] == '0') {
				a = n / 2;
				b = n;
				c = n / 2 + 1;
				d = n;
			} else {
				a = n / 2;
				b = n - 1;
				c = n / 2 + 1;
				d = n;
			}
		}
		cout << a << " " << b << " " << c << " " <<  d << endl;
		//cout << check(a, b) << " " << check(c, d) << endl;
	}
	return 0;
}
