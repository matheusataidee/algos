#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

void update(string& ans, int qnt) {
	for (int i = 0; i < qnt / 2; i++) {
		ans += 'A';
	}
	if (qnt % 2 == 1) {
		ans += 'B';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans = "";
	int qnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'C') {
			update(ans, qnt);
			ans += 'C';
			qnt = 0;
		} else if (s[i] == 'A') {
			qnt += 2;
		} else {
			qnt += 1;
		}
	}
	update(ans, qnt);
	cout << ans << endl;
	return 0;
}
