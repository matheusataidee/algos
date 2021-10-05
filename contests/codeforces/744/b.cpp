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
		
		vector<int> v(n);
		for (int& val : v) cin >> val;
		
		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++) {
			int id = i;
			for (int j = i; j < n; j++) {
				if (v[j] < v[id]) {
					id = j;
				}
			}
			if (i != id) {
				ans.push_back({i+1, id+1});
				
				int mini = v[id];
				for (int j = id; j > i; j--) {
					v[j] = v[j-1];
				}
				v[i] = mini;
			}
		}
		
		cout << ans.size() << endl;
		for (pair<int, int>& p : ans) {
			cout << p.first << " " << p.second << " " << p.second - p.first << endl;
		}
		
	}
	return 0;
}
