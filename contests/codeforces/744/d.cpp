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
		
		priority_queue<pair<int, int>> heap;
		for (int i = 0; i < n; i++) {
			heap.push({v[i], i+1});
		}
		vector<pair<int, int>> ans;
		
		while (true) {
			pair<int, int> a = heap.top();
			heap.pop();
			pair<int, int> b = heap.top();
			heap.pop();
			
			if (!a.first || !b.first) break;
			
			ans.push_back({a.second, b.second});
			a.first--;
			b.first--;
			
			heap.push(a);
			heap.push(b);
		}
		
		cout << ans.size() << endl;
		for (pair<int, int>& p : ans) {
			cout << p.first << " " << p.second << endl;
		}
	}
	return 0;
}
