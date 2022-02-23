#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

void invert(int p, vector<int>& v, vector<int>& szs, vector<pair<int, int>>& ops) {
	int added = 0;
	for (int i = (int)v.size() - 1; i >= p; i--) {
		ops.push_back({p + added, v[i]});
		added++;
	}
	szs.push_back(2 * added);
	reverse(v.begin() + p, v.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n), goal;
		map<int, int> freq;
		int odd = 0;	
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			freq[v[i]]++;
			if (freq[v[i]] % 2 == 0) {
				goal.push_back(v[i]);
				odd--;
			} else {
				odd++;
			}
		}
		if (odd) {
			cout << "-1" << endl;
			continue;
		}
		sort(all(goal));
		for (int i = 0; i < n / 2; i++) {
			goal.push_back(goal[i]);
		}
		
		vector<pair<int, int>> ops;
		vector<int> szs;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (v[j] == goal[i]) {
					invert(j, v, szs, ops);
					invert(i, v, szs, ops);
					break;
				}
			}
		}
		szs.push_back(n);
		
		reverse(all(szs));
		cout << ops.size() << endl;
		for (pair<int, int> op : ops) {
			cout << op.first << " " << op.second << endl;
		}
		cout << szs.size() << endl;
		for (int sz : szs) {
			cout << sz << " ";
		}
		cout << endl;
		
	}
	return 0;
}
