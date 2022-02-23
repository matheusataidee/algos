#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> szs;
vector<pair<int, int>> ans;
int q = 0;

bool allEven(map<int, int>& freq) {
	for (auto it : freq) {
		if (it.second % 2 == 1) return false;
	}
	return true;
}

void invert(int p, vector<int>& v) {
	for (int i = 0; i <= p; i++) {
		ans.push_back({1 + p + i + 2 * q, v[i]});
	}
	q += p + 1;
	szs.push_back(2 * (p + 1));
	
	int l = 0, r = p;
	while (l < r) {
		swap(v[l++], v[r--]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> freq;
		vector<int> goal;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			freq[v[i]]++;
			if (freq[v[i]] % 2 == 0) {
				goal.push_back(v[i]);
			}
		}
		if (!allEven(freq)) {
			cout << "-1" << endl;
			continue;
		}
		
		sort(begin(goal), end(goal));
		for (int i = 0; i < n / 2; i++) {
			goal.push_back(goal[i]);
		}
		
		szs.clear();
		ans.clear();
		q = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j >= 0; j--) {
				if (v[j] == goal[i]) {
					invert(j, v);
					invert(i, v);
					break;
				}
			}
		}
		
		
		szs.push_back(n);
		cout << ans.size() << endl;
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
		cout << szs.size() << endl;
		for (int i = 0; i < (int)szs.size(); i++) {
			cout << szs[i] << " ";
		}
		cout << endl;
		
	}
	return 0;
}
