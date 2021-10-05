#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> cilinders(m);
	vector<int> avail(n+1, -1);
	queue<pair<int, int>> myq;
	int qnt = 0;
	for (int i = 0; i < m; i++) {
		int sz;
		cin >> sz;
		cilinders[i] = vector<int>(sz);
		for (int& ball : cilinders[i]) cin >> ball;
		int last = cilinders[i].back();
		if (avail[last] != -1) {
			myq.push({avail[last], i});
		} else {
			avail[last] = i;
		}
	}
	while (!myq.empty()) {
		qnt++;
		int a = myq.front().first, b = myq.front().second;
		myq.pop();
		cilinders[a].pop_back();
		cilinders[b].pop_back();
		
		
		if (cilinders[a].size() > 0) {
			int last = cilinders[a].back();
			if (avail[last] != -1) {
				myq.push({avail[last], a});
			} else {
				avail[last] = a;
			}
		}
		if (cilinders[b].size() > 0) {
			int last = cilinders[b].back();
			if (avail[last] != -1) {
				myq.push({avail[last], b});
			} else {
				avail[last] = b;
			}
		}
	}
	if (qnt == n) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
