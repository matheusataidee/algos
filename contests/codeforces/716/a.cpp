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
		bool cond = true;
		for (int i = 0; i < n; i++) {
			int x;	cin >> x;
			int sq = sqrt(x);
			if (sq * sq != x) cond = false;
		}
		cout << vector<string>{"YES", "NO"}[cond] << endl;
	}
	return 0;
}
