#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Dsu {
	vector<int> r;
	vector<int> p;
	
	Dsu(int n) {
		r.assign(n, 0);
		p.assign(n, 0);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	
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
};

struct Edge{
	int a, b;
	ll c;
};

bool operator<(const Edge& a, const Edge& b) {
	return a.c > b.c;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	Dsu dsu(n);
	vector<Edge> edges(m);
	priority_queue<Edge> heap;
	
	ll ans = 0;
	int componentsN = n;
	for (Edge& edge : edges) {
		cin >> edge.a >> edge.b >> edge.c;
		
		edge.a--; edge.b--;
		if (edge.c > 0) {
			ans += edge.c;
			heap.push(edge);
		} else {
			if (dsu.findSet(edge.a) != dsu.findSet(edge.b)) componentsN--;
			dsu.uniteSets(edge.a, edge.b);
		}
	}
	
	while (componentsN > 1) {
		Edge edge = heap.top();
		heap.pop();
		
		if (dsu.findSet(edge.a) != dsu.findSet(edge.b)) {
			ans -= edge.c;
			dsu.uniteSets(edge.a, edge.b);
			componentsN--;
		}
	}
	cout << ans << endl;
	return 0;
}
