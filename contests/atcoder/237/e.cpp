#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> g;
vector<vector<ll>> cost;
vector<ll> h;
vector<ll> d;

void dijkstra() {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> heap;
	//d[0] = 0;
	
	heap.push({0, 0});
	while (!heap.empty()) {
		int cur = heap.top().second;
		ll c = heap.top().first;
		heap.pop();
		if (d[cur] != -1) continue;
		d[cur] = c;
		for (int i = 0; i < (int)g[cur].size(); i++) {
			int to = g[cur][i];
			if (d[to] == -1) {
				heap.push({d[cur] + cost[cur][i], to});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	g.assign(n, vector<ll>());
	cost.assign(n, vector<ll>());
	h.assign(n, 0);
	d.assign(n, -1);
	
	for (auto& hei : h) cin >> hei;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		
		g[a].push_back(b);
		g[b].push_back(a);
		ll delta = h[b] - h[a];
		if (delta > 0) {
			cost[a].push_back(delta);
			cost[b].push_back(0);
		} else {
			cost[a].push_back(0);
			cost[b].push_back(-delta);
		}
	}
	dijkstra();
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] != -1) {
			ans = max(ans, h[0] - h[i] - d[i]);
		}
	}
	cout << ans << endl;
	
	return 0;
}
