#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

const int maxx = 2020;

int s, t, n, m;
map<pair<int, int>, int> match_to_vertex;
unordered_map<int, int> player_to_vertex;
vector<vector<int>> wins;

int maxFlow(vector<vector<int>>& g, map<pair<int, int>, int>& cap) {
	int flow = 0;
	while (true) {
		queue<int> myq;
		myq.push(s);
		vector<int> prev(t + 1, -1);
		while (!myq.empty()) {
			int cur = myq.front();
			myq.pop();
			for (int to : g[cur]) {
				if (cap[{cur, to}] && prev[to] == -1) {
					prev[to] = cur;
					myq.push(to);
				}
			}
			if (prev[t] != -1) break;
		}
		if (prev[t] == -1) break;
		for (int from : g[t]) {
			if (prev[from] == -1 || !cap[{from, t}]) continue;
			int bot = cap[{from, t}];
			int cur = from;
			while (cur != s) {
				bot = min(bot, cap[{prev[cur], cur}]);
				cur = prev[cur];
			}
			cur = from;
			flow += bot;
			cap[{from, t}] -= bot;
			cap[{t, from}] += bot;
			while (cur != s) {
				cap[{prev[cur], cur}] -= bot;
				cap[{cur, prev[cur]}] += bot;
				cur = prev[cur];
			}	
		}
	}
	return flow;
}

bool canBeChampion(int player, vector<vector<int>>& g, map<pair<int, int>, int> cap) {
	int player_points = 0;
	for (int i = 1; i <= n; i++) {
		if (i == player) continue;
		if (wins[player][i]) {
			player_points++;
			int match = match_to_vertex[{player, i}];
			cap[{s, match}] = 0;
		}
	}
	if (!player_points) return false;
	for (int i = 1; i <= n; i++) {
		if (i == player) continue;
		
		int a = player_to_vertex[i];
		cap[{a, t}] = player_points - 1;
		cap[{t, a}] = 0;
	}
	return maxFlow(g, cap) == ((n * (n - 1)) / 2) - player_points;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	
	wins = vector<vector<int>>(n+1, vector<int>(n+1, -1));
	for (int i = 0; i < m; i++) {
		int winner, loser;
		cin >> winner >> loser;
		wins[winner][loser] = 1;
		wins[loser][winner] = 0;
	}
	
	s = 0;
	int counter = 1;
	vector<vector<int>> g(maxx);
	map<pair<int, int>, int> cap;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			match_to_vertex[{i, j}] = counter;
			match_to_vertex[{j, i}] = counter++;
			if (!player_to_vertex.count(i)) player_to_vertex[i] = counter++;
			if (!player_to_vertex.count(j)) player_to_vertex[j] = counter++;
			
			int match = match_to_vertex[{i, j}];
			int a = player_to_vertex[i];
			int b = player_to_vertex[j];
			
			g[match].push_back(s);
			g[match].push_back(a);
			g[match].push_back(b);
			g[s].push_back(match);
			g[a].push_back(match);
			g[b].push_back(match);
			
			cap[{s, match}] = 1;
			cap[{match, s}] = 0;
			if (wins[i][j] == -1) {
				cap[{match, a}] = 1;
				cap[{a, match}] = 0;
				cap[{match, b}] = 1;
				cap[{b, match}] = 0;
			} else if (wins[i][j] == 1) {
				cap[{match, a}] = 1;
				cap[{a, match}] = 0;
			} else {
				cap[{match, b}] = 1;
				cap[{b, match}] = 0;
			}
		}
	}
	t = counter;
	for (int i = 1; i <= n; i++) {
		int player = player_to_vertex[i];
		g[player].push_back(t);
		g[t].push_back(player);
	}
	
	for (int i = 1; i <= n; i++) {
		if (canBeChampion(i, g, cap)) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}
