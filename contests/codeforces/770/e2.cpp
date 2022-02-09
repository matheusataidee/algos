#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int m;
vector<vector<int>> vs;
vector<vector<int>> g;
vector<vector<char>> ans;
vector<int> available;
vector<bool> used;
unordered_map<int, int> translate;

void eulerTour(int cur) {
	if (!available[cur]) return;
	available[cur]--;
	if (cur < m) {
		ans[cur][available[cur]] = 'L';
	} else {
		int base = g[cur][available[cur]];
		ans[base][--available[base]] = 'R';
	}
	eulerTour(g[cur][available[cur]]);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> m;
	vs.assign(m, vector<int>());
	ans.assign(m, vector<char>());
	map<int, int> freq;
	for (auto& v : vs) {
		int n;
		cin >> n;
		v.assign(n, 0);
		for (int& val : v) {
			cin >> val;
			freq[val]++;
		}
	}
	int counter = m;
	bool impossible = false;
	for (auto& it : freq) {
		if (it.second % 2 == 1) impossible = true;
		translate[it.first] = counter++;
	}
	if (impossible) {
		cout << "NO" << endl;
	} else {
		g.assign(counter, vector<int>());
		available.assign(counter, 0);
		used.assign(m, false);
		for (int i = 0; i < m; i++) {
			ans[i].assign(vs[i].size(), ' ');
			for (int j = 0; j < (int)vs[i].size(); j++) {
				int neigh = translate[vs[i][j]];
				g[i].push_back(neigh);
				g[neigh].push_back(i);
			}
		}
		for (int i = 0; i < counter; i++) {
			available[i] = g[i].size();
		}
		for (int i = 0; i < m; i++) {
			if (!used[i]) {
				eulerTour(i);
			}
		}
		//cout << "
		
	}
	
	
	
	return 0;
}
