#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
	int y;
	int x;
	int c;
	Point(int y_, int x_, int c_) : y(y_), x(x_), c(c_) { }
};

const vector<int> dy{-1, +1, -1, +1, -1, 0, +1, 0};
const vector<int> dx{-1, +1, +1, -1, 0, -1, 0, +1};

const int maxn = 1010;

int g[maxn][maxn];
bool ok[maxn][maxn];
queue<Point> myq;

void solve(int y, int x) {
	int last = -1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (ok[y+i][x+j]) continue;
			if (last != -1 && g[y+i][x+j] != last) return;
			last = g[y+i][x+j];
		}
	}
	if (last != -1) {
		ok[y][x] = ok[y+1][x] = ok[y][x+1] = ok[y+1][x+1] = true;
		myq.push(Point(y, x, last));
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	scanf("%d %d", &n, &m);
	memset(ok, false, sizeof(ok));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &g[i][j]);
		}
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			solve(i, j);
		}
	}
	vector<Point> ans;
	while (!myq.empty()) {
		Point cur = myq.front();
		myq.pop();
		
		ans.push_back(cur);
		
		for (int i = 0; i < (int)dy.size(); i++) {
			int y = cur.y + dy[i];
			int x = cur.x + dx[i];
			if (y >= n - 1 || y < 0) continue;
			if (x >= m - 1 || x < 0) continue;
			solve(y, x);
		}
	}
	bool all_ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!ok[i][j]) all_ok = false;
		}
	}
	if (all_ok) {
		printf("%d\n", (int)ans.size());
		for (int i = (int)ans.size() - 1; i >= 0; i--) {
			printf("%d %d %d\n", ans[i].y + 1, ans[i].x + 1, ans[i].c);
		}
	} else {
		printf("-1\n");
	}
	return 0;
}
