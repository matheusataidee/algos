#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n), acc(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			acc[i] ^= v[i];
			if (i) acc[i] ^= acc[i-1];
		}
		
		bool cond = false;
		if (acc[n-1] == 0) {
			cond = true;
		} else {
			bool f = false;
			for (int i = 0; !cond && i < n - 1; i++) {
				if (acc[i] == acc[n-1]) f = true;
				if (f && acc[i] == 0) cond = true;
			}
		}
		cout << vector<string>{"NO", "YES"}[cond] << endl;
	}
	return 0;
}
