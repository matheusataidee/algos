#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

class Flow {
	int n;
	vector<vector<int>> g;
	map<pair<int, int>, int> cap;
	vector<int> prev;
	
	bool bfs(int s, int t) {
		prev.assign(n, -1);
		queue<int> myq;
		myq.push(s);
		while (!myq.empty() && prev[t] == -1) {
			int cur = myq.front();
			myq.pop();
			for (int to : g[cur]) {
				if (prev[to] == -1 && cap[{cur, to}] > 0) {
					prev[to] = cur;
					myq.push(to);
				}
			}
		}
		return prev[t] != -1;
	}
	
public:	

	Flow(int n_) : n(n_), g(n_) { }

	void addEdge(int from, int to, int c) {
		g[from].push_back(to);
		g[to].push_back(from);
		cap[{from, to}] = c;
		cap[{to, from}] = 0;
	}
	
	int maxFlow(int s, int t) {
		int flow = 0;
		while (bfs(s, t)) {
			for (int from : g[t]) {
				if (prev[from] == -1 || !cap[{from, t}]) continue;
				int bot = cap[{from, t}];
				int cur = from;
				while (cur != s) {
					bot = min(bot, cap[{prev[cur], cur}]);
					cur = prev[cur];
				}
				if (!bot) continue;
				cap[{from, t}] -= bot;
				cap[{t, from}] += bot;
				cur = from;
				while (cur != s) {
					cap[{prev[cur], cur}] -= bot;
					cap[{cur, prev[cur]}] += bot;
					cur = prev[cur];
				}
				flow += bot;
			}
		}
		return flow;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	
	vector<vector<bool>> happened(n+1, vector<bool>(n+1));
	vector<int> initial_score(n+1);
	for (int i = 0; i < m; i++) {
		int winner, loser;
		cin >> winner >> loser;
		initial_score[winner]++;
		happened[winner][loser] = happened[loser][winner] = true;
	}
	
	for (int cur = 1; cur <= n; cur++) {
		vector<int> score = initial_score;
		
		int s = 0, t = n + 1;
		Flow flow(t+1);
		
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (happened[i][j]) continue;
				if (i == cur) {
					score[i]++;
				} else if (j == cur) {
					score[j]++;
				} else {
					score[i]++;
					flow.addEdge(j, i, 1);
				}
			}
		}
		int lim = score[cur] - 1;
		if (lim < 0) continue;
		int need = 0;
		for (int i = 1; i <= n; i++) {
			if (i == cur) continue;
			int diff = score[i] - lim;
			if (diff > 0) {
				flow.addEdge(i, t, diff);
				need += diff;
			} else if (diff < 0) {
				flow.addEdge(s, i, -diff);
			}
		}
		if (flow.maxFlow(s, t) == need) {
			cout << cur << " ";
		}
		
	}
	cout << endl;
	return 0;
}
