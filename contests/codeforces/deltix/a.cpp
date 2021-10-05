#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll c, d;
		cin >> c >> d;
		if ((c + d) % 2 == 1) {
			cout << "-1" << endl;
		} else if (c == d) {
			if (c == 0) {
				cout << "0" << endl;
			} else {
				cout << "1" << endl;
			}
		} else {
			cout << "2" << endl;
		}
	}
	return 0;
}
