#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

const pair<int, int> unavailable;

pair<int, int> getCandidate(int y, int x, set<pair<int, int>>& xy,
										  set<pair<int, int>>& yx, int k) {
	if (k == 0) { // Down
		auto it = xy.lower_bound({x, y});
		if (it == xy.end() || it->first != x) {
			return unavailable;
		}
		return {it->second - 1, it->first};
	} else if (k == 1) { // UP
		auto it = xy.lower_bound({x, y});
		if (it == xy.begin()) return unavailable;
		it--;
		if (it->first != x) return unavailable;
		
		return {it->second + 1, it->first};
	} else if (k == 2) { // RIGHT
		auto it = yx.lower_bound({y, x});
		if (it == yx.end() || it->first != y) {
			return unavailable;
		}
		return {it->first, it->second - 1};
	} else { // LEFT
		auto it = yx.lower_bound({y, x});
		if (it == yx.begin()) return unavailable;
		it--;
		if (it->first != y) return unavailable;
		
		return {it->first, it->second + 1};
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w, n;
	cin >> h >> w >> n;
	
	set<pair<int, int>> xy, yx;
	map<pair<int, int>, int> dist;
	pair<int, int> initial, target;
	cin >> initial.first >> initial.second;
	cin >> target.first >> target.second;
	
	for (int i = 0; i < n; i++) {
		int y, x;
		cin >> y >> x;
		xy.insert({x, y});
		yx.insert({y, x});
	}
	dist[{initial.first, initial.second}] = 0;
	queue<pair<int, int>> myq;
	myq.push(initial);
	while (!myq.empty()) {
		int y = myq.front().first;
		int x = myq.front().second;
		int d = dist[myq.front()];
		myq.pop();
		
		for (int i = 0; i < 4; i++) {
			pair<int, int> nxt = getCandidate(y, x, xy, yx, i);
			if (nxt != unavailable && !dist.count(nxt)) {
				dist[nxt] = d + 1;
				myq.push(nxt);
			}
		}
	}
	if (dist.count(target)) {
		cout << dist[target] << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}
