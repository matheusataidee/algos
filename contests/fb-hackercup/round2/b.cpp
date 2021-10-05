#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> g;
vector<int> dist;
vector<int> pred;
vector<int> p;
vector<int> r;

int findSet (int v) {
	return v == p[v] ? v : p[v] = findSet(p[v]);
}

void uniteSets (int a, int b) {
	a = findSet(a);
	b = findSet(b);
	if (a != b) {
		if (r[a] < r[b]) {
			swap(a, b);
		}
		p[b] = a; 
		if (r[a] == r[b]) {
			r[a]++;
		} 
	}
}

void bfs() {
	queue<int> myq;
	
	dist[0] = 0;
	myq.push(0);
	while (!myq.empty()) {
		int v = myq.front();
		myq.pop();
		
		for (int to : g[v]) {
			if (dist[to] != -1) continue;
			dist[to] = dist[v] + 1;
			pred[to] = v;
			myq.push(to);
		}
	}
}

void solve(int a, int b) {
	if (findSet(a) == findSet(b)) return;
	
	int far = (dist[a] > dist[b]) ? a : b;
	int close = a + b - far;
	
	while (dist[far] > dist[close]) {
		uniteSets(far, pred[far]);
		far = pred[far];
		
		if (findSet(far) == findSet(close)) return;
	}
	
	while (findSet(far) != findSet(close)) {
		uniteSets(far, close);
		
		far = pred[far];
		uniteSets(far, close);
		
		close = pred[close];
	}
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		g = vector<vector<int>>(n, vector<int>());
		dist = vector<int>(n, -1);
		pred = vector<int>(n, -1);
		p = vector<int>(n, 0);
		r = vector<int>(n, 0);
		for (int i = 0; i < n - 1; i++) {
			int from, to;
			cin >> from >> to;
			from--;	to--;
			g[from].push_back(to);
			g[to].push_back(from);
		}
		bfs();
		
		vector<vector<int>> groups(n);
		for (int i = 0; i < n; i++) {
			int group;
			cin >> group;
			group--;
			groups[group].push_back(i);
			
			p[i] = i;
		}
		
		
		
		for (int group = 0; group < n; group++) {
			int sz = groups[group].size();
			for (int i = 1; i < sz; i++) {
				solve(groups[group][i-1], groups[group][i]);
			}
		}
		
		set<int> diffs;
		for (int i = 0; i < n; i++) {
			diffs.insert(findSet(i));
		}
		int ans = (int)diffs.size() - 1;
		
		cout << "Case #" << t << ": " << ans << endl;
		
		g.clear();
		dist.clear();
		pred.clear();
		p.clear();
		r.clear();
	}
	return 0;
}
