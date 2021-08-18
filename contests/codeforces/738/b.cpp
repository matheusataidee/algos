#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void run(string& s, int start, int inc, char last) {
	int n = s.size();
	for (int i = start; i >= 0 && i < n; i += inc) {
		if (s[i] == '?') {
			if (last == 'B') {
				s[i] = 'R';
			} else if (last == 'R') {
				s[i] = 'B';
			}
		}
		last = s[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		run(s, 0, +1, '?');
		run(s, n-1, -1, '?');
		run(s, 0, +1, 'B');
		cout << s << endl;
	}
	return 0;
}
