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
		vector<int> v(n);
		for (int& x : v) cin >> x;
		for (int i = 0; i + 2 < n; i+=3) {
			v[i] = v[i+2] = v[i+1] * 2;
		}
		if (n % 3 == 1) {
			v[n-1] = v[n-2];
		} else if (n % 3 == 2) {
			v[n-2] = v[n-1] * 2;
		}
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
