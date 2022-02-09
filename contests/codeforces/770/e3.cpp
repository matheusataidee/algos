#include <bits/stdc++.h>

using namespace std;

#define len(x) (int)x.size()

typedef long long ll;

const int MAXN = 4e5 + 100;

vector<pair<int, int>> g[MAXN];
string ans[MAXN];
int pos[MAXN];
int m;

void dfs(int cur) {
	if (pos[cur] == 0) {
		ans[cur] = string(len(g[cur]), 'L');
	}
	while (pos[cur] < len(g[cur])) {
		auto [to, where] = g[cur][pos[cur]];
		if (to == -1) {
			pos[cur]++;
			continue;
		}
		if (cur < m) {
			ans[cur][pos[cur]] = 'R';
		}
		g[cur][pos[cur]].first = g[to][where].first = -1;
		pos[cur]++;
		dfs(to);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> m;
	int slider = m;
	map<int, int> translate, counter;
	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			counter[x]++;
			if (!translate.count(x)) {
				translate[x] = slider++;
			}
			int who = translate[x];
			g[i].push_back({who, g[who].size()});
			g[who].push_back({i, (int)g[i].size() - 1});
		}
	}
	bool impossible = false;
	for (auto [num, freq] : counter) {
		if (freq % 2 == 1) impossible = true;
	}
	if (impossible) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (int i = 0; i < m; i++) {
			dfs(i);
			cout << ans[i] << endl;
		}
	}
	
	return 0;
}
