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
