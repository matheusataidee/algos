#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll num;
	cin >> num;
	ll pot = 0;
	ll x = 1;
	while (2 * x <= num) {
		pot++;
		x *= 2;
	}
	cout << pot << endl;
	return 0;
}
