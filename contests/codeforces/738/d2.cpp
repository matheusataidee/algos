#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
class DSU {
	vector<int> v;
	vector<int> r;
public:
	DSU(int n) {
		v = vector<int>(n+1);
		r = vector<int>(n+1);
		for (int i = 0; i <= n; i++) v[i] = i;
	}
	
	int find(int p) {
		return p == v[p] ? p : v[p] = find(v[p]);
	}
	
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b) {
			if (r[a] < r[b]) swap(r[a], r[b]);
			v[b] = a;
			if (r[a] == r[b]) r[a]++;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	DSU dsu1(n), dsu2(n);
	for (int i = 0; i < m1; i++) {
		int a, b;
		cin >> a >> b;
		dsu1.unite(a, b);
	}
	for (int i = 0; i < m2; i++) {
		int a, b;
		cin >> a >> b;
		dsu2.unite(a, b);
	}
	
	vector<pair<int, int> > ans;
	map<int, int> linker;
	
	int which = 0;
	linker[dsu2.find(1)] = 1;
	for (int i = 2; i <= n; i++) {
		DSU& dsu = !which ? dsu1 : dsu2;
		DSU& other = !which ? dsu2 : dsu1;
		if (dsu.find(i) == dsu.find(i-1)) {
			linker[other.find(i)] = i;
		} else {
			int c_a = other.find(i);
			if (!linker.count(c_a) || linker.size() > 1) {
				auto it = linker.begin();
				int c_b = it->first;
				if (c_b == c_a) c_b = (++it)->first;
				linker[c_a] = i;
				
				ans.push_back({linker[c_b], i});
				
				dsu.unite(linker[c_b], i);
				other.unite(c_a, c_b);
				
				linker.erase(c_a);
				linker.erase(c_b);
				
				linker[other.find(i)] = i;
			} else {
				linker.erase(c_a);
				
				linker[dsu.find(i)] = i;
				linker[dsu.find(i - 1)] = i - 1;
				which = 1 - which;
			}
		}
	}
	
	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}
