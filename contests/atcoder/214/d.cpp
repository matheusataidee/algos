#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class DSU {
	vector<int> p;
	vector<int> r;
	vector<ll> sz;
public:
	DSU(int n) {
		p = vector<int>(n);
		r = vector<int>(n);
		sz = vector<ll>(n, 1);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}
	
	int findSet(int v) {
		return v == p[v] ? v : p[v] = findSet(p[v]);
	}
	
	ll getSz(int v) {
		v = findSet(v);
		return sz[v];
	}

	void uniteSets (int a, int b) {
		a = findSet(a);
		b = findSet(b);
		if (a != b) {
			if (r[a] < r[b]) {
				swap(a, b);
			}
			p[b] = a; 
			sz[a] += sz[b];
			if (r[a] == r[b]) {
				r[a]++;
			} 
		}
	}
};

struct Edge {
	ll a, b, w;
	bool operator<(Edge& other) {
		return w < other.w;
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	DSU dsu(n);
	vector<Edge> edges(n-1);
	for (Edge& e : edges) {
		cin >> e.a >> e.b >> e.w;
		e.a--;	e.b--;
	}
	sort(begin(edges), end(edges));
	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += dsu.getSz(edges[i].a) * dsu.getSz(edges[i].b) * edges[i].w;
		dsu.uniteSets(edges[i].a, edges[i].b);
	}
	cout << ans << endl;
	
	return 0;
}
