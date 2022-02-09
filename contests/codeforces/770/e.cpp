#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int m, counter = 1;
vector<vector<int>> vs;
vector<map<int, int>> freq;
unordered_map<int, int> translate_group;
unordered_map<int, int> translate_num;
vector<vector<int>> g;
map<pair<int, int>, int> cap;

bool maxflow(int s, int t) {
	int obj = 0;
	for (int from : g[t]) {
		obj += cap[{from, t}];
	}
	int flow = 0;
	while (true) {
		unordered_map<int, int> prev;
		vector<int> hitters;
		prev[s] = -1;
		queue<int> myq;
		myq.push(s);
		while (!myq.empty() && !prev.count(t)) {
			int cur = myq.front(); myq.pop();
			for (int to : g[cur]) {
				if (cap[{cur, to}] > 0 && !prev.count(to)) {
					prev[to] = cur;
					myq.push(to);
				}
			}
		}
		if (!prev.count(t)) break;
		for (int from : g[t]) {
			if (prev.count(from) && cap[{from, t}]) {
				int bot = cap[{from, t}];
				int v = from;
				while (v != s) {
					bot = min(bot, cap[{prev[v], v}]);
					v = prev[v];
				}
				if (!bot) continue;
				cap[{from, t}] -= bot;
				cap[{t, from}] += bot;
				v = from;
				while (v != s) {
					cap[{prev[v], v}] -= bot;
					cap[{v, prev[v]}] += bot;
					v = prev[v];
				}
				flow += bot;
			}
		}
	}
	return flow == obj;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> m;
	vs.assign(m, vector<int>());
	freq.assign(m, map<int, int>());
	for (int i = 0; i < m; i++) {
		translate_group[i] = counter++;
		int n;
		cin >> n;
		vs[i].assign(n, 0);
		for (int& val : vs[i]) {
			cin >> val;
			freq[i][val]++;
			if (!translate_num.count(val)) {
				translate_num[val] = counter++;
			}
		}
	}
	g.assign(counter + 1, vector<int>());
	map<int, int> qnt;
	for (int i = 0; i < m; i++) {
		int odd = 0;
		for (auto& it : freq[i]) {
			if (it.second % 2 == 1) {
				g[translate_num[it.first]].push_back(translate_group[i]);
				g[translate_group[i]].push_back(translate_num[it.first]);
				cap[{translate_num[it.first], translate_group[i]}] = 1;
				cap[{translate_group[i], translate_num[it.first]}] = 0;
				
				qnt[translate_num[it.first]]++;
				odd++;
			}
		}
		if (odd) {
			g[translate_group[i]].push_back(counter);
			g[counter].push_back(translate_group[i]);
			cap[{translate_group[i], counter}] = odd / 2;
			cap[{counter, translate_group[i]}] = 0;
		}
	}
	for (auto& it : qnt) {
		g[0].push_back(it.first);
		g[it.first].push_back(0);
		cap[{0, it.first}] = it.second / 2;
		cap[{it.first, 0}] = 0;
	}
	
	if (maxflow(0, counter)) {
		cout << "YES" << endl;
		for (int i = 0; i < m; i++) {
			unordered_map<int, int> l;
			unordered_map<int, int> r;
			for (auto it : freq[i]) {
				l[it.first] = it.second / 2;
				r[it.first] = it.second / 2;
				if (it.second % 2 == 1) {
					if (cap[{translate_num[it.first], translate_group[i]}]) {
						l[it.first]++;
					} else {
						r[it.first]++;
					}
				}
			}
			for (int& val : vs[i]) {
				if (l[val] > 0) {
					cout << "L";
					l[val]--;
				} else {
					cout << "R";
					r[val]--;
				}
			}
			cout << endl;
		}
	} else {
		cout << "NO" << endl;
	}
	
	
	return 0;
}
