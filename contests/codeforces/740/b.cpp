#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int a, int b, int na, int nb, set<int>& ans) {
	for (int i = 0; i <= a; i++) {
		int breaksA = i;
		int servA = a - i;
		int servB = nb - i;
		int breaksB = b - servB;
		if (servA > na) continue;
		if (servB < 0 || servB > b) continue;
		if (breaksB < 0 || breaksB > b) continue;
		ans.insert(breaksA + breaksB);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int total = a + b;
		set<int> ans;
		if (total % 2 == 0) {
			solve(a, b, total / 2, total / 2, ans);
			solve(b, a, total / 2, total / 2, ans);
		} else {
			solve(a, b, total / 2, (total+1)/2, ans);
			solve(b, a, total / 2, (total+1)/2, ans);
			solve(a, b, (total+1) / 2, total/2, ans);
			solve(b, a, (total+1) / 2, total/2, ans);
		}
		cout << ans.size() << endl;
		for (auto& it : ans) {
			cout << it << " ";
		}
		cout << endl;
	}
	
	return 0;
}
