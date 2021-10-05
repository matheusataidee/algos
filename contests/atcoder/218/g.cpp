#include <bits/stdc++.h>

using namespace std;

#define MAXI 0
#define MINI 1

typedef long long ll;

class Median {
	multiset<int> high, low;

	void fix() {
		if (!low.empty()) {
			auto it = low.end(); --it;
			
			high.insert(*it);
			low.erase(it);
		}
		
		while (low.size() < high.size()) {
			auto it = high.begin();
			low.insert(*it);
			high.erase(it);
		}
	}

public:
	void insert(int x) {
		high.insert(x);
		fix();
	}
	
	void erase(int x) {
		auto it = low.end(); --it;
		if (x > *it) {
			high.erase(high.lower_bound(x));
		} else {
			low.erase(low.lower_bound(x));
		}
		fix();
	}
	
	int getMedian() {
		auto it = low.end(); --it;
		if (low.size() == high.size()) {
			return (*it + *high.begin()) / 2;
		}
		return *it;
	}
};

int n;
vector<vector<int>> g;
vector<int> dp[2];
vector<int> costs;
Median med;

void dfs(int p, int prev) {
	med.insert(costs[p]);
	int nnei = 0;
	for (int to : g[p]) {
		if (to == prev) continue;
		nnei++;
		dfs(to, p);
	}
	if (nnei == 0) dp[MAXI][p] = dp[MINI][p] = med.getMedian();
	med.erase(costs[p]);
}

int solve(int p, int who, int prev) {
	if (dp[who][p] != -1) return dp[who][p];
	
	int maxi = INT_MIN;
	int mini = INT_MAX;
	for (int to : g[p]) {
		if (to == prev) continue;
		maxi = max(maxi, solve(to, 1 - who, p));
		mini = min(mini, solve(to, 1 - who, p));
	}
	return dp[who][p] = (who == MAXI) ? maxi : mini;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	g.assign(n, vector<int>());
	costs.assign(n, 0);
	dp[0].assign(n, -1);
	dp[1].assign(n, -1);
	for (int& cost : costs) cin >> cost;
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		from--;	to--;
		
		g[from].push_back(to);
		g[to].push_back(from);
	}
	
	dfs(0, -1);
	cout << solve(0, MAXI, -1) << endl;
	
	return 0;
}
