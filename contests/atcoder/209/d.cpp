#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<vector<int> > g(n, vector<int>());
	vector<int> color(n, -1);
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		from--;	to--;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	color[0] = 0;
	queue<int> myq;
	myq.push(0);
	while (!myq.empty()) {
		int p = myq.front(); myq.pop();
		for (int to : g[p]) {
			if (color[to] == -1) {
				color[to] = 1 - color[p];
				myq.push(to);
			}
		}
	}
	
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--;	b--;
		if (color[a] == color[b]) {
			cout << "Town" << endl;
		} else {
			cout << "Road" << endl;
		}
	}
	return 0;
}
