#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int last = 1;
vector<int> l, r, prv;
vector<vector<int>> g;

void solve(int cur) {
	l[cur] = r[cur] = last;
	int qnt = 1;
	for (int to : g[cur]) {
		if (to == prv[cur]) continue;
		
		qnt++;
		prv[to] = cur;
		solve(to);
		r[cur] = r[to];
	}
	if (qnt == 1) last++;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	l = vector<int>(n, -1);
	r = vector<int>(n, -1);
	prv = vector<int>(n, -1);
	g = vector<vector<int>>(n, vector<int>());
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--;	b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	solve(0);
	for (int i = 0; i < n; i++) {
		cout << l[i] << " " << r[i] << endl;
	}
	return 0;
}
