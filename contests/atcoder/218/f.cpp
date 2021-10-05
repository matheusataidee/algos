#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> g;

int getDist(pair<int, int> forbidden, set<pair<int, int>>& specials) {
	vector<int> d(n, -1);
	vector<int> prev(n, -1);
	
	d[0] = 0;
	queue<int> myq;
	myq.push(0);
	while (!myq.empty()) {
		int p = myq.front(); myq.pop();
		
		for (int to : g[p]) {
			if (p == forbidden.first && to == forbidden.second) continue;
			if (d[to] == -1) {
				d[to] = d[p] + 1;
				prev[to] = p;
				myq.push(to);
			}
		}
	}
	
	int cur = n - 1;
	while (prev[cur] != -1) {
		specials.insert({prev[cur], cur});
		cur = prev[cur];
	}
	return d[n-1];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	g.assign(n, vector<int>());
	
	vector<pair<int, int>> edges(m);
	set<pair<int, int>> specials;
	for (pair<int, int>& edge : edges) {
		cin >> edge.first >> edge.second;
		int from = --edge.first, to = --edge.second;
		
		g[from].push_back(to);
	}
	
	int dist = getDist({-1, -1}, specials);
	
	set<pair<int, int>> ignore;
	for (int i = 0; i < m; i++) {
		if (specials.count(edges[i])) {
			cout << getDist(edges[i], ignore) << endl;
		} else {
			cout << dist << endl;
		}
	}
	return 0;
}
