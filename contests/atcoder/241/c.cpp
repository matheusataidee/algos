#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

const vector<int> dy{0, +1, +1, +1};
const vector<int> dx{+1, 0, +1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> grid(n);
	for (string& row : grid) cin >> row;
	bool found = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (i + 5 * dy[k] >= n) continue;
				if (j + 5 * dx[k] >= n || j + 5 * dx[k] < 0) continue;
				int counter = 0;
				for (int step = 0; step < 6; step++) {
					int y = i + step * dy[k];
					int x = j + step * dx[k];
					if (grid[y][x] == '#') counter++;
				}
				if (counter >= 4) found = true;
			}
		}
	}
	cout << vector<string>{"No", "Yes"}[found] << endl;
	return 0;
}
