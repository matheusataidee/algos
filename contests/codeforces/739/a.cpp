#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	vector<int> ans;
	for (int i = 1; ans.size() <= 1000; i++) {
		if (i % 3 == 0 || i % 10 == 3) continue;
		ans.push_back(i);
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << ans[n-1] << endl;
	}
	
	return 0;
}
