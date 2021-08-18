#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Dsu {
	vector<int> r;
	vector<int> p;
public:
	Dsu(int n) {
		r = vector<int>(n+1);
		p = vector<int>(n+1);
		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}
	}
	
	void uniteSets(int a, int b) {
		a = findSet(a);
		b = findSet(b);
		if (a != b) {
			if (r[a] < r[b]) swap(a, b);
			p[b] = a;
			if (r[a] == r[b]) r[a]++;
		}
	}
	
	int findSet(int v) {
		return v == p[v] ? v : p[v] = findSet(p[v]);
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	Dsu g1(n);
	Dsu g2(n);
	for (int i = 0; i < m1; i++) {
		int a, b;
		cin >> a >> b;
		g1.uniteSets(a, b);
	}
	for (int i = 0; i < m2; i++) {
		int a, b;
		cin >> a >> b;
		g2.uniteSets(a, b);
	}
	vector<pair<int, int> > ans;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (g1.findSet(i) != g1.findSet(j) &&
				g2.findSet(i) != g2.findSet(j)) {
				ans.push_back({i, j});
				g1.uniteSets(i, j);
				g2.uniteSets(i, j);
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	return 0;
}
